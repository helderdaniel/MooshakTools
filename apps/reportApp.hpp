/**
 * add report to mooshak submission folder
 *
 * hdaniel@ualg.pt
 * 17th May 2020
 *
 * call with:
 *
 * evaluate <path to executable> <path to root of tests> [<input fname regex=input> <output fname regex=output>]
 *
 *
 */

#ifndef MOOSHAKTOOLS_REPORTAPP_H
#define MOOSHAKTOOLS_REPORTAPP_H

#include <iostream>
#include "file/File.hpp"
//#include "src/Evaluate.hpp"

//using mooshak::Evaluate;
using had::File;

//app main function.
//called form *.cpp stub
int repmain(int argc, char* argv[], istream& in, ostream& out) {
/*
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
*/
	//const std::string path = "/storage/OneDrive-ualg/00-ongoing/CodePlagiarism/analysis-sample2.POO1920/All";
	const std::string path = "/storage/OneDrive-ualg/00-ongoing/CodePlagiarism/analysis-sample1.SO1920/All";
	const std::vector v = File::search(path, "(.*).zip");

	int countpk=0;
	int count34=0;
	for (const auto& f : v) {
		char head[5] = { 0, 0, 0, 0 };
		ifstream zip(f.c_str(), ifstream::binary);
		zip.getline(head, 5);
		out << (int) head[2] << (int) head[3] << " " << f.c_str() << '\n';
		if (head[0] == 'P'  && head[1] == 'K') countpk++;
		if (head[2] == 3 && head[3] == 4) count34++;
		zip.close();
	}

	out << v.size()
		<< "," << countpk
		<< "," << count34
		<< std::endl;

	return 0;
}

#endif //MOOSHAKTOOLS_REPORTAPP_H
