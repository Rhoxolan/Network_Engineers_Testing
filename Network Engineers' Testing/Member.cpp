#include "Member.h"

void Administrator::Set(std::string _login, std::string _password, std::string _full_name)
{
	login = _login;
	password = _password;
	full_name = _full_name;
}

void Administrator::SetLogin(std::string _login)
{
	login = _login;
}

void Administrator::SetPassword(std::string _password)
{
	password = _password;
}

void Administrator::SetFullName(std::string _full_name)
{
	full_name = _full_name;
}

void Administrator::SetResult(std::vector<std::string> _result)
{
	result = _result;
}

void Administrator::AddResult(std::string _result)
{
	result.emplace_back(_result);
}

std::string Administrator::GetLogin()
{
	return login;
}

std::string Administrator::GetPassword()
{
	return password;
}

std::string Administrator::GetFullName()
{
	return full_name;
}

std::size_t Administrator::GetMemberID()
{
	return MemberID;
}

std::vector<std::string> Administrator::GetResult()
{
	return result;
}

void Student::Set(std::string _login, std::string _password, std::string _full_name)
{
	login = _login;
	password = _password;
	full_name = _full_name;
}

void Student::SetLogin(std::string _login)
{
	login = _login;
}

void Student::SetPassword(std::string _password)
{
	password = _password;
}

void Student::SetFullName(std::string _full_name)
{
	full_name = _full_name;
}

void Student::SetResult(std::vector<std::string> _result)
{
	result = _result;
}

void Student::AddResult(std::string _result)
{
	result.emplace_back(_result);
}

std::string Student::GetLogin()
{
	return login;
}

std::string Student::GetPassword()
{
	return password;
}

std::string Student::GetFullName()
{
	return full_name;
}

std::size_t Student::GetMemberID()
{
	return MemberID;
}

std::vector<std::string> Student::GetResult()
{
	return result;
}