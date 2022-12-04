#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTWidgetsApp.h"

class QTWidgetsApp : public QMainWindow
{
    Q_OBJECT

public:
    QTWidgetsApp(QWidget *parent = nullptr);
    ~QTWidgetsApp();

private:
    Ui::QTWidgetsAppClass ui;
};
