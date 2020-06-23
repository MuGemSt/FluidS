#include "smokesimulation.h"

SmokeSimulation::SmokeSimulation(QWidget *parent)
	: QWidget(parent)
{
	 setupUi(this);
}

SmokeSimulation::~SmokeSimulation()
{

}

void SmokeSimulation::setupUi(QWidget *SmokeSimulationClass)
    {
		if (SmokeSimulationClass->objectName().isEmpty())
			
	    SmokeSimulationClass->setObjectName(QStringLiteral("SmokeSimulationClass"));
		SmokeSimulationClass->resize(800, 555);
		SmokeSimulationClass->setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);  
		SmokeSimulationClass->setFixedSize(this->width(), this->height());  

		QFont font;
		font.setFamily(QStringLiteral("Microsoft YaHei UI"));
		SmokeSimulationClass->setFont(font);
		SmokeSimulationClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

		centralWidget = new QWidget(SmokeSimulationClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		pushButton_Vector = new QPushButton(centralWidget);
		pushButton_Vector->setObjectName(QStringLiteral("pushButton_Vector"));
		pushButton_Vector->setGeometry(QRect(720, 490, 71, 31));
		groupBox_Ref = new QGroupBox(centralWidget);
		groupBox_Ref->setObjectName(QStringLiteral("groupBox_Ref"));
		groupBox_Ref->setGeometry(QRect(550, 160, 231, 131));
		horizontalSlider_Diff = new QSlider(groupBox_Ref);
		horizontalSlider_Diff->setObjectName(QStringLiteral("horizontalSlider_Diff"));
		horizontalSlider_Diff->setGeometry(QRect(90, 90, 111, 20));
		horizontalSlider_Diff->setMaximum(10);
		horizontalSlider_Diff->setPageStep(1);
		horizontalSlider_Diff->setSliderPosition(0);
		horizontalSlider_Diff->setOrientation(Qt::Horizontal);
		horizontalSlider_Diff->setTickPosition(QSlider::TicksAbove);
		horizontalSlider_Visc = new QSlider(groupBox_Ref);
		horizontalSlider_Visc->setObjectName(QStringLiteral("horizontalSlider_Visc"));
		horizontalSlider_Visc->setGeometry(QRect(90, 40, 111, 19));
		horizontalSlider_Visc->setMaximum(10);
		horizontalSlider_Visc->setPageStep(1);
		horizontalSlider_Visc->setValue(0);
		horizontalSlider_Visc->setOrientation(Qt::Horizontal);
		horizontalSlider_Visc->setTickPosition(QSlider::TicksAbove);
		label_Visc = new QLabel(groupBox_Ref);
		label_Visc->setObjectName(QStringLiteral("label_Visc"));
		label_Visc->setGeometry(QRect(210, 40, 54, 12));
		label_Diff = new QLabel(groupBox_Ref);
		label_Diff->setObjectName(QStringLiteral("label_Diff"));
		label_Diff->setGeometry(QRect(210, 90, 54, 12));
		label_ViscName = new QLabel(groupBox_Ref);
		label_ViscName->setObjectName(QStringLiteral("label_ViscName"));
		label_ViscName->setGeometry(QRect(10, 40, 71, 20));
		label_DiffName = new QLabel(groupBox_Ref);
		label_DiffName->setObjectName(QStringLiteral("label_DiffName"));
		label_DiffName->setGeometry(QRect(10, 90, 81, 16));
		groupBox_Res = new QGroupBox(centralWidget);
		groupBox_Res->setObjectName(QStringLiteral("groupBox_Res"));
		groupBox_Res->setGeometry(QRect(550, 30, 231, 91));
		radioButton_64 = new QRadioButton(groupBox_Res);
		radioButton_64->setObjectName(QStringLiteral("radioButton_64"));
		radioButton_64->setGeometry(QRect(20, 30, 89, 16));
		radioButton_64->setChecked(false);
		radioButton_128 = new QRadioButton(groupBox_Res);
		radioButton_128->setObjectName(QStringLiteral("radioButton_128"));
		radioButton_128->setGeometry(QRect(20, 60, 89, 16));
		radioButton_128->setChecked(true);

		pushButton_Pause = new QPushButton(centralWidget);
		pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));
		pushButton_Pause->setGeometry(QRect(540, 490, 75, 31));
		pushButton_Vector = new QPushButton(centralWidget);
        pushButton_Vector->setObjectName(QStringLiteral("pushButton_Vector"));
        pushButton_Vector->setGeometry(QRect(720, 490, 75, 31));
        pushButton_Clear = new QPushButton(centralWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));
        pushButton_Clear->setGeometry(QRect(630, 490, 75, 31));

		openGLWidget = new GLWidget(centralWidget);
		openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
		openGLWidget->setGeometry(QRect(20, 20, 512, 512));
		groupBox_Color = new QGroupBox(centralWidget);
		groupBox_Color->setObjectName(QStringLiteral("groupBox_Color"));
		groupBox_Color->setGeometry(QRect(550, 330, 231, 141));
		comboBox_VelColor = new QComboBox(groupBox_Color);
		comboBox_VelColor->setObjectName(QStringLiteral("comboBox_VelColor"));
		comboBox_VelColor->setGeometry(QRect(100, 90, 111, 22));
		comboBox_DenColor = new QComboBox(groupBox_Color);
		comboBox_DenColor->setObjectName(QStringLiteral("comboBox_DenColor"));
		comboBox_DenColor->setGeometry(QRect(100, 40, 111, 22));
		label_Den = new QLabel(groupBox_Color);
		label_Den->setObjectName(QStringLiteral("label_Den"));
		label_Den->setGeometry(QRect(10, 40, 61, 20));
		label_Vel = new QLabel(groupBox_Color);
		label_Vel->setObjectName(QStringLiteral("label_Vel"));
		label_Vel->setGeometry(QRect(10, 90, 71, 20));

		timer_ReDraw = new QTimer;
		timer_ReDraw->setInterval(1);

        retranslateUi(SmokeSimulationClass);
		
		//=================================GLWidget received signals====================================
		//Resolution
		QObject::connect(radioButton_64, SIGNAL(toggled(bool)), openGLWidget, SLOT(resolution(bool)));

		//Parameter
		QObject::connect(horizontalSlider_Diff, SIGNAL(valueChanged(int)), openGLWidget, SLOT(changeDiff(int)));
		QObject::connect(horizontalSlider_Visc, SIGNAL(valueChanged(int)), openGLWidget, SLOT(changeVisc(int))); 

		//Color
		QObject::connect(comboBox_DenColor, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(denColorId(int)));
		QObject::connect(comboBox_VelColor, SIGNAL(currentIndexChanged(int)), openGLWidget, SLOT(velColorId(int)));

		//Buttons
		QObject::connect(pushButton_Pause, SIGNAL(clicked()), openGLWidget, SLOT(Pause()));
		QObject::connect(pushButton_Clear, SIGNAL(clicked()), openGLWidget, SLOT(Clear()));
		QObject::connect(pushButton_Vector, SIGNAL(clicked()), openGLWidget, SLOT(Vector()));

		//Timer 
		QObject::connect(timer_ReDraw, SIGNAL(timeout()), openGLWidget, SLOT(Update()));

		//=================================GLWidget emitted signals====================================
		//Parameter
		QObject::connect(openGLWidget, SIGNAL(setDiff(int)), label_Diff, SLOT(setNum(int)));
		QObject::connect(openGLWidget, SIGNAL(setVisc(int)), label_Visc, SLOT(setNum(int)));

		//Buttons
		QObject::connect(openGLWidget, SIGNAL(isVector(bool)), this, SLOT(VecMod(bool)));
		QObject::connect(openGLWidget, SIGNAL(isPause(bool)), this, SLOT(PauseSlot(bool)));

    }

void SmokeSimulation::retranslateUi(QWidget *SmokeSimulationClass)
    {
        SmokeSimulationClass->setWindowTitle(QApplication::translate("SmokeSimulationClass", "Fluid Simulatior", 0));
        pushButton_Vector->setText(QApplication::translate("SmokeSimulationClass", "Vector", 0)); 
        groupBox_Ref->setTitle(QApplication::translate("SmokeSimulationClass", "Parameter", 0));
        label_Visc->setText(QApplication::translate("SmokeSimulationClass", "0", 0));
        label_Diff->setText(QApplication::translate("SmokeSimulationClass", "0", 0));
        label_ViscName->setText(QApplication::translate("SmokeSimulationClass", "Viscosity:", 0));
        label_DiffName->setText(QApplication::translate("SmokeSimulationClass", "Diffusivity:", 0));
        groupBox_Res->setTitle(QApplication::translate("SmokeSimulationClass", "Resolution", 0));
        radioButton_64->setText(QApplication::translate("SmokeSimulationClass", "64", 0));
        radioButton_128->setText(QApplication::translate("SmokeSimulationClass", "128", 0));
        pushButton_Pause->setText(QApplication::translate("SmokeSimulationClass", "Pause", 0)); 
        pushButton_Clear->setText(QApplication::translate("SmokeSimulationClass", "Clear", 0));
        groupBox_Color->setTitle(QApplication::translate("SmokeSimulationClass", "Color", 0));
        comboBox_VelColor->clear();
        comboBox_VelColor->insertItems(0, QStringList()
         << QApplication::translate("SmokeSimulationClass", "White", 0)
		 << QApplication::translate("SmokeSimulationClass", "Red", 0)
         << QApplication::translate("SmokeSimulationClass", "Green", 0)
		 << QApplication::translate("SmokeSimulationClass", "Blue", 0)
		 << QApplication::translate("SmokeSimulationClass", "Yellow", 0)
         << QApplication::translate("SmokeSimulationClass", "Purple", 0)
		 << QApplication::translate("SmokeSimulationClass", "Skyblue", 0)
        );
        comboBox_DenColor->clear();
		comboBox_VelColor->setCurrentIndex(1);
        comboBox_DenColor->insertItems(0, QStringList()
         << QApplication::translate("SmokeSimulationClass", "White", 0)
		 << QApplication::translate("SmokeSimulationClass", "Red", 0)
         << QApplication::translate("SmokeSimulationClass", "Green", 0)
		 << QApplication::translate("SmokeSimulationClass", "Blue", 0)
		 << QApplication::translate("SmokeSimulationClass", "Yellow", 0)
         << QApplication::translate("SmokeSimulationClass", "Purple", 0)
		 << QApplication::translate("SmokeSimulationClass", "Skyblue", 0)
        );
        label_Den->setText(QApplication::translate("SmokeSimulationClass", "Density:", 0));
        label_Vel->setText(QApplication::translate("SmokeSimulationClass", "Velocity:", 0));

		timer_ReDraw->start();
    }

void SmokeSimulation::PauseSlot(bool ip)
{

	if (ip){
		timer_ReDraw->stop();
		pushButton_Pause->setText("Continue");
	}
	else{
		timer_ReDraw->start();
		pushButton_Pause->setText("Pause");
	}

}

void SmokeSimulation::VecMod(bool iv)
{
	pushButton_Vector->setText(iv ? "Scalar" : "Vector");
}

