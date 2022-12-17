#include <iostream>
#include <fstream>
#include"Question.h"
#include "User.h"
namespace sql = sqlite_orm;
int main()
{

	const std::string db_file = "questions.sqlite";
	const std::string db_file_user = "users.sqlite";
	Storage db = createStorage(db_file);
	UsersStorage dbUser = createStorageUser(db_file_user);
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
	CROW_ROUTE(app, "/questionsABCD")([&db]() {
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
	CROW_ROUTE(app, "/questionsNumeric")([&db]()
		{

			std::vector<crow::json::wvalue> question_json;
			for (const auto& questionNumeric : db.iterate<QuestionNumeric>())
			{
				question_json.push_back(crow::json::wvalue{
					{"id", questionNumeric.id},
					{"question", questionNumeric.m_question},
					{"correctAnswer", questionNumeric.m_correctAnswer}
					});
			}
			return crow::json::wvalue{ question_json };
		});

	auto& addUser = CROW_ROUTE(app, "/register").methods(crow::HTTPMethod::PUT);
	addUser(RegisterHandler(dbUser));
	auto& searchUser = CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST);
	searchUser(LoginHandler(dbUser));
	CROW_ROUTE(app, "/randomABCDQuestion")([&db]() {
		using namespace sqlite_orm;
		auto rows = db.select(sql::columns(&QuestionABCD::id, &QuestionABCD::m_question, &QuestionABCD::m_correctAnswer, &QuestionABCD::m_answerA, &QuestionABCD::m_answerB, &QuestionABCD::m_answerC, &QuestionABCD::m_answerD),
			sql::where(sql::c(&QuestionABCD::id) == 1));
		const auto& [id, question, m_correctAnswer, m_answerA, m_answerB, m_answerC, m_answerD] = rows[0];
		crow::json::wvalue q
		{
			{"id", id},
			{"question",question},
			{"correctAnswer",m_correctAnswer},
			{"answerA",m_answerA},
			{"answerB",m_answerB},
			{"answerC",m_answerC},
			{"answerD",m_answerD},
		};
		
			return q;
		});
	app.port(18080).multithreaded().run();
	return 0;
}

