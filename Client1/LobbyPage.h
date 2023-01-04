#pragma once
#include <QMainWindow>
#include "Game.h"
#include "utils.h"
#include <cpr/cpr.h>
#include "ui_LobbyPage.h"

class LobbyPage :
	public QMainWindow
{
	Q_OBJECT

private:
	Ui::Lobby ui;
	std::string m_Owner;

public slots:
	//void on_StartGame_clicked();
	void on_StartGame_clicked() {
		//switch in functie de numarul de playeri conectati
		Game* game = new Game(nullptr, 3, 3);
		game->resize(1200, 600);
		game->show();
	};
	std::vector<std::string> reload(std::string owner)
	{
		cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/players" },
			cpr::Body{ "&username=" + owner });
		std::string response = r.text;
		qDebug() << r.text.c_str();
		std::vector<std::string> players = split(response, ",");
		return players;
	}
public:
	LobbyPage(QWidget* parent = nullptr, std::string owener = "");
	~LobbyPage() {};
};

