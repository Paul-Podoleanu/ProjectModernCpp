#include "Play.h"
#include <qcolor.h>
#include <qmessagebox.h>

Play::Play(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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