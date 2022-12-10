#pragma once

#include <QMainWindow>
#include "ui_MainPage.h"

class MainPage : public QMainWindow
{
	Q_OBJECT

public:
	MainPage(QWidget *parent = nullptr);
	~MainPage();

private:
	Ui::MainPageClass ui;
};
