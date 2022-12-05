#pragma once
#include "DuelManager.h"
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
	void chooseBaseStartOfGame2Player(Player one, Player two);

	//Functia pentru intrebari inainte de joc-propriu zis, dar dupa alegerea bazei
	//toate intrebarile se tin in functia asta, in cazut la 2 jucatori o sa fie 2 intrebari
	//int-urile corespund nr de intrebari raspunse corect de fiecare jucator, si nr de regiuni ce vor putea alege
	std::pair<int, int> preGameQuestions2Player(Player one, Player two);

	//Functia ar trebui folosita pentru alegerea de regiuni dupa 
	void pickRegion(Player one, int nrRegions); 
	

	//Setup joc
	void addPlayer(Player one);


	//Joc-ul in sine
	//void Game();
};

