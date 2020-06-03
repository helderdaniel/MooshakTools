/**
 * Gather information from submission to a Mooshak contest
 *
 * hdaniel@ualg.pt
 * 24th May 2020
 *
 * call with:
 *
 * submissions <contest folder> <All | A | AF> <yes|*> <filter> [ -cxxxx | -n]
 *
 * eg.:  submissions contests/POO1920/ AF yes fugaf
 *
 * 1st argument is the contest folder, eg:
 *	/home/mooshak/data/contests/SO1920
 *
 * 2nd argument can be:
 *	All	list all submissions
 *	A	list only Accepted submissions
 *	AF	list only Accepted and Final submissions
 *
 *  List formatted as sample below and sorted alphabetically:
 *
 *  A,12335,Accepted
 *  A,23456,Accepted
 *  A,23456,{Wrong Answer}
 *  B,13456,Accepted
 *  (...)
 *
 *  3rd argument allows Team name fixing and can be:
 *	yes					perform team names substitution
 *	<anything else>     does nothing
 *
 *		basic fixing is just removing leading 'a' in student number
 *		defined fixing allows changing Team names
 *
 * 4th argument is optional and can be:
 *	-c      count submissions for each problem
 *
 *	Following need All to get info from all submissions:
 *	-cfu    count failed submissions for each user and each problem
 *	-cfp    count failed submissions for each problem
 *	-cfug   count failed submissions for each user and each problem grouped
 *	-cfpg   count failed submissions for each problem grouped
 *	-cfugaf count failed submissions for each problem grouped, ONLY for who have Accept Final
 *
 *	Faillures tracked are the ones below, others are ignored
 *		{Runtime Error}
 *		{Wrong Answer}
 *		Evaluating
 *		{Time Limit Exceeded}
 *
 */

#include <iostream>
#include "src/Contest.hpp"

int main(int argc, char** argv) {
//std::string input="input";
//std::string output="output";
/*
	if (argc != 3 && argc != 5) {
		std::cout << "Usage: evaluate <path to executable> <path to root of tests> "
					 "[<input fname regex=input> <output fname regex=output>]";
		return 0;
	}
	if (argc == 5) {
		input=argv[3];
		output=argv[4];
	}
*/

	Contest contest("../test/samples/contests/POO1920", true);
	std::cout << contest.AcceptedFinal();

	std::cout << str << std::endl;
	return 0;
}
