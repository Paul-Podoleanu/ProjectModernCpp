#include "Play.h"
#include <qcolor.h>

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
	//ui.AnswerA->setStyleSheet(b);
	QColor col = QColor(Qt::red);
	QString qss = QString("background-color: %1").arg(col.name());
	ui.AnswerA->setStyleSheet(qss);
	ui.Question->setFont(QFont("Helvetica", 10, QFont::Bold, QFont::Capitalize));
}

Play::~Play()
{
}
