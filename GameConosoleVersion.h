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

	//Functia pentru intrebari inainte de joc-propriu zis, dar dupa alegerea bazei
	//toate intrebarile se tin in functia asta, in cazut la 2 jucatori o sa fie 2 intrebari
	//int-urile corespund nr de intrebari raspunse corect de fiecare jucator, si nr de regiuni ce vor putea alege
	std::pair<int, int> preGameQuestions2Player(Player one, Player two);



	//Setup joc
	void addPlayer(Player one);

};

