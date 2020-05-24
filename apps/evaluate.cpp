/**
 * Evaluate executable like Mooshak
 *
 * hdaniel@ualg.pt
 * 24th May 2020
 */

#include <iostream>
#include "../src/MooshakEval.hpp"

int main(int argc, char** argv) {
std::string input="input";
std::string output="output";

	if (argc != 3 && argc != 5) {
		std::cout << "Usage: evaluate <path to executable> <path to root of tests> "
					 "[<input fname regex=input> <output fname regex=output>]";
		return 0;
	}
	if (argc == 5) {
		input=argv[3];
		output=argv[4];
	}

	MooshakEval eval(argv[1], argv[2], input, output);
	std::cout << eval.run();
	return 0;
}
