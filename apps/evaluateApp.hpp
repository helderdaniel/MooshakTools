/**
 * Perform mooshak like evaluation tests.
 *
 * hdaniel@ualg.pt
 * 24th May 2020
 *
 * call with:
 *
 * evaluate <path to executable> <path to root of tests> [<input fname regex=input> <output fname regex=output>]
 *
 * <path to executable>		executable or script to be evaluated
 * <path to root of tests>  root folder to search for test files
 * <input fname regex>		input test file name regex. By default "input"
 * <output fname regex>		output test file name regex. By default "output"
 *
 * Last 2 parameters are optional by group: pass them both or none!
 *
 * Outputs a line for each test, in the form:
 * <executable> < <input filename>
 *
 * If any differences between <executable> output and <expected output> shows them as:
 * Expected:
 * (...)
 * Actual:
 * (...)
 *
 * Example:
 *
 * $> ./evaluate ../test/samples/apps/conv  ../test/samples/tests input output
 *
 *	  ../test/samples/apps/conv < ../test/samples/tests/T0/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T1/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T2/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T3/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T3forceerror/input
 *	  Expected:
 *	  2.00
 *	  5.00
 *	  10.00
 *	  8.00
 *	  7.00
 *	  3.00
 *	  Actual:
 *	  2.00
 *	  5.00
 *	  10.00
 *	  8.00
 *	  8.00
 *	  3.00
 *	  ../test/samples/apps/conv < ../test/samples/tests/T4/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T5/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T6/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T7/input
 *	  ../test/samples/apps/conv < ../test/samples/tests/T8/input
 */

#ifndef MOOSHAKTOOLS_MOOSHAKEVALAPP_H
#define MOOSHAKTOOLS_MOOSHAKEVALAPP_H

#include <iostream>
#include "src/Evaluate.hpp"

using mooshak::Evaluate;

//app main function.
//called form *.cpp stub
int evalmain(int argc, char* argv[], istream& in, ostream& out) {
std::string input="input";
std::string output="output";

	if (argc != 3 && argc != 5) {
		out << "Usage: evaluate <path to executable> <path to root of tests> "
					 "[<input fname regex=input> <output fname regex=output>]\n";
		return 0;
	}
	if (argc == 5) {
		input=argv[3];
		output=argv[4];
	}

	Evaluate eval(argv[1], argv[2], input, output);
	out << eval.run();
	return 0;
}

#endif //MOOSHAKTOOLS_MOOSHAKEVALAPP_H
