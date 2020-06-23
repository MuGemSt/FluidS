#include "smokesimulation.h"
#include <QtWidgets/QApplication>
#include <QtPlugin>

#ifdef QT_NO_DEBUG
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
#endif

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SmokeSimulation w;
	w.show();
	return a.exec();
}
