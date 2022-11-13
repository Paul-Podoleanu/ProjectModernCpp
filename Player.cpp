#include "Player.h"

void Player::setColor(std::string m_color)
{
	this->m_color = m_color;
}

void Player::setBase(Region m_baza)
{
	this->m_base = m_base;
}

void Player::setFormerBase(Region m_formerbase)
{
	this->m_formerbase = m_formerbase;
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

Region Player::getBase()
{
	return m_base;
}

Region Player::getFormerBase()
{
	return m_formerbase;
}

void Player::changeScore(int dif)
{
	this->m_score = this->m_score + dif;
}
