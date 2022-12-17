#include "MainPage.h"
#include "Play.h"
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

void MainPage::on_Play_clicked()
{
	Play* play = new Play(this);
	play->resize(1200, 600);
	play->show();
}
