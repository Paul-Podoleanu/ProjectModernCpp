#include "Game.h"
#include <qgridlayout.h>
#include <qpushbutton.h>
#include <qdebug.h>
#include <qmessagebox.h>

Game::Game(QWidget* parent, int rows, int columns)
	: QMainWindow(parent)
{
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

}
Game::~Game()
{}

void Game::on_button_clicked()
{
	//Textul de la regiuni este Qstring, trebuie atribuit unui string normal pentru cpr::Body
	//QString region = ((QPushButton*)sender())->text();
	QPushButton* button = qobject_cast<QPushButton*>(sender());
	std::string regionText = button->text().toUtf8().constData();
	
	//QPushButton* button = qobject_cast<QPushButton*>(sender());
	auto r = cpr::Put(cpr::Url{ "http://localhost:18080/clickRegion" },
		cpr::Body{ "region" + regionText }
	);
	if (r.status_code == 200)
	{
		Play* PlayPage = new Play();
		PlayPage->resize(800, 600);
		PlayPage->show();
		QMessageBox::information(this, "Button clicked", button->text());
	}
	else
	{
		QMessageBox::information(this, "Error", "Cant open");
	}

	
	
}


