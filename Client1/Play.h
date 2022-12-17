#pragma once

#include <QMainWindow>
#include "ui_Play.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <string>
class Play : public QMainWindow
{
	Q_OBJECT

public:
	Play(QWidget *parent = nullptr);
	~Play();
public slots:
	void on_AnswerA_clicked();
	void on_AnswerB_clicked();
	void on_AnswerC_clicked();
	void on_AnswerD_clicked();
private:
	Ui::PlayClass ui;
	std::string correctAnswer;
};
