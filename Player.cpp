#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::setName(std::string m_name)
{

}

void Player::setColor(std::string m_color)
{
	this->m_color = m_color;
}

void Player::setBase(Region m_base)
{
	this->m_base = m_base;
}

int Player::getScore()
{
	return this->m_score;
}

std::string Player::getName()
{
	return this->m_name;
}

bool Player::getActive()
{
	return this->m_active;
}

std::string Player::getColor()
{
	return m_color;
}

void Player::deactivate_player()
{
	this->m_active = false;
}

void Player::reactivatePlayer()
{
	this->m_active = true;
}

Region Player::getBase()
{
	return m_base;
}

void Player::changeScore(int dif)
{
	this->m_score = this->m_score + dif;
}

void Player::addRegion(Region newRegion)
{
	m_regions.push_back(newRegion);
}

//void Player::addRegion(std::string newRegion, Board b)
//{
//	for (auto& region : b.getRegions()) {
//		if (newRegion == region.getName()) {
//			this->addRegion(region);
//			break;
//		}
//	}
//}

void Player::loseRegion(Region lostRegion)
{
	for (int i = 0; i < m_regions.size(); i++) {
		if (m_regions[i] == lostRegion) {
			m_regions.erase(m_regions.begin()+i);
			break;
		}
	}
}
//void Player::chooseBase(Board b)
//{
//	int linie, coloana;
//	std::cin >> linie >> coloana;
//	std::vector < std::vector<Region>>board; //= b.getBoard();
//	if (board[linie][coloana].getisOwned() == false)
//	{
//		m_baza = board[linie][coloana];
//		board[linie][coloana].setisOwned(true);
//		board[linie][coloana].setOwner(*this);
//	}
//	else
//	{
//		std::cout << "Alege alta baza";
//		chooseBase(b);
//	}
//}
