#pragma once
#include "Board.h"
#include "Question.h"
class GameConosoleVersion
{
	//Initial o sa fac ca jocul sa fie doar pentru 2 jucatori
private:
	//Trebuie setat board-ul, regiunile din el, dimensiunile etc;
	Board table;
	std::vector<Player> players;

public:
	//Gameplay
	void chooseBaseStartOfGame2Player(Player one, Player two);
	
	//Setup joc

};

