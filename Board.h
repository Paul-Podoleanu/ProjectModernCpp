#pragma once
#include "Player.h"
#include <iostream>
#include <vector>
class Board
{
private:
	std::pair<int, int> dimensions;
	int size;
	std::vector<Region>m_regions;
	int nrPlayers;
	int nrRounds;
	std::vector < std::vector<int, int>>BoardMatrix;
public:
	Board();
	~Board();
	void setnrPlayers(int nrPlayers);
	int getnrPlayers();
	void setDimension();
	void setRegionsNumber();

};

