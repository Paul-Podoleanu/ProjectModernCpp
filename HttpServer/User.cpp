#include "User.h"

User::User(std::string username, std::string password, uint8_t matchesPlayed, uint8_t level) : m_username(username), m_password(password), m_matchesPlayed(matchesPlayed), m_level(level)
{
	id = -1;
}

User::~User()
{
}

crow::response LoginHandler::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto password = urlArgs["password"];
	for (auto user : db.iterate<User>())
	{
		if (user.getUsername() == username)
		{
			if (user.getPassword() == password)
			{
				return crow::response(200);
			}
			else
			{
				return crow::response(401, "Wrong password");
			}
		}
	}

	return crow::response(401, "User not found");

}

crow::response RegisterHandler::operator()(const crow::request& req) const
{
	auto urlArgs = parseUrlArgs(req.body);
	auto username = urlArgs["username"];
	auto password = urlArgs["password"];
	for (auto user : db.iterate<User>())
	{
		if (user.getUsername() == username)
		{
			return crow::response(401, "User already exists");
		}
	}
	db.insert(User(username, password));
	return crow::response(200);
}

LoginHandler::LoginHandler(UsersStorage& db) :db(db)
{
}

RegisterHandler::RegisterHandler(UsersStorage& db) :db(db)
{
}
