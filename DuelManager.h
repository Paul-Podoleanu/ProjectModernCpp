#pragma once
#include <iostream>
#include"Player.h"
#include"Region.h"
#include "Question.h"

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
	void TwoPlayerDuelABCD(Question q, Player one, Player two, int score);
	void TwoPlayerDuelNumeric(Player one, Player Two, int score);
};

