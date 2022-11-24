#include "AccountManager.h"

AccountManager::AccountManager()
{
}

AccountManager::AccountManager(std::vector<Account> users) : m_users(users)
{
}

void AccountManager::addAccount(Account account)
{
	m_users.push_back(account);
}

void AccountManager::removeAccount(Account account)
{
	m_users.erase(std::remove(m_users.begin(), m_users.end(), account), m_users.end());
}
