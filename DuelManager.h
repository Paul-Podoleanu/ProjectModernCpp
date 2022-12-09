#pragma once
#include <iostream>
#include "Question.h"
#include "Board.h"

class DuelManager
{
private:
public:
	DuelManager();
	~DuelManager();
	void NormalRegionDuel(bool isBase);
	Player BaseDuel(Question q,Player one, Player two, bool isBase);
	void DuelTime();

	//Duels
	//Momentan se dau raspunsuri in consola
	//O sa inlocuim cum se dau raspunsurile, intr-un GUI, alta data

	//Two-Player-Duel
	//Return este jucatorul care a castigat
	Player TwoPlayerDuelABCD(Question q, Player one, Player two, int score);
	Player TwoPlayerDuelNumeric(Question q, Player one, Player two, int score);

	//Three-Player-Duel
	//O sa fie folosite la inceput de joc, sau posibil la final
	void ThreePlayerDuelABCD(Board b, Question q, Player one, Player two, Player three, int score);
};


