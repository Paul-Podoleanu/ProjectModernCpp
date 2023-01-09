#pragma once

#include <QMainWindow>
#include "ui_Game.h"
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <iostream>
#include <cpr/cpr.h>
#include <crow.h>
#include "Play.h"

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent = nullptr, int rows=0, int columns=0);
	~Game();
private slots:
	void on_button_clicked();

private:
	Ui::GameClass ui;
	std::vector<QPushButton*>buttons;
};
