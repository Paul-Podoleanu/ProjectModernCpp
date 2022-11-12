#include "Player.h"

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

void Player::deactivate_player()
{
	this->m_active = false;
}

void Player::changeScore(int dif)
{
	this->m_score = this->m_score + dif;
}
