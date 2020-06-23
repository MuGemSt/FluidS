#define IX(i,j) ((i)+(N+2)*(j))
#define SWAP(x0,x) {float * tmp=x0;x0=x;x=tmp;}
#define FOR_EACH_CELL for ( i=1 ; i<=N ; i++ ) { for ( j=1 ; j<=N ; j++ ) {
#define END_FOR }}

#include <stdlib.h>
#include <stdio.h> 

static int N;
static float dt, diff, visc;
static float force, source;

static bool perm;
static bool dvel;
static int DenColor;
static int VelColor;

static float * u, *v, *u_prev, *v_prev;
static float * dens, *dens_prev;

static int win_id;
static int win_x, win_y;
static int mouse_down[3];
static int omx, omy, mx, my;



#ifndef GLWIDGET_H
#define GLWIDGET_H

#include<QMouseEvent>

#include <QtWidgets/QOpenGLWidget>

class QVector3D;
class GLWidget: public QOpenGLWidget
{
    Q_OBJECT

public:

    GLWidget(QWidget *parent=0);

private:

    void static free_data(void);
    void static clear_data(void);
    int static allocate_data(void);
	void static draw_velocity(void);
    void static draw_density(void);
	void static InitVariable(void);
	void static display_func(void);
    void static get_from_UI(float *, float *, float *);
    void static mouse_func(int, int, int, int);
    void static motion_func(int, int);
    void static choose_color(int, float);	


protected:
    void initializeGL();
    void resizeGL(int, int);
    void paintGL();

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

public slots:
	//Resolution
	void resolution(bool);

	//Parameter
	void changeVisc(int);
	void changeDiff(int);

	//Color
	void denColorId(int);
	void velColorId(int); 

	//Buttons
	void Pause(void);
	void Clear(void);
	void Vector(void); 

	//Timer
	void Update(void);

signals:
	//Parameter
	void setVisc(int);
	void setDiff(int);

	//Buttons
	void isVector(bool);
	void isPause(bool);


};

#endif // GLWIDGET_H
