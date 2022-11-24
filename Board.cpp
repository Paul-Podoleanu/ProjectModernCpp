#include "Board.h"

Board::Board()
{

}

Board::~Board()
{
}

void Board::setnrPlayers(int nrPlayers)
{
	this->nrPlayers = nrPlayers;
}

int Board::getNrPlayers()
{
	return nrPlayers;
}

Region Board::getSpecificRegion(std::string region)
{
	for (auto& r : m_regions) {
		if (r.getName() == region) {
			return r;
		}
	}
}

void Board::setDimension()
{
	if (nrPlayers == 2)
	{
		nrRounds = 5;
		dimensions.first = 3;
		dimensions.second = 3;
	}
	else if (nrPlayers == 3)
	{
		nrRounds = 4;
		dimensions.first = 5;
		dimensions.second = 3;
	}
	else if (nrPlayers == 4)
	{
		nrRounds = 4;
		dimensions.first = 6;
		dimensions.second = 4;
	}
}

void Board::setRegionsNumber()
{
	if (dimensions.first == 3 && dimensions.second ==3)
		size = 9;
	if (dimensions.first == 5 && dimensions.second == 3)
		size = 15;
	if (dimensions.first == 6 && dimensions.second == 4)
		size = 24;
}
