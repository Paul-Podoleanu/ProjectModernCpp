#include "Account.h"

Account::Account()
{
}

Account::Account(std::string firstname, std::string surname, std::string email, std::string username, std::string password)
	: m_firstname(firstname), m_surname(surname), m_email(email), m_username(username), m_password(password)
{
}

bool Account::operator==(const Account& other)
{
	if (this->m_username != other.m_username)
	{
		return false;
	}
	if (this->m_password != other.m_password)
	{
		return false;
	}
	if (this->m_email != other.m_email)
	{
		return false;
	}
	if (this->m_firstname != other.m_firstname)
	{
		return false;
	}
	if (this->m_surname != other.m_surname)
	{
		return false;
	}
	return true;
}

Account::~Account()
{
}

