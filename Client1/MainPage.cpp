#include "MainPage.h"
MainPage::MainPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void MainPage::on_Cont_clicked()
{
	accountPage = new AccountPage(this);
	accountPage->resize(800, 600);
	accountPage->show();
}
MainPage::~MainPage()
{}
