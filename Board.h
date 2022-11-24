#pragma once
#include "Player.h"
#include "Region.h"
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

public:
	Board();
	~Board();

	//Set
	void setnrPlayers(int nrPlayers);
	void setDimension();
	void setRegionsNumber();

	//Get
	int getNrPlayers();
	std::vector<Region> getRegions() { return m_regions; }
	Region getSpecificRegion(std::string region);

	//Overload operator
	//Board& operator=(const Board& other);

};

