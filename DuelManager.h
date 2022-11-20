#pragma once
#include <iostream>
#include"Player.h"
#include"Region.h"
#include "Question.h"
#include "Board.h"

class DuelManager
{
private:
public:
	DuelManager();
	~DuelManager();
	void NormalRegionDuel(bool isBase);
	void BaseDuel(bool isBase);
	void DuelTime();

	//Duels
	//Momentan se dau raspunsuri in consola
	//O sa inlocuim cum se dau raspunsurile, intr-un GUI, alta data

	//Two-Player-Duel
	void TwoPlayerDuelABCD(Question q, Player one, Player two, int score);
	void TwoPlayerDuelNumeric(Question q, Player one, Player two, int score);

	//Three-Player-Duel
	//O sa fie folosite la inceput de joc, sau posibil la final
	void ThreePlayerDuelABCD(Board b, Question q, Player one, Player two, Player three, int score);
};


