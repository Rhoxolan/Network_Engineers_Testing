#pragma once
#include "MyHeader.h"
#include "Functions.h"
#include "Member.h"
#include "Question.h"
#include "TestFunctions.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>
#include <typeinfo>
#include <array>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>
#include <cstddef>
#include <limits>
#include <conio.h>

class InitialMenu
{
	std::vector<std::unique_ptr<IMember>>& member;
	std::size_t& MemberID;
private:
	std::size_t CreateMemberID();

	const std::type_info& Registration();

	const std::type_info& SignIn();

public:
	InitialMenu(std::vector<std::unique_ptr<IMember>>& _member, size_t& _MemberID) : member{ _member },
		MemberID{ _MemberID } {}

	const std::type_info& operator()();

};

class AdministratorMenu
{
	std::vector<std::unique_ptr<IMember>>& member;
private:
	void ShowMembers();

	void RedactingTheFullName();

	void RedactingTheLogin();

	void DeleteUser();

	void ShowStatistics();

	void ResetTheUserPassword();

	void ChangeAdminLogNPass();

	void ShowAllMembers();

public:
	AdministratorMenu(std::vector<std::unique_ptr<IMember>>& _member) : member{ _member } {}

	void operator()();

};

class StudentMenu
{
	std::array<test::Question, test::size> FirstTest = test::FirstTestLoader();
	std::array<test::Question, test::size> SecondTest = test::SecondTestLoader();
	std::array<test::Question, test::size> ThirdTest = test::ThirdTestLoader();
	std::vector<std::unique_ptr<IMember>>& member;
	std::size_t& MemberID;
private:
	bool testing(const test::Question& question, int& score, int& number);

	void after_test(int& score, int layer);

	void Test();

	void ShowResult();

	void ChangePassword();

public:
	StudentMenu(std::vector<std::unique_ptr<IMember>>& _member, size_t& _MemberID) : member{ _member },
		MemberID{ _MemberID } {}

	void operator()();

};
