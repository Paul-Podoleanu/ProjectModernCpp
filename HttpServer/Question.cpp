#include "Question.h"
void populateStorage(Storage& storage)
{
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
			storage.insert(a);
		}
		else
		{
			std::string correctAnswer;
			std::getline(fin, correctAnswer);
			QuestionNumeric a(question, std::stof(correctAnswer));
			storage.insert(a);
		}
	}
}