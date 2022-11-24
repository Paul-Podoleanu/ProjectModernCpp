#pragma once
#include <vector>
#include "Account.h"
class AccountManager
{
public:
	AccountManager();
	AccountManager(std::vector<Account> users);
	void addAccount(Account account);
	void removeAccount(Account account);
	
private:
	std::vector<Account> m_users;
};

