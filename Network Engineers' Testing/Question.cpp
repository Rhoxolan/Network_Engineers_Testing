#include "Question.h"

std::string test::Question::GetQuestion() const
{
	return question;
}

std::string test::Question::GetAnswer() const
{
	return answer;
}

std::vector<std::string> test::Question::GetBadAnswers() const
{
	return bad_answer;
}