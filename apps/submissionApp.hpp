/**
 * Gather information from submission to a Mooshak contest
 *
 * hdaniel@ualg.pt
 * 15th June 2020
 *
 * call with:
 *
 * submissions <contest path> <operation> [<filter path>]
 *
 * eg.:  submissions contests/POO1920/ AF
 * eg.:  submissions ../test/samples/contests/POO1920  AF  ../test/samples/contests/filterPOO1920.txt
 *
 * 1st argument is the contest folder, eg:
 *	/home/mooshak/data/contests/SO1920
 *
 * 2nd argument is the operation, and can be:
 *	All				list all submissions
 *	Accepted		list only "Accepted" submissions
 *	AcceptedFinal	list only "Accepted" and "final" submissions
 *	Fail			list failed submissions
 *	FailType		list failed submissions grouped by type
 *	AcceptedFailType list failed submissions grouped by type, only if team as one "Accepted" submission to the problem
 *  mapAll  		map counter of all submissions classification for each problem
 *  mapFinal 		map counter of all submissions classification for each problem, marked as "final"
 *
 *  3rd argument is an optional path to a Team filter for name fixing
 *
 *
 *  For operations: "All", "Accepted" and "AcceptedFinal", list is formatted as sample below and sorted alphabetically:
 *  A,12335,Accepted,final
 *  A,23456,Accepted,pending
 *  A,23456,Wrong Answer,pending
 *  B,13456,Accepted,pending
 *  (...)
 *
 *  For operation "Fail" list is formatted as sample below and sorted alphabetically:
 *  A,44340,Runtime Error,1
 *  A,44340,Wrong Answer,2
 *  A,49551,Wrong Answer,1
 *  A,52080,Runtime Error,1
 *  A,52770,Wrong Answer,1
 *  (...)
 *
 *  For operation "FailType" and "AcceptedFailType", list is formatted as sample below and sorted alphabetically:
 *  A,44340,3
 *  A,49551,1
 *  A,52080,1
 *  A,52770,1
 *  (...)
 *
 *  For operation "mapAll" and "mapFinal", map is formatted as sample below:
 *
 *  nofail  *    *              *              *    *
 *  Prob  Acc CTEr Eval InFn InSb MLEx OLEx PErr PSEx REvl RTEr TLEx WrAn Total Fails
 *    A    89   35    0    0    0    0    0    2    0    0   41    0   34   201    75
 *    B   115   19    0    0    0    0    0    4    0    0   55    0   46   239   101
 *    C   139   29    0    0    0    0    0    9    1    0   37    0   57   272    94
 *    D   120   24    0    0    0    0    0    0    0    0   18    0  115   277   133
 *    E    83   87    0    0    0    0    0    0    0    0   13    0   11   194    24
 *    F   119   38    0    0    0    0    0    2    0    0   27    0   26   212    53
 *    G    74   22    0    0    0    0    0    3    0    0    5    0   13   117    18
 *    H    47   38    0    0    0    0    0   13    1    0    4    0   16   119    20
 *
 *
 *	Classifications listed below are the only ones not considered as failure:
 *		Accepted
 *		Compile Time Error
 *		Invalid Submission
 *		Presentation Error
 *		Program Size Exceeded
 *
 */

#ifndef MOOSHAKTOOLS_SUBMISSIONSAPP_H
#define MOOSHAKTOOLS_SUBMISSIONSAPP_H

#include <iostream>
#include "src/SubmissionsInfo.hpp"

using std::string;
using mooshak::SubmissionsInfo;

//app main function.
//called form *.cpp stub
int subsmain(int argc, char* argv[], istream& in, ostream& out) {

	if (argc != 3 && argc != 4) {
		out << "Usage: submissions <contest path> <operation> [<filter path>]\n";
		return 0;
	}

	string contestPath(argv[1]);
	string operation(argv[2]);
	string filterPath;
	if (argc == 4) filterPath = argv[3];

	SubmissionsInfo subs(contestPath, filterPath);

	if (operation == "All")         			out << subs.All();
	else if (operation == "Accepted")      		out << subs.Accepted();
	else if (operation == "AcceptedFinal")  	out << subs.AcceptedFinal();
	else if (operation == "Fail")      			subs.Failed(out);
	else if (operation == "FailType")     		subs.FailedType(out);
	else if (operation == "AcceptedFailType")   subs.FailedTypeAccepted(out);
	else if (operation == "mapAll") 			subs.reportAll(out);
	else if (operation == "mapFinal")   		subs.reportFinal(out);
	else out << "Unknown operation! Valid operations are:\n"
				 "All\n"
				 "Accepted\n"
				 "AcceptedFinal\n"
				 "Fail\n"
				 "FailType\n"
				 "AcceptedFailType\n"
				 "mapAll\n"
				 "mapFinal\n";

	return 0;
}

#endif  //  MOOSHAKTOOLS_SUBMISSIONSAPP_H