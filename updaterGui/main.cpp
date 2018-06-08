#include "updatergui.h"
#include <QtWidgets/QApplication>

#include <QApplication>
#include <updatecontroller.h>
#include <updater.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Since there is no mainwindow, the various dialogs should not quit the app
	QApplication::setQuitOnLastWindowClosed(false);
	//create the update controller with the application as parent -> will live long enough start the tool on exit
	//since there is no parent window, all dialogs will be top-level windows
	QtAutoUpdater::UpdateController *controller = new QtAutoUpdater::UpdateController("C:/Program Files (x86)/3tee/avdMeeting/maintenancetool.exe", &a);//.exe is automatically added
	//QtAutoUpdater::Updater *updater = new QtAutoUpdater::Updater("D:\Qt\Qt5.9.0\MaintenanceTool", &a);//.exe is automatically added

	QObject::connect(controller, &QtAutoUpdater::UpdateController::runningChanged, [controller](bool running) {
	//	qDebug() << "Running changed:" << running;
		//quit the application as soon as the updating finished
		if (!running)
			qApp->quit();
	});

	//start the update check -> AskLevel to give the user maximum control
	controller->start(QtAutoUpdater::UpdateController::AskLevel);
	return a.exec();
}