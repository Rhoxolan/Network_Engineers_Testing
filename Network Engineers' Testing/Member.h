#pragma once
#include <string>
#include <vector>
#include <cstddef>

class IMember
{
public:
	virtual void Set(std::string _login, std::string _password, std::string _full_name) = 0;

	virtual void SetLogin(std::string _login) = 0;

	virtual void SetPassword(std::string _password) = 0;

	virtual void SetFullName(std::string _full_name) = 0;

	virtual void SetResult(std::vector<std::string> _result) = 0;

	virtual void AddResult(std::string _result) = 0;

	virtual std::string GetLogin() = 0;

	virtual std::string GetPassword() = 0;

	virtual std::string GetFullName() = 0;

	virtual std::size_t GetMemberID() = 0;

	virtual std::vector<std::string> GetResult() = 0;

	~IMember() = default;

};

class Administrator : public IMember
{
	std::string login;
	std::string password;
	std::string full_name;
	std::vector<std::string> result;
	std::size_t MemberID;
public:
	Administrator() = default;

	Administrator(std::string _login, std::string _password, std::string _full_name, std::size_t _MemberID) : login{ _login },
		password{ _password }, full_name{ _full_name }, MemberID{ _MemberID } {}

	void Set(std::string _login, std::string _password, std::string _full_name);

	void SetLogin(std::string _login);

	void SetPassword(std::string _password);

	void SetFullName(std::string _full_name);

	void SetResult(std::vector<std::string> _result);

	void AddResult(std::string _result);

	std::string GetLogin();

	std::string GetPassword();

	std::string GetFullName();

	std::size_t GetMemberID();

	std::vector<std::string> GetResult();

};

class Student : public IMember
{
	std::string login;
	std::string password;
	std::string full_name;
	std::vector<std::string> result;
	std::size_t MemberID;
public:
	Student() = default;

	Student(std::string _login, std::string _password, std::string _full_name, std::size_t _MemberID) : login{ _login },
		password{ _password }, full_name{ _full_name }, MemberID{ _MemberID } {}

	void Set(std::string _login, std::string _password, std::string _full_name);

	void SetLogin(std::string _login);

	void SetPassword(std::string _password);

	void SetFullName(std::string _full_name);

	void SetResult(std::vector<std::string> _result);

	void AddResult(std::string _result);

	std::string GetLogin();

	std::string GetPassword();

	std::string GetFullName();

	std::size_t GetMemberID();

	std::vector<std::string> GetResult();

};
