#include "Question.h"


void Question::addQuestion()
{
	//read the questions from file and answers and add them to the vector
	std::string last_answer;
	bool ok = 1;
	std::ifstream fin("Questions.txt");
	while (!fin.eof())
	{
		std::string question;
		std::getline(fin, question);
		if (question[0] == 'Q' && question[1] == ':')
		{
			question = question.substr(2, question.size() - 2);
			std::string answerA, answerB, answerC, answerD, correctAnswer;
			std::getline(fin, correctAnswer);
			std::getline(fin, answerA);
			std::getline(fin, answerB);
			std::getline(fin, answerC);
			std::getline(fin, answerD);
			QuestionABCD a(question, answerA, answerB, answerC, answerD, correctAnswer);
			m_QuestionsWithVariants.push_back(a);
		}
		else
		{
			std::string correctAnswer;
			std::getline(fin, correctAnswer);
			QuestionNumeric a(question, std::stoi(correctAnswer));
			m_QuestionWithNumericAnswer.push_back(a);
		}
	}
}