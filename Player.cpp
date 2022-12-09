#include "Player.h"

Player::Player()
{
}

Player::Player(std::string name, std::string color, int score, bool active, std::vector<Region> regions, Region m_base)
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
void Player::getPlayerHistory()
{
}
Player& Player::operator=(const Player& player)
{
	m_name = player.m_name;
	m_active = player.m_active;
	m_base = player.m_base;
	m_color = player.m_color;
	m_regions = player.m_regions;
	m_score = player.m_score;
	return *this;
}

bool Player::operator==(const Player& player) const
{
	//In teorie 2 jucatori nu ar trb sa aiba acelasi nume, deci se va compara doar dupa nume
	if (this->m_name == player.m_name) {
		return true;
	}
	return false;
}

