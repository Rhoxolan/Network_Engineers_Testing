#include "TestFunctions.h"

std::array<test::Question, test::size> test::FirstTestLoader()
{
	std::array<test::Question, test::size> test1{
	test::Question(one_one, one_one_1, std::vector<std::string>{one_one_0_1, one_one_0_2}),
	{one_two, one_two_1, std::vector<std::string>{one_two_0_1, one_two_0_2}} ,
	{one_three, one_three_1, std::vector<std::string>{one_three_0_1, one_three_0_2, one_three_0_3, one_three_0_4, one_three_0_5}},
	{one_four, one_four_1, std::vector<std::string>{one_four_0_1, one_four_0_2, one_four_0_3}},
	{one_five, one_five_1, std::vector<std::string>{one_five_0_1, one_five_0_2}},
	{one_six, one_six_1, std::vector<std::string>{one_six_0_1, one_six_0_2, one_six_0_3}},
	{one_seven, one_seven_1, std::vector<std::string>{one_seven_0_1, one_seven_0_2, one_seven_0_3}},
	{one_eight, one_eight_1, std::vector<std::string>{one_eight_0_1, one_eight_0_2}},
	{one_nine, one_nine_1, std::vector<std::string>{one_nine_0_1, one_nine_0_2}},
	{one_ten, one_ten_1, std::vector<std::string>{one_ten_0_1, one_ten_0_2}}
	};
	return test1;
}

std::array<test::Question, test::size> test::SecondTestLoader()
{
	std::array<test::Question, test::size> test2{
	test::Question(two_one, two_one_1, std::vector<std::string>{two_one_0_1}),
	{two_two, two_two_1, std::vector<std::string>{two_two_0_1, two_two_0_2}} ,
	{two_three, two_three_1, std::vector<std::string>{two_three_0_1, two_three_0_2, two_three_0_3}},
	{two_four, two_four_1, std::vector<std::string>{two_four_0_1, two_four_0_2, two_four_0_3}},
	{two_five, two_five_1, std::vector<std::string>{two_five_0_1, two_five_0_2}},
	{two_six, two_six_1, std::vector<std::string>{two_six_0_1, two_six_0_2}},
	{two_seven, two_seven_1, std::vector<std::string>{two_seven_0_1, two_seven_0_2, two_seven_0_3}},
	{two_eight, two_eight_1, std::vector<std::string>{two_eight_0_1, two_eight_0_2}},
	{two_nine, two_nine_1, std::vector<std::string>{two_nine_0_1, two_nine_0_2}},
	{two_ten, two_ten_1, std::vector<std::string>{two_ten_0_1, two_ten_0_2}}
	};
	return test2;
}

std::array<test::Question, test::size> test::ThirdTestLoader()
{
	std::array<test::Question, test::size> test3{
	test::Question(three_one, three_one_1, std::vector<std::string>{three_one_0_1, three_one_0_3, three_one_0_3}),
	{three_two, three_two_1, std::vector<std::string>{three_two_0_1, three_two_0_2}} ,
	{three_three, three_three_1, std::vector<std::string>{three_three_0_1, three_three_0_2}},
	{three_four, three_four_1, std::vector<std::string>{three_four_0_1, three_four_0_2}},
	{three_five, three_five_1, std::vector<std::string>{three_five_0_1, three_five_0_2}},
	{three_six, three_six_1, std::vector<std::string>{three_six_0_1, three_six_0_2, three_six_0_3}},
	{three_seven, three_seven_1, std::vector<std::string>{three_seven_0_1, three_seven_0_2}},
	{three_eight, three_eight_1, std::vector<std::string>{three_eight_0_1, three_eight_0_2}},
	{three_nine, three_nine_1, std::vector<std::string>{three_nine_0_1, three_nine_0_2}},
	{three_ten, three_ten_1, std::vector<std::string>{three_ten_0_1, three_ten_0_2}}
	};
	return test3;
}