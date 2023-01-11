#include "Game.h"
#include <qgridlayout.h>
#include "NumericAnswer.h"
#include "Play.h"
#include <qpushbutton.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include "utils.h"

Game::Game(QWidget* parent, int rows, int columns, std::string username, std::string owner)
	: QMainWindow(parent)
{
	m_owner = owner;
	this->username = username;
	ui.setupUi(this);
	this->resize(1400, 800);
	QGridLayout* layout = new QGridLayout();
	buttons.resize(rows * columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			buttons[i * columns + j] = new QPushButton();
			buttons[i * columns + j]->setMinimumSize(100, 100);
			buttons[i * columns + j]->setStyleSheet("background-color: white");
			buttons[i * columns + j]->setStyleSheet("QPushButton {background-color: white; border: 2px solid black; border-radius: 10px;}");
			buttons[i * columns + j]->setCursor(Qt::PointingHandCursor);
			buttons[i * columns + j]->setText(QString::number(i * columns + j));
			buttons[i * columns + j]->setObjectName(QString::number(i * columns + j));
			layout->addWidget(buttons[i * columns + j], i, j);
			//bring the buttons closer together
			layout->setSpacing(0);
			connect(buttons[i * columns + j], &QPushButton::clicked, this, &Game::on_button_clicked);
		}
		//create a new row in the grid layout
		layout->setRowStretch(i, 1);
	}
	this->centralWidget()->setLayout(layout);
	layout->setGeometry(QRect(0, 0, 1400, 800));
	layout->setAlignment(Qt::AlignCenter);
	players();
}
Game::~Game()
{}
void Game::players()
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:18080/players" },
		cpr::Body{ "&username=" + m_owner });
	std::string response = r.text;
	std::vector<std::string> players = split(response, ",");
	ui.Player1->setText(players[0].c_str());
	ui.Player2->setText(players[1].c_str());
	if (players[3] != "*")
	{
		ui.Player3->setText(players[2].c_str());
		ui.Player4->setText(players[3].c_str());

	}
	else if (players[2] == "*")
	{
		ui.Player3->setVisible(false);
		ui.Player4->setVisible(false);
	}
	else if (players[3] == "*")
	{
		ui.Player3->setText(players[2].c_str());
		ui.Player4->setVisible(false);
	}
}
void Game::on_button_clicked()
{
	//Textul de la regiuni este Qstring, trebuie atribuit unui string normal pentru cpr::Body
	//QString region = ((QPushButton*)sender())->text();
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	int index = button->objectName().toInt();
	NumericAnswer* numericAnswer = new NumericAnswer(nullptr, username);
	numericAnswer->show();
}


