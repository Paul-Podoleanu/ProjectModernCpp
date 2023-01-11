#pragma once

#include <QMainWindow>
#include "ui_NumericAnswer.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <string>

class NumericAnswer : public QMainWindow
{
	Q_OBJECT

public:
	NumericAnswer(QWidget* parent = nullptr, std::string username = "");
	~NumericAnswer();

private:
	Ui::NumericAnswerClass ui;
	std::string m_username;
};
