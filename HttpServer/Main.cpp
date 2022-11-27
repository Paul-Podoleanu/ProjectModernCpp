#include <iostream>
#include <fstream>
#include"Question.h"
namespace sql = sqlite_orm;

int main()
{

	const std::string db_file = "questions.sqlite";
	Storage db = createStorage(db_file);
	db.sync_schema();
	auto initQuestionCounts = db.count<QuestionABCD>();
	auto initQuestionNumeriCount = db.count<QuestionNumeric>();
	if (initQuestionCounts == 0 && initQuestionNumeriCount == 0)
	{
		populateStorage(db);
	}
	crow::SimpleApp app;
	CROW_ROUTE(app, "/")([]() {
		return "This is an example app of crow and sql-orm";
		});
	CROW_ROUTE(app, "/questions")([&db]() {
		std::vector<crow::json::wvalue> question_json;

		for (const auto& questionABCD : db.iterate<QuestionABCD>())
		{
			question_json.push_back(crow::json::wvalue{
				{"id", questionABCD.id},
				{"question", questionABCD.m_question},
				{"answerA", questionABCD.m_answerA},
				{"answerB", questionABCD.m_answerB},
				{"answerC", questionABCD.m_answerC},
				{"answerD", questionABCD.m_answerD},
				{"correctAnswer", questionABCD.m_correctAnswer}
				});
		}
		return crow::json::wvalue{ question_json };
		});

	app.port(8080).multithreaded().run();
	return 0;
}

