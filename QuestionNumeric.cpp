#include "QuestionNumeric.h"

QuestionNumeric::QuestionNumeric(std::string question, int correctAnswer) :m_question(question), m_correctAnswer(correctAnswer)
{
}
QuestionNumeric::~QuestionNumeric()
{
}
int QuestionNumeric::getCorrectAnswer() const
{
	return m_correctAnswer;
}
void QuestionNumeric::setQuestion(std::string question)
{
	m_question = question;
}
void QuestionNumeric::setCorrectAnswer(int correctAnswer)
{
	m_correctAnswer = correctAnswer;
}
std::string QuestionNumeric::getQuestion() const
{
	return m_question;
}
int QuestionNumeric::getCorrectAnswer() const
{
	return m_correctAnswer;
}