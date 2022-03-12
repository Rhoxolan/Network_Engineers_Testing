#pragma once
#include <vector>
#include <string>

namespace test
{
	class Question
	{
		std::string question;
		std::string answer;
		std::vector<std::string> bad_answer;
	public:
		Question() = default;

		Question(std::string _question, std::string _answer, std::vector<std::string> _bad_answer)
			: question{ _question }, answer{ _answer }, bad_answer{ _bad_answer } {}

		std::string GetQuestion() const;

		std::string GetAnswer() const;

		std::vector<std::string> GetBadAnswers() const;

	};
}