#pragma once
#include <string>
struct QuestionABCD
{
	int id;
	std::string m_question;
	std::string m_answerA;
	std::string m_answerB;
	std::string m_answerC;
	std::string m_answerD;
	std::string m_correctAnswer;
	QuestionABCD() = default;
	QuestionABCD(std::string question, std::string answerA, std::string answerB, std::string answerC, std::string answerD, std::string correctAnswer);
};