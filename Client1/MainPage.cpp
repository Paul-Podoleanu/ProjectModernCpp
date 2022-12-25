#include "MainPage.h"
#include "Play.h"
MainPage::MainPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}
void MainPage::on_Cont_clicked()
{
	accountPage = new AccountPage();
	accountPage->resize(800, 600);
	accountPage->show();
}
MainPage::~MainPage()
{}

void MainPage::on_Play_clicked()
{
	Play* play = new Play();
	play->resize(1200, 600);
	play->show();
}

void MainPage::on_doi_clicked()
{
	Game* game = new Game(nullptr,3, 3);
	game->resize(1200, 600);
	game->show();
}

void MainPage::on_trei_clicked()
{
	Game* game = new Game(nullptr,3, 5);
	game->resize(1200, 600);
	game->show();
}

void MainPage::on_patru_clicked()
{
	Game* game = new Game(nullptr,3, 6);
	game->resize(1200, 600);
	game->show();
}
