#pragma once
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <filesystem>
#include <fstream>
#include <string>
#include <memory>
#include <crow.h>
#include <sqlite_orm/sqlite_orm.h>
#include "utils.h"
namespace sql = sqlite_orm;
class User
{
public:
	User() = default;
	User(std::string username = "", std::string password = "", uint8_t matchesPlayed = 0, uint8_t level = 0);
	~User();
	friend inline auto createStorageUser(const std::string& filename);
	std::string getUsername() const { return m_username; }
	std::string getPassword() const { return m_password; }

private:
	uint8_t id;
	std::string m_username;
	std::string m_password;
	uint8_t m_matchesPlayed;
	uint8_t m_level;
};

inline auto createStorageUser(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table
		(
			"Users",
			sql::make_column("id", &User::id, sql::primary_key()),
			sql::make_column("username", &User::m_username),
			sql::make_column("password", &User::m_password),
			sql::make_column("matchesPlayed", &User::m_matchesPlayed),
			sql::make_column("level", &User::m_level)
		)
	);
}
using UsereStorage = decltype(createStorageUser(""));
class LoginHandler
{
	std::string username;
	std::string password;
public:
	crow::response operator() (const crow::request& req, UsereStorage db) const;

};
class RegisterHandler
{
	std::string username;
	std::string password;
public:
	crow::response operator() (const crow::request& req, UsereStorage db) const;
};
