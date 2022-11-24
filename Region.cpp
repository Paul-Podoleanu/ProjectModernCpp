#include "Region.h"

Region::Region()
{
}

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

void Region::setIsFormerBase(bool status)
{
	this->m_isFormerBase = status;
}


void Region::setisOwned(bool status)
{
	this->isOwned = status;
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

bool Region::getIsFormerBase()
{
	return this->m_isFormerBase;
}


bool Region::getisOwned()
{
	return isOwned;
}

bool Region::operator==(const Region& region) const
{
	/*Doua regiuni nu ar trebui sa aiba acelasi nume, deci toate sunt diferite in acest aspect
	Restul de variabile/caracteristici nu diferentiaza reginuile in sine, doar cum se comporta
	intr-o anumita stare a jocului (ex: Daca un player are baza in regiune) */
	if (this->m_name == region.m_name) {
		return true;
	}
	return false;
}

