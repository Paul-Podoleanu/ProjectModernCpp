#pragma once
#include <QMainWindow>
#include "Game.h"
#include "ui_LobbyPage.h"

class LobbyPage :
	public QMainWindow
{
	Q_OBJECT

private:
	Ui::Lobby ui;

public slots:
	//void on_StartGame_clicked();
	void on_StartGame_clicked() {
		//switch in functie de numarul de playeri conectati
		Game* game = new Game(nullptr, 3, 3);
		game->resize(1200, 600);
		game->show();
	};

public:
	LobbyPage(QWidget* parent = nullptr);
	~LobbyPage() {};
};

