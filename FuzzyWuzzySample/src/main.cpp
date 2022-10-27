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
			"���",
			"�����Լ�",
			"����˭",
			"�Է�����",
			"������ô��",
			"�����鲻̫��",
			"���벻��д",
			"��ǰ���¹⣬���ǵ���˪",
			"������ɽ�����ƺ��뺣��"
		};
		std::string query = "��ð�������˭��";

		std::vector<std::pair<std::string, int>> results = fuzz::extract(query, choices);

		for (auto& result : results)
		{
			std::string a = std::get<0>(result);
			int score = std::get<1>(result);
			std::cout << a << "\t" << score << std::endl;
		}
	}
}
