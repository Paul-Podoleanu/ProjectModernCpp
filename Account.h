#pragma once
#include <string>
class Account
{
private:
	std::string m_firstname;
	std::string m_surname;
	std::string m_email;
	std::string m_username;
	std::string m_password;
public:
	Account();
	Account(std::string firstname, std::string surname, std::string email, std::string username, std::string password);
	~Account();
};

