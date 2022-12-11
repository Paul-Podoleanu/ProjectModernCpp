#include "AccountPage.h"

void AccountPage::displayUsername()
{
	std::string username;
	auto response = cpr::Post(
		cpr::Url{ "http://localhost:18080/login" },
		cpr::Body{ "username=" + username }
	);
	QString qUsername = QString::fromStdString(username);
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
