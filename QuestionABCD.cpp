#include "QuestionABCD.h"

QuestionABCD::QuestionABCD(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, std::string correctAnswer) :m_question(question), m_answerA(answerA), m_answerB(answerB), m_answerC(answerC), m_answerD(answerD), m_correctAnswer(correctAnswer)
{
}
std::string QuestionABCD::getQuestion() const
{
	return m_question;
}
std::string QuestionABCD::getAnswerA() const
{
	return m_answerA;
}
std::string QuestionABCD::getAnswerB() const
{
	return m_answerB;
}
std::string QuestionABCD::getAnswerC() const
{
	return	m_answerC;
}
std::string QuestionABCD::getAnswerD() const
{
	return	m_answerD;
}
std::string QuestionABCD::getCorrectAnswer() const
{
	return m_correctAnswer;
}

void QuestionABCD::setQuestion(std::string question)
{
	m_question = question;
}

void QuestionABCD::setAnswerA(std::string answerA)
{
	m_answerA = answerA;
}

void QuestionABCD::setAnswerB(std::string answerB)
{
	m_answerB = answerB;
}

void QuestionABCD::setAnswerC(std::string answerC)
{
	m_answerC = answerC;
}

void QuestionABCD::setAnswerD(std::string answerD)
{
	m_answerD = answerD;
}

void QuestionABCD::setCorrectAnswer(std::string correctAnswer)
{
	m_correctAnswer = correctAnswer;
}

QuestionABCD::~QuestionABCD()
{
}

