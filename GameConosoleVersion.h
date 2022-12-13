#pragma once
#include "DuelManager.h"
#include <stdlib.h>
#include <conio.h>
/*
SPECIFICATII PENTRU VERSIUNEA DE CONSOLA

>Jocul este pentru 2 jucatori, nu am implementat inca o metoda pentru a verifica
daca 2 regiuni sunt vecine, deci momentan se poate alege o regiune oriune fie pentru
stabilit la inceput de joc, fie pentru a ataca un alt jucator

>Selectarea de raspunsuri, alegere de regiuni se face prin input direct de la tastatura prin
scriere de string-uri 
*/

class GameConosoleVersion
{
private:
	//Trebuie setat board-ul, regiunile din el, dimensiunile etc;
	Board table;
	std::vector<Player> players;
	Question questions;

public:
	//Gameplay
	GameConosoleVersion();
	~GameConosoleVersion();
	GameConosoleVersion(std::vector<Player> players, Board table, Question questions);
	void chooseBaseStartOfGame2Player(Player &one, Player &two);

	//Functia pentru intrebari inainte de joc-propriu zis, dar dupa alegerea bazei
	//toate intrebarile se tin in functia asta, in cazut la 2 jucatori o sa fie 2 intrebari
	//int-urile corespund nr de intrebari raspunse corect de fiecare jucator, si nr de regiuni ce vor putea alege
	std::pair<int, int> preGameQuestions2Player(Player& one, Player& two);

	//Functia ar trebui folosita pentru alegerea de regiuni
	void pickRegion(Player& one, int nrRegions);
	
	//Player one ataca Player two, pentru regiunea parametru
	void attackPlayer(Player& one, Player& two, Region region);
	Player AttackPlayerBase(Player& one, Player& two, Region base);

	//Functie pentru gsit regiune doar prin nume
	Region getRegionByName(std::string nume);

	//Functie pentru afisare stats
	//O sa trebuiasaca sa ia direct din vectorul de playeri, dar o sa ne ocupam de asta
	//cand refacem si restul de functii sa mearga pe nr variabil de playeri
	void showStats(Player one, Player two);


	//Setup joc
	void addPlayer(Player one);
	void addRegion(Region reg);
	Question getQuestions();
	void ReadQuestion();

	//Joc-ul in sine
	void StartGame(Player one, Player two, int numberRounds);
};

