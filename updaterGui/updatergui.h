#ifndef UPDATERGUI_H
#define UPDATERGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_updatergui.h"

class updaterGui : public QMainWindow
{
	Q_OBJECT

public:
	updaterGui(QWidget *parent = 0);
	~updaterGui();

private:
	Ui::updaterGuiClass ui;
};

#endif // UPDATERGUI_H
