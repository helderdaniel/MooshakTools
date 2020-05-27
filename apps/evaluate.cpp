/**
 * Perform mooshak like evaluation tests.
 *
 * hdaniel@ualg.pt
 * 24th May 2020
 *
 * call with:
 *
 * evaluate <path to executable> <path to root of tests>
 * [<input fname regex=input> <output fname regex=output>]
 *
 * <path to executable>		executable or script to be evaluated
 * <path to root of tests>  root folder to search for test files
 * <input fname regex>		input test file name regex. By default "input"
 * <output fname regex>		output test file name regex. By default "output"
 * Last 2 parameters are optional by group: pass them both or none!
 */

#include <iostream>
#include "src/Evaluate.hpp"

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

	Evaluate eval(argv[1], argv[2], input, output);
	std::cout << eval.run();
	return 0;
}
