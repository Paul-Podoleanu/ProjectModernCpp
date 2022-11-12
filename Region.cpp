#include "Region.h"

void Region::setName(std::string name)
{
	this->m_name = name;
}

void Region::setPoints(int score)
{
	this->m_points = score;
}

void Region::setIsBase(bool status)
{
	this->m_isBase = status;
}

std::string Region::getName()
{
	return this->m_name;
}

int Region::getPoints()
{
	return this->m_points;
}

bool Region::getIsBase()
{
	return this->m_isBase;
}
