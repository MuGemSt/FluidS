#include "glwidget.h"
#include<QVector3D>
#include<QDebug>
#include<QPoint>
#include<qmath.h>
#include"solver.h"

GLWidget::GLWidget(QWidget *parent) :QOpenGLWidget(parent)
{
	InitVariable();
}


void GLWidget::initializeGL()
{
	if (!allocate_data()) exit(1);
	clear_data();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 0.0); 
}

void GLWidget::paintGL()
{

	glClear(GL_COLOR_BUFFER_BIT);
	display_func();

}

void GLWidget::InitVariable()
{
	win_x = 512;
	win_y = 512;

	N = 126;
	dt = 0.1f;
	diff = 0.0f;
	visc = 0.0f;
	force = 5.0f;
	source = 100.0f;

	perm = true;
	dvel = false;
	DenColor = 0;
	VelColor = 1;
}

void GLWidget::display_func(void)
{
	if (perm){
		get_from_UI(dens_prev, u_prev, v_prev);

		solver s;
		s.vel_step(N, u, v, u_prev, v_prev, visc, dt);
		s.dens_step(N, dens, dens_prev, u, v, diff, dt);
	}

	dvel ? draw_velocity() : draw_density();
}


int GLWidget::allocate_data(void)
{
	int size = (N + 2)*(N + 2);

	u = (float *)malloc(size*sizeof(float));
	v = (float *)malloc(size*sizeof(float));
	u_prev = (float *)malloc(size*sizeof(float));
	v_prev = (float *)malloc(size*sizeof(float));
	dens = (float *)malloc(size*sizeof(float));
	dens_prev = (float *)malloc(size*sizeof(float));

	if (!u || !v || !u_prev || !v_prev || !dens || !dens_prev) {
		fprintf(stderr, "cannot allocate data\n");
		return (0);
	}

	return (1);
}

void GLWidget::free_data(void)
{
	if (u) free(u);
	if (v) free(v);
	if (u_prev) free(u_prev);
	if (v_prev) free(v_prev);
	if (dens) free(dens);
	if (dens_prev) free(dens_prev);
}


void GLWidget::clear_data(void)
{
	int i, size = (N + 2)*(N + 2);

	for (i = 0; i < size; i++) {
		u[i] = v[i] = u_prev[i] = v_prev[i] = dens[i] = dens_prev[i] = 0.0f;
	}
}


void GLWidget::choose_color(int color, float nit)
{
	switch (color) {
	case 0: glColor3f(nit, nit, nit); break;  //white
	case 1: glColor3f(nit, 0.0, 0.0); break;  //red
	case 2: glColor3f(0.0, nit, 0.0); break;  //green
	case 3: glColor3f(0.0, 0.0, nit); break;  //blue
	case 4: glColor3f(nit, nit, 0.0); break;  //yellow
	case 5: glColor3f(nit, 0.0, nit); break;  //purple
	case 6: glColor3f(0.0, nit, nit); break;  //skyblue
	default:;
	};
}

void GLWidget::draw_velocity(void)
{
	int i, j;
	float x, y, h;

	h = 1.0f / N;

	choose_color(VelColor, 1.0);

	glLineWidth(1.0f);

	glBegin(GL_LINES);

	for (i = 1; i <= N; i++) {
		x = (i - 0.5f)*h;
		for (j = 1; j <= N; j++) {
			y = (j - 0.5f)*h;

			glVertex2f(x, y);
			glVertex2f(x + u[IX(i, j)], y + v[IX(i, j)]);
		}
	}

	glEnd();
}

void GLWidget::draw_density(void)
{
	int i, j;
	float x, y, h, d00, d01, d10, d11;

	h = 1.0f / N;

	glBegin(GL_QUADS);

	for (i = 0; i <= N; i++) {
		x = (i - 0.5f)*h;
		for (j = 0; j <= N; j++) {
			y = (j - 0.5f)*h;

			d00 = dens[IX(i, j)];
			d01 = dens[IX(i, j + 1)];
			d10 = dens[IX(i + 1, j)];
			d11 = dens[IX(i + 1, j + 1)];

			choose_color(DenColor, d00); glVertex2f(x, y);
			choose_color(DenColor, d10); glVertex2f(x + h, y);
			choose_color(DenColor, d11); glVertex2f(x + h, y + h);
			choose_color(DenColor, d01); glVertex2f(x, y + h);

		}
	}

	glEnd();
}


void GLWidget::get_from_UI(float * d, float * u, float * v)
{
	int i, j, size = (N + 2)*(N + 2);

	for (i = 0; i < size; i++) {
		u[i] = v[i] = d[i] = 0.0f;
	}

	if (!mouse_down[0] && !mouse_down[2]) return;

	i = (int)((mx / (float)win_x)*N + 1);
	j = (int)(((win_y - my) / (float)win_y)*N + 1);

	if (i < 1 || i > N || j < 1 || j > N) return;

	if (mouse_down[0]) {
		u[IX(i, j)] = force * (mx - omx);
		v[IX(i, j)] = force * (omy - my);
	}

	if (mouse_down[2]) d[IX(i, j)] = source;

	omx = mx;
	omy = my;

	return;
}

void GLWidget::mousePressEvent(QMouseEvent *e)
{
	QPoint st(e->pos());
	mouse_func(0, e->button(), st.rx(), st.ry());
}

void GLWidget::mouseReleaseEvent(QMouseEvent *e)
{
	mouse_down[0] = mouse_down[2] = false;
}

void GLWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint ed(e->pos());
	motion_func(ed.rx(), ed.ry());
}

void GLWidget::mouse_func(int button, int state, int x, int y)
{
	omx = mx = x;
	omy = my = y;

	switch (state) {
	case Qt::LeftButton:
		mouse_down[button] = true;
		mouse_down[2 - button] = false;
		break;
	case Qt::RightButton:
		mouse_down[button] = false;
		mouse_down[2 - button] = true;
		break;
	default:;
	}

}

void GLWidget::motion_func(int x, int y)
{
	mx = x;
	my = y;
}

void GLWidget::Update(void)
{
	update();
}

void GLWidget::denColorId(int id)
{
	DenColor = id;
	if (!perm) Update();
}

void GLWidget::velColorId(int id)
{
	VelColor = id;
	if (!perm) Update();
}

void GLWidget::Pause(void)
{
	perm = !perm; 
	emit isPause(!perm);
}

void GLWidget::Clear(void)
{
	clear_data();
	perm = true;
	dvel = false; 
	emit isVector(dvel);
	emit isPause(!perm);
}

void GLWidget::Vector(void)
{
	dvel = !dvel;
	if (!perm) Update();
	emit isVector(dvel);
}

void GLWidget::resolution(bool id)
{
	N = id ? 62 : 126;
	Clear();
}

void GLWidget::changeVisc(int id)
{
	visc = id * 0.001;
	emit setVisc(id);
}

void GLWidget::changeDiff(int id)
{
	diff = id * 0.001;
	emit setDiff(id);
}