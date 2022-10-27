#include <iostream>

#include "fuzzywuzzy.hpp"
#include "process.hpp"

int main()
{
	const string a = "I'm in your mind", b = "I'm in your mind fuzz";
	const string c = "fuzzy wuzzy was a bear", d = "wuzzy fuzzy was a bear";

	std::cout << fuzz::ratio(a, b) << '\n';
	std::cout << fuzz::partial_ratio(a, b) << '\n';
	std::cout << fuzz::token_sort_ratio(c, d) << '\n';

	std::vector<string> v = { "fuzzy", "wuzzy", "wuzzy", "fuzzy", "fuzzy", " " };
	auto erg = fuzz::dedupe(v);

	std::cout << "=============================================================" << std::endl;
	if (true) {
		std::vector<std::string> choices = {
			"hello",
			"introduction yourself",
			"who you are",
			"how are you",
			"what is the weather?"
		};

		std::string query = "hello, who you are?";

		std::vector<std::pair<std::string, int>> results = fuzz::extract(query, choices);

		for (auto& result : results)
		{
			std::string a = std::get<0>(result);
			int score = std::get<1>(result);
			std::cout << a << "\t" << score << std::endl;
		}
	}
	
	// chinese characters test(not passed!)
	std::cout << "=============================================================" << std::endl;

	if(false) {

		std::vector<std::string> choices = {
			"你好",
			"介绍自己",
			"你是谁",
			"吃饭了吗",
			"天气怎么样",
			"我心情不太好",
			"代码不好写",
			"床前明月光，疑是地上霜",
			"白日依山尽，黄河入海流"
		};
		std::string query = "你好啊，你是谁？";

		std::vector<std::pair<std::string, int>> results = fuzz::extract(query, choices);

		for (auto& result : results)
		{
			std::string a = std::get<0>(result);
			int score = std::get<1>(result);
			std::cout << a << "\t" << score << std::endl;
		}
	}
}
