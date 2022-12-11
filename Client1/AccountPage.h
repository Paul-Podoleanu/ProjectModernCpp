#pragma once

#include <QMainWindow>
#include <cpr/cpr.h>
#include <string>
#include "ui_AccountPage.h"

class AccountPage : public QMainWindow
{
	Q_OBJECT

public:
	void displayUsername();
	AccountPage(QWidget *parent = nullptr);
	~AccountPage();

private:
	Ui::AccountPageClass ui;
};
