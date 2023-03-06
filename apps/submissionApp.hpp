/**
 * Gather information from all submissions to a Mooshak contest
 *
 * hdaniel@ualg.pt
 * 15th June 2020
 */


/** Operation documentation in markdown:

# submissions
Gather information from all submissions to a Mooshak contest.

Call with:

`submissions <contest path> <operation> [<filter path>]`


### 1st argument is the contest folder path, eg:

`/home/mooshak/data/contests/aContestFolder`


### 2nd argument is the operation, and can be:
```
All               list all submissions
Accepted          list only "Accepted" submissions
AcceptedFinal     list only "Accepted" and "final" submissions
Fail              list failed submissions
FailType          list failed submissions grouped by type
AcceptedFailType  list failed submissions grouped by type, only if team as one "Accepted" submission to the problem
                  (used to get info from Mooshak to assessment sheets)
mapAll            map counter of all submissions classification for each problem
mapFinal          map counter of all submissions classification for each problem, marked as "final"
mapUnique         map counter of different persons that have submitted, have accepted and have accepted marked as \"final\"\n";
```

For operations: "All", "Accepted" and "AcceptedFinal", list is formatted as sample below and sorted alphabetically.
Columns from left to right are:

- Mooshak contest's problem name
- Team name
- Submission state
- Submission marked as **final** or **pending** review

 ```
 A,12335,Accepted,final
 A,23456,Accepted,pending
 A,23456,Wrong Answer,pending
 B,13456,Accepted,pending
 (...)
 ```
 For operation "Fail" list is formatted as sample below and sorted alphabetically.
 Columns from left to right are:

- Mooshak contest's problem name
- Team name
- Submission state
- number of submissions with this state for this problem and this team

 ```
 A,44340,Runtime Error,1
 A,44340,Wrong Answer,2
 A,49551,Wrong Answer,1
 A,52080,Runtime Error,1
 A,52770,Wrong Answer,1
 (...)
 ```
 For operation "FailType" and "AcceptedFailType", list is formatted as sample below and sorted alphabetically.
 Columns from left to right are:

- Mooshak contest's problem name
- Team name
- number of all failed submissions for this problem and this team

 ```
 A,44340,3
 A,49551,1
 A,52080,1
 A,52770,1
 (...)
 ```
 Submission states listed below are the only ones not considered as failure	(This is hard coded in current version).
 -	Accepted
 -	Compile Time Error
 -	Invalid Submission
 -	Presentation Error
 -	Program Size Exceeded

For operation "mapAll" and "mapFinal", map is formatted as sample below.
**mapAll** presents a map of all submissions, while **mapFinal** only of final marked submissions.

Columns with an asterisk on top are submission states not considered failures, as described above.

 ```
 nofail  *    *              *              *    *
 Prob  Acc CTEr Eval InFn InSb MLEx OLEx PErr PSEx REvl RTEr TLEx WrAn Total Fails
   A    89   35    0    0    0    0    0    2    0    0   41    0   34   201    75
   B   115   19    0    0    0    0    0    4    0    0   55    0   46   239   101
   C   139   29    0    0    0    0    0    9    1    0   37    0   57   272    94
   D   120   24    0    0    0    0    0    0    0    0   18    0  115   277   133
   E    83   87    0    0    0    0    0    0    0    0   13    0   11   194    24
   F   119   38    0    0    0    0    0    2    0    0   27    0   26   212    53
   G    74   22    0    0    0    0    0    3    0    0    5    0   13   117    18
   H    47   38    0    0    0    0    0   13    1    0    4    0   16   119    20
```
Column header legend:\
**Acc** Accepted\
**CTEr** Compile Time Error\
**Eval** Evaluating\
**InFn** Invalid Function\
**InSb** Invalid Submission\
**MLEx** Memory Limit Exceeded\
**OLEx** Output Limit Exceeded\
**PErr** Presentation Error\
**PSEx** Program Size Exceeded\
**REvl** Requires Reevaluation\
**RTEr** Runtime Error\
**TLEx** Time Limit Exceeded\
**WrAn** Wrong Answer\


### 3rd argument is an optional path to a Team filter for team name fixing
If specified a 3rd parameter, it is the path of a filter text file to fix team names using regular expressions, eg.:

`submissions /home/mooshak/data/contests/aContestFolder All aFilterFile.flt`

If file `aFilterFile.flt` has the contents:

```
^a,
G1POO1920P1G15,POO1920P1G15
POO1920g1p07,POO1920P1G7
```

Rules are applied from top to bottom. First row makes all team names uppercase. Last 2 row are substitution pairs. If found a team name equal to the left column it is changed to the name in the right column.

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
		out << "Usage: submissions <contest path> <operation> [<filter path>]\n\n";
		out <<
		"Operation:\n"
        "Accepted               list only \"Accepted\" submissions\n"
        "AcceptedFinal          list only \"Accepted\" and \"final\" submissions\n"
        "All                    list all submissions\n"
        "Fail                   list failed submissions\n"
        "FailType               list failed submissions grouped by type\n"
        "AcceptedFailType       list failed submissions grouped by type, only if team as one \"Accepted\" submission to the problem\n"
        "                       (used to get info from Mooshak to assessment sheets)\n"
        "AcceptedFailTypeMark   list failed submissions grouped by type, only if team as one \"Accepted\" submission to the problem\n"
        "                       (as above but shows also Mark, needs Mooshak contest type: Exam)"
        "                       (also used to get info from Mooshak to assessment sheets)\n"
        "mapAll                 map counter of all submissions classification for each problem\n"
        "mapFinal               map counter of all submissions classification for each problem, marked as \"final\"\n"
        "mapUnique              map counter of different persons that have submitted, have accepted and have accepted marked as \"final\"\n";

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
    else if (operation == "AcceptedFailTypeMark") subs.FailedTypeAccepted(out, true);
	else if (operation == "mapAll") 			subs.reportAll(out);
	else if (operation == "mapFinal")   		subs.reportFinal(out);
    else if (operation == "mapUnique")   		subs.reportUnique(out);
	else out << "Unknown operation \'" << operation << "\' Valid operations are:\n"
				 "All\n"
				 "Accepted\n"
				 "AcceptedFinal\n"
				 "Fail\n"
				 "FailType\n"
				 "AcceptedFailType\n"
                 "AcceptedFailTypeMark\n"
				 "mapAll\n"
				 "mapFinal\n"
                 "mapUnique\n";

	return 0;
}

#endif  //  MOOSHAKTOOLS_SUBMISSIONSAPP_H