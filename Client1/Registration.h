#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Registration.h"
#include <cpr/cpr.h>
#include <crow.h>
#include <iostream>
#include<string>
#include <sstream>
#include <qmessagebox.h>

class Registration : public QMainWindow
{
    Q_OBJECT

public:
    Registration(QWidget *parent = nullptr);
    ~Registration();
public slots:
    void on_Login_clicked();
    void on_Register_clicked();
 
private:
	Ui::RegistrationClass ui;
};
