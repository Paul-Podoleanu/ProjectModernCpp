#pragma once
#include <iostream>
#include"Player.h"
#include"Region.h"
class DuelManager
{
private:
public:
	DuelManager();
	~DuelManager();
	void NormalRegionDuel(bool isBase);
	void BaseDuel(bool isBase);
	void DuelTime();
};

