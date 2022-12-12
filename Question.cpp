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
	//std::cout << m_QuestionsWithVariants.size() << ' ' << m_QuestionWithNumericAnswer.size()<<std::endl;
}
void Question::writeQuestionWithVar()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<>dis(0, m_QuestionsWithVariants.size() - 1);
	std::cout << m_QuestionsWithVariants[dis(g)];

}
void Question::writeQuestionWithNumeric()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::uniform_int_distribution<>dis(0, m_QuestionWithNumericAnswer.size() - 1);
	std::cout << m_QuestionWithNumericAnswer[dis(g)];
}

QuestionABCD Question::getRandomQuestionWithVariants()
{
	int k=rand()%m_QuestionsWithVariants.size();
	return m_QuestionsWithVariants[k];
}

QuestionNumeric Question::getRandomQuestionWithNumericAnswer()
{
	int k = rand() % m_QuestionWithNumericAnswer.size();
	return m_QuestionWithNumericAnswer[k];

}

int Question::getNumberQVar()
{
	return m_QuestionsWithVariants.size();
}
