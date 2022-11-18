#pragma once
#include <string>
#include <iostream>
class QuestionNumeric
{
private:
	std::string m_question;
	int m_correctAnswer;
public:
	QuestionNumeric(std::string question, int correctAnswer);
	std::string getQuestion() const;
	int getCorrectAnswer() const;
	void setQuestion(std::string question);
	void setCorrectAnswer(int correctAnswer);
	friend std::ostream& operator<<(std::ostream& out, const QuestionNumeric& question);
	~QuestionNumeric();
};