#pragma once
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QMainWindow>
#include "ui_MainPage.h"
#include "AccountPage.h"

class MainPage : public QMainWindow
{
	Q_OBJECT

public:
	MainPage(QWidget *parent = nullptr);
	~MainPage();

public slots:
	void on_Cont_clicked();
	void on_Play_clicked();
private:
	Ui::MainPageClass ui;
	AccountPage* accountPage;
};
