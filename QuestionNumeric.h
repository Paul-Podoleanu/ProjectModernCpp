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
	QuestionNumeric();
	//Get
	std::string getQuestion() const;
	int getCorrectAnswer() const;

	//Set
	void setQuestion(std::string question);
	void setCorrectAnswer(int correctAnswer);

	//Overload operator
	friend std::ostream& operator<<(std::ostream& out, const QuestionNumeric& question);
	QuestionNumeric& operator=(const QuestionNumeric& other);

	~QuestionNumeric();
};