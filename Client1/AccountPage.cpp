#include "AccountPage.h"


void AccountPage::displayUsername()
{
	std::string username;
	auto response = cpr::Get(
		cpr::Url{ "http://localhost:18080/login" },
		cpr::Body{ "username=" + username }
	);

	QString qUsername(username.c_str());
	ui.usernameEdit->setText(qUsername);
}

AccountPage::AccountPage(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	displayUsername();
}

AccountPage::~AccountPage()
{}
