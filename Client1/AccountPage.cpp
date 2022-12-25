#include "AccountPage.h"


void AccountPage::displayUsername()
{
	auto responseAccount = cpr::Get(cpr::Url{ "http://localhost:18080/Account" });
	auto AccountRow = crow::json::load(responseAccount.text);
	std::string username = AccountRow["username"].s();
	ui.usernameEdit->setText(username.c_str());
	std::string matchesPlayed = AccountRow["matchesPlayed"].s();
	ui.matchesPlayedEdit->setText(matchesPlayed.c_str());
}

AccountPage::AccountPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	displayUsername();
}

AccountPage::~AccountPage()
{}
