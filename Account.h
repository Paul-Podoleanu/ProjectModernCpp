#pragma once
#include <string>
class Account
{
public:
	Account();
	Account(std::string firstname, std::string surname, std::string email, std::string username, std::string password);
	void setFirstname(std::string firstname) { m_firstname = firstname; }
	void setSurname(std::string surname) { m_surname = surname; }
	void setEmail(std::string email) { m_email = email; }
	void setUsername(std::string username) { m_username = username; }
	void setPassword(std::string password) { m_password = password; }
	
	std::string getFirstname() { return m_firstname; }
	std::string getSurname() { return m_surname; }
	std::string getEmail() { return m_email; }
	std::string getUsername() { return m_username; }
	std::string getPassword() { return m_password; }
	
	~Account();
	
private:
	std::string m_firstname;
	std::string m_surname;
	std::string m_email;
	std::string m_username;
	std::string m_password;
};

