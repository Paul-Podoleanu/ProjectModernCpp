#include "Account.h"

Account::Account()
{
}

Account::Account(std::string firstname, std::string surname, std::string email, std::string username, std::string password)
{
	m_firstname = firstname;
	m_surname = surname;
	m_email = email;
	m_username = username;
	m_password = password;
}

Account::~Account()
{
}

