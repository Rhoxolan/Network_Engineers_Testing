#pragma once
#include "Question.h"
#include "Questions.cpp"
#include <array>

namespace test
{
	constexpr auto size = 10;

	std::array<test::Question, test::size> FirstTestLoader();

	std::array<test::Question, test::size> SecondTestLoader();

	std::array<test::Question, test::size> ThirdTestLoader();
}
