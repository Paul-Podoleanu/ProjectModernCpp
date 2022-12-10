#include "Registration.h"
#include "MainPage.h"

Registration::Registration(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Registration::~Registration()
{}

void Registration::on_Register_clicked()
{
	std::string username = ui.UsernameInput->text().toUtf8().constData();
	std::string password = ui.PassInput->text().toUtf8().constData();
	auto response = cpr::Put(
		cpr::Url{ "http://localhost:18080/register" },
		cpr::Body{ "username=" + username + "&password=" + password }
	);
	if (response.status_code == 200)
	{
		QMessageBox::information(this, "Success", "Registration successful");
	}
	else
	{
		QMessageBox::information(this, "Error", "Registration failed");
	}
}

void Registration::on_Login_clicked()
{
	std::string username = ui.UsernameInput->text().toUtf8().constData();
	std::string password = ui.PassInput->text().toUtf8().constData();
	auto response = cpr::Post(
		cpr::Url{ "http://localhost:18080/login"},
		cpr::Body{ "username=" + username + "&password=" + password }
	);
	if (response.status_code == 200)
	{
		MainPage* mainPage = new MainPage();
		//mainPage->setWindowState(Qt::WindowMaximized);
		mainPage->show();
	}
	else
	{
		QMessageBox::information(this, "Error", "Login failed");
	}
}