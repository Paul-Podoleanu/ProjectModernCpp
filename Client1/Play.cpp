#include "Play.h"
#include <qcolor.h>
#include <qmessagebox.h>
#include <qtimer.h>

Play::Play(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//trebuie adaugata conditie in caz ca e ABCD sau Numeric
	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(100);
	ui.progressBar->setValue(100);
	ui.progressBar->setFormat("");
	connect(timer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
	ui.progressBar->setStyleSheet("QProgressBar {border: 2px solid grey;border-radius: 5px;text-align: center;}");
	connect(timer, SIGNAL(timeout()), this, SLOT(close1()));
	auto responseQuestion = cpr::Get(cpr::Url{ "http://localhost:18080/randomABCDQuestion" });
	auto questionRow = crow::json::load(responseQuestion.text);
	std::string question = questionRow["question"].s();
	ui.Question->setText(question.c_str());
	std::string answerA = questionRow["answerA"].s();
	ui.AnswerA->setText(answerA.c_str());
	std::string answerB = questionRow["answerB"].s();
	ui.AnswerB->setText(answerB.c_str());
	std::string answerC = questionRow["answerC"].s();
	ui.AnswerC->setText(answerC.c_str());
	std::string answerD = questionRow["answerD"].s();
	ui.AnswerD->setText(answerD.c_str());
	ui.Question->setFont(QFont("Helvetica", 10, QFont::Bold, QFont::Capitalize));
	correctAnswer = questionRow["correctAnswer"].s();
	QDebug(QtMsgType::QtInfoMsg) << correctAnswer.c_str();
	//pentru numeric questions
	//auto responseNumericQuestion = cpr::Get(cpr::Url{ "http://localhost:18080/randomNumericQuestion" });
	//auto numericQuestionRow = crow::json::load(responseNumericQuestion.text);
	//std::string numericQuestion = numericQuestionRow["question"].s();
	//ui.Question->setText(numericQuestion.c_str());
	//std::string numericAnswer = numericQuestionRow["answer"].s();
	//correctAnswer = numericQuestionRow["correctAnswer"].s();
	//QDebug(QtMsgType::QtInfoMsg) << correctAnswer.c_str();
}

Play::~Play()
{
}
void Play::on_AnswerA_clicked()
{
	if (ui.AnswerA->text().toUtf8().constData() == correctAnswer)
	{
		QMessageBox::information(this, "Correct", "Correct");
	}
	else
	{
		QMessageBox::information(this, "Incorrect", "Incorrect");
	}
}

void Play::on_AnswerB_clicked()
{
	if (ui.AnswerB->text().toUtf8().constData() == correctAnswer)
	{
		QMessageBox::information(this, "Correct", "Correct");
	}
	else
	{
		QMessageBox::information(this, "Incorrect", "Incorrect");
	}
}
void Play::on_AnswerC_clicked()
{
	if (ui.AnswerC->text().toUtf8().constData() == correctAnswer)
	{
		QMessageBox::information(this, "Correct", "Correct");
	}
	else
	{
		QMessageBox::information(this, "Incorrect", "Incorrect");
	}

}
void Play::on_AnswerD_clicked()
{
	if (ui.AnswerD->text().toUtf8().constData() == correctAnswer)
	{
		QMessageBox::information(this, "Correct", "Correct");
	}
	else
	{
		QMessageBox::information(this, "Incorrect", "Incorrect");
	}

}

void Play::updateProgressBar()
{
	if (ui.progressBar->value() > 0)
	{
		ui.progressBar->setValue(ui.progressBar->value() - 1);
	}
}
void Play::close1()
{
	if (ui.progressBar->value() == 0)
	{
		this->close();
	}
}
void Play::on_AvantajJumatate_clicked()
{
	int random = rand() % 4;
	int random2 = rand() % 4;
	while (random == random2)
	{
		random2 = rand() % 4;
	}
	int contor = 0;
	if (okAvantajJumatate == true)
	{
		QMessageBox::information(this, "You already used this advantage", "You already used this advantage");
	}
	else {
		while (contor != 2 && okAvantajJumatate == false) {
			if (random == 0 || random2 == 0)
			{
				if (ui.AnswerA->text().toUtf8().constData() != correctAnswer)
				{
					ui.AnswerA->setDisabled(true);
					ui.AnswerA->hide();
					contor++;
				}
			}
			if (random == 1 || random2 == 1)
			{
				if (ui.AnswerB->text().toUtf8().constData() != correctAnswer)
				{
					ui.AnswerB->setDisabled(true);
					ui.AnswerB->hide();
					contor++;
				}
			}
			if (random == 2 || random2 == 2)
			{
				if (ui.AnswerC->text().toUtf8().constData() != correctAnswer)
				{
					ui.AnswerC->setDisabled(true);
					ui.AnswerC->hide();
					contor++;
				}
			}
			if (random == 3 || random2 == 3)
			{
				if (ui.AnswerD->text().toUtf8().constData() != correctAnswer)
				{
					ui.AnswerD->setDisabled(true);
					ui.AnswerD->hide();
					contor++;
				}
			}
		}
	}
	if (okAvantajJumatate == true)
	{
		QMessageBox::information(this, "You already used this advantage", "You already used this advantage");
	}
	okAvantajJumatate = true;
}
void Play::on_AvantajAlegereRaspuns_clicked()
{

	int contor2 = 0;
	if (okAvantajAlegere == true)
	{
		QMessageBox::information(this, "You already used this advantage", "You already used this advantage");
	}
	else {
		if (okAvantajAlegere == false && contor2 == 0)
		{
			auto responseAnswer = cpr::Get(cpr::Url{ "http://localhost:18080/getAnswer" });
			auto answerRow = crow::json::load(responseAnswer.text);
			std::string answer = answerRow["answer"].s();
			QMessageBox::information(this, "Answer", answer.c_str());
		}
		contor2++;
	}
}
void Play::on_AvantajSugestieRaspuns_clicked()
{
	int contor3 = 0;
	if (okAvantajSugestie == true)
	{
		QMessageBox::information(this, "You already used this advantage", "You already used this advantage");
	}
	else {
		if (okAvantajSugestie == false && contor3 == 0)
		{
			auto responseSuggestion = cpr::Get(cpr::Url{ "http://localhost:18080/getSuggestion" });
			auto suggestionRow = crow::json::load(responseSuggestion.text);
			std::string suggestion = suggestionRow["suggestion"].s();
			QMessageBox::information(this, "Suggestion", suggestion.c_str());
		}
		contor3++;
	}
}
//void Play::on_NumericAnswer_typed()
//{
//	if (ui.numericAnswer->text().toUtf8().constData() == correctAnswer)
//	{
//		QMessageBox::information(this, "Correct", "Correct");
//	}
//	else
//	{
//		QMessageBox::information(this, "Incorrect", "Incorrect");
//	}
//}
//

