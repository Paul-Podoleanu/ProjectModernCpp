#pragma once
#include <string>
struct QuestionNumeric
{
	int id;
	std::string m_question;
	float m_correctAnswer;
	QuestionNumeric() = default;
	QuestionNumeric(std::string question, float correctAnswer);
};