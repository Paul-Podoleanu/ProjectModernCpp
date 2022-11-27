#pragma once
#include "Board.h"
#include "Question.h"
class GameConosoleVersion
{
	//Initial o sa fac ca jocul sa fie doar pentru 2 jucatori
private:

	Board tabla;
	std::vector<Player> Jucatori;

public:
	
	void chooseBaseStartOfGame(Player one, Player two);


};

