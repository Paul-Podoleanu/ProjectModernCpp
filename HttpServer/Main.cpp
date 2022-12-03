#include <iostream>
#include <fstream>
#include "User.h"
#include"Question.h"
namespace sql = sqlite_orm;

int main()
{
	const std::string db_file_user = "users.sqlite";
	const std::string db_file = "questions.sqlite";
	Storage db = createStorage(db_file);
	UsereStorage dbUser = createStorageUser(db_file_user);
	dbUser.sync_schema();
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
	CROW_ROUTE(app, "/addusers")([&dbUser](const crow::request& req)
		{
			std::string username = req.url_params.get("username");
			std::string password = req.url_params.get("password");
			if (username.empty() || password.empty())
			{
				return crow::response(400);
			}
			else
			{
				dbUser.insert(User{ username, password });
				return crow::response(200);
			}
		});

	app.port(8080).multithreaded().run();
	return 0;
}

