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

private:
	Ui::PlayClass ui;
};
