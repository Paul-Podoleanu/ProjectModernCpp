#pragma once

#include <QMainWindow>
#include "ui_Game.h"
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <iostream>

class Game : public QMainWindow
{
	Q_OBJECT

public:
	Game(QWidget *parent = nullptr, int rows=0, int columns=0);
	~Game();
private slots:
	void on_button_clicked()
	{
		QPushButton* button = qobject_cast<QPushButton*>(sender());
		QMessageBox::information(this, tr("Button clicked"), button->text());
	}

private:
	Ui::GameClass ui;
	std::vector<QPushButton*>buttons;
};
