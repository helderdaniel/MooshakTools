/**
 *
 *
 * @author hdaniel@ualg.pt 
 * @version 0.1
 * 25/05/2020.
 */

#ifndef MOOSHAKTOOLS_SUBMISSION_H
#define MOOSHAKTOOLS_SUBMISSION_H


#include <map>
#include <iostream>
#include <numeric>
#include <file/File.hpp>
#include <string/String.hpp>

using namespace had;
using std::cout;
using std::map;
using std::string;
using std::vector;
using std::ostream;

namespace mooshak {

	class Contest {
		static const char fieldSep = ',';
		static inline string folderSep = "/";
		static inline string datafile = ".data.tcl";
		static inline string problemsFN = "problems";
		static inline string submissionsFN = "submissions";

		static inline string Problem = "Problem ";
		static inline string Team = "Team ";
		static inline string Classify = "Classify ";
		static inline string ClassifyAccepted = "Classify Accepted";
		static inline string ClassifyFinal = "State final";
		static inline string Final = "Final";

		string contestFolder;
		bool filterNames;
		string problemsFolder;
		string submissionsFolder;
		map<const string, const string> problemName;


		/**
		 * Create map with problem directory name as key and Mooshak problem name as value
		 */
		void _getProblemNames() {
			string buf, key, value;

			auto probInfo = File::search(problemsFolder, datafile);
			for (auto pi : probInfo) {

				//extract key
				buf = pi.string();
				String::lastSubstring(buf, folderSep, folderSep, key);
				//ignore datafile in problems root dir
				if (key == problemsFN) continue;

				//find Mooshak problem name in folder
				buf = File::read(pi);
				String::firstSubstring(buf, "Name ", "\n", value);

				//add new entry
				problemName.insert({key, value});
			}
		}


		/**
		 *
		 * @param in string to parse
		 * @return string transformed according to filter code (better if dynamic)
		 */
		string _filter(const string &in) {
			if (in[0] == 'a') return in.substr(1);
			if (in == "G1POO1920P1G15") return "POO1920P1G15";
			if (in == "POO1920g1p07") return "POO1920P1G7";
			if (in == "POO1920p02G05") return "POO1920P2G5";
			if (in == "POO1920p1G02") return "POO1920P1G2";
			if (in == "POO2019203G4") return "POO1920P3G4";
			if (in == "POOP3G8") return "POO1920P3G8";
			if (in == "POO1920p1G09") return "POO1920P1G9";
			return in;
		}

		/**
		 *
		 * @param accepted
		 * @param final
		 * 					If accepted == true AND final == true Lists only submissions Accepted and Final
		 * 					If accepted == true AND final == false Lists all submissions Accepted
		 * 					Else lists all submissions
		 *
		 * @return vector in format as sample below:
		 *
		 *  A,12335,Accepted
		 *  A,23456,Accepted
		 *  A,23456,{Wrong Answer}
		 *  B,13456,Accepted
		 *  (...)
		 */
		vector<string> _search(bool accepted, bool final) {
			string file, row, buf;
			ulong idx;
			vector<string> ret;

			auto subfiles = File::search(submissionsFolder, datafile, 1);
			for (auto sf : subfiles) {

				//ignore datafile in submissions root dir
				String::lastSubstring(sf, folderSep, folderSep, buf);
				if (buf == submissionsFN) continue;

				//read datafile
				file = File::read(sf.c_str());

				//get only Accepted and Final if required
				if (accepted && final) {
					idx = file.find(ClassifyAccepted);
					if (idx == string::npos) continue;
					idx = file.find(ClassifyFinal, idx);
					if (idx == string::npos) continue;
				}

				//get only Accepted if required
				if (accepted)
					if (file.find(ClassifyAccepted) == string::npos)
						continue;

				//clear row
				row = "";

				//Add problem name
				idx = String::firstSubstring(file, Problem, "\n", buf);
				row += problemName[buf] + fieldSep;

				//Add team
				idx = String::firstSubstring(file, Team, "\n", buf, idx);

				if (filterNames) buf = _filter(buf);
				row += buf + fieldSep;

				//Add classify
				idx = String::firstSubstring(file, Classify, "\n", buf, idx);
				row += buf;

				//Add final if it is
				String::firstSubstring(file, ClassifyFinal, "\n", buf, idx);
				if (!buf.empty()) row += Final;

				row += '\n';
				ret.push_back(row);
			}

			return ret;
		}


	public:
		/**
		 *
		 * @param contestFolder Mooshak contest root folder
		 * @param fileterNames      Filter Team names if true
		 */
		Contest(const string &contestFolder, const bool &filterNames = false) :
				contestFolder(contestFolder), filterNames(filterNames) {

			problemsFolder = contestFolder + folderSep + problemsFN;
			submissionsFolder = contestFolder + folderSep + submissionsFN;

			//Get names of problems as displayed in Mooshak: A,B,C,...
			_getProblemNames();
		}

		/**
		 *
		 * @return all submissions
		 */
		string All() {
			vector<string> v = _search(false, false);
			sort(v.begin(), v.end());

			return accumulate(v.begin(), v.end(), string{});
		}

		/**
		 *
		 * @return all submissions Accepted
		 */
		string Accepted() {
			vector<string> v = _search(true, false);
			sort(v.begin(), v.end());

			return accumulate(v.begin(), v.end(), string{});
		}

		/**
		 *
		 * @return all submissions Accepted and Final
		 */
		string AcceptedFinal() {
			vector<string> v = _search(true, true);
			sort(v.begin(), v.end());

			return accumulate(v.begin(), v.end(), string{});
		}

		friend ostream &operator<<(ostream &os, const Contest &mcnt);
	};


	ostream &operator<<(ostream &os, const Contest &mcnt) {
		os << mcnt.contestFolder + '\n' <<
		   mcnt.filterNames << '\n' <<
		   mcnt.problemsFolder << '\n' <<
		   mcnt.submissionsFolder << '\n';

		for (auto e : mcnt.problemName)
			os << e.first << ' ' << e.second << '\n';

		return os;
	}

}

#endif //MOOSHAKTOOLS_SUBMISSION_H
