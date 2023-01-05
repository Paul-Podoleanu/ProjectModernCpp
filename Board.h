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
	//Regiunile sunt trecute ca pair, Region: regiunea prorpiu zisa; Player: jucatorul ce detine acea regiune
	//Structureat astfel pentru a nu include Region.h in clasa Player
	std::vector<std::pair<Region,Player>> m_regions;
	int nrPlayers;
	int nrRounds;

public:


	Board();
	Board(std::pair<int, int> dimensions, int size, std::vector<std::pair<Region, Player>> m_regions, int nrPlayers, int nrRounds);
	~Board();

	//Set
	void setnrPlayers(int nrPlayers);
	void setDimension();
	void setRegionsNumber();

	//Get
	int getNrPlayers();
	std::vector<std::pair<Region, Player>>& getRegions() { return m_regions; }
	Region getSpecificRegion(std::string region);

	//General use functions
	void addRegion(Region addedRegion, Player addedPLayer);

	//Overload operator
	Board& operator=(const Board& other);

};

