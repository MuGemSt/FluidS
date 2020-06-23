#ifndef SMOKESIMULATION_H
#define SMOKESIMULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include<QTimer>

#include"GLWidget.h" 

class SmokeSimulation : public QWidget
{
	Q_OBJECT

public:
    QWidget *centralWidget;
    
    QGroupBox *groupBox_Ref;
    QSlider *horizontalSlider_Diff;
    QSlider *horizontalSlider_Visc;
    QLabel *label_Visc;
    QLabel *label_Diff;
    QLabel *label_ViscName;
    QLabel *label_DiffName;
    QGroupBox *groupBox_Res;
    QRadioButton *radioButton_64;
    QRadioButton *radioButton_128;
    
    QPushButton *pushButton_Clear;
	QPushButton *pushButton_Pause;
	QPushButton *pushButton_Vector;

    QOpenGLWidget *openGLWidget;
    QGroupBox *groupBox_Color;
    QComboBox *comboBox_VelColor;
    QComboBox *comboBox_DenColor;
    QLabel *label_Den;
    QLabel *label_Vel;
    QStatusBar *statusBar;

	QTimer *timer_ReDraw;

public:
	SmokeSimulation(QWidget *parent = 0);
	~SmokeSimulation();

	void setupUi(QWidget *SmokeSimulationClass);
	void retranslateUi(QWidget *SmokeSimulationClass);

public slots:
	void PauseSlot(bool);
	void VecMod(bool);
};

#endif // SMOKESIMULATION_H
