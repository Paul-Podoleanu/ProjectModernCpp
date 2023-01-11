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
	Game(QWidget* parent = nullptr, int rows = 0, int columns = 0, std::string username = "", std::string Owner = "");
	~Game();
private slots:
	void on_button_clicked();
	void players();
private:
	Ui::GameClass ui;
	std::vector<QPushButton*>buttons;
	std::string m_Answer;
	std::string username;
	std::string m_owner;
};
