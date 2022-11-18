#include "Board.h"

void Board::setnrPlayers(int nrPlayers)
{
	this->nrPlayers = nrPlayers;
}

int Board::getnrPlayers()
{
	return nrPlayers;
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
