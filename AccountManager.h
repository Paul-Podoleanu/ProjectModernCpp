#pragma once
#include <vector>
#include "Account.h"
class AccountManager
{
private:
	AccountManager();
	std::vector<Account> m_users;
public:
	void addAccount(Account account);
	void removeAccount(Account account);
};

