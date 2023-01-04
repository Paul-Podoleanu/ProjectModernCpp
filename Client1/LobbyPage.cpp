#include "LobbyPage.h"
LobbyPage::LobbyPage(QWidget* parent, std::string owner) : QMainWindow(parent)
{

	ui.setupUi(this);
	m_Owner = owner;
	std::vector<std::string>players = reload(owner);
	if (players[0] != "*")
	{
		ui.Player1->setText(players[0].c_str());
	}
	if (players[1] != "*")
	{
		ui.Player2->setText(players[1].c_str());
	}
	if (players[2] != "*")
	{
		ui.Player3->setText(players[2].c_str());
	}
	if (players[3] != "*")
	{
		ui.Player4->setText(players[3].c_str());
	}
}