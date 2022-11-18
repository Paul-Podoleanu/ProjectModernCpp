#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
class Board
{
private:
	std::pair<int, int> dimensions;
	std::vector<Region>m_regions;
	int nrPlayers;
	int nrRounds;
	Board();
	~Board();
	void setnrPlayers(int nrPlayers);
	int getnrPlayers();
	void setDimension();
};

