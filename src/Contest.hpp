/**
 *
 *
 * @author hdaniel@ualg.pt 
 * @version 0.1
 * 25/05/2020.
 */

#ifndef MOOSHAKTOOLS_CONTEST_H
#define MOOSHAKTOOLS_CONTEST_H

#include <map>
#include <iostream>
#include <numeric>
#include <file/File.hpp>
#include <string/String.hpp>
#include "Submission.hpp"

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::ostream;

using had::File;
using had::String;

namespace mooshak {

	class Contest {
		static inline string folderSep = "/";
		static inline string datafile = ".data.tcl";
		static inline string problemsFN = "problems";
		static inline string submissionsFN = "submissions";

		string contestFolder;
		bool filterNames;
		string problemsFolder;
		string submissionsFolder;
		map<const string, const string> problemName;
		vector<Submission> submissions;


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
		 *	Fills submission vector with every submission in contest
		 */
		void _getSubmissions() {
			string file, buf, name, team, classify, state;
			Submission sub;
			ulong idx;

			auto subfiles = File::search(submissionsFolder, datafile, 1);
			for (auto sf : subfiles) {

				//ignore datafile in submissions root dir
				String::lastSubstring(sf, folderSep, folderSep, buf);
				if (buf == submissionsFN) continue;

				//read datafile
				file = File::read(sf.c_str());

				//Add problem name
				idx = String::firstSubstring(file, Submission::Problem, "\n", buf);
				name = problemName[buf];

				//Add team
				idx = String::firstSubstring(file, Submission::Team, "\n", buf, idx);

				if (filterNames) buf = _filter(buf);
				team = buf;

				//Add classify
				idx = String::firstSubstring(file, Submission::Classify, "\n", buf, idx);
				classify = buf;

				//Add state
				String::firstSubstring(file, Submission::ClassifyFinal, "\n", buf, idx);
				state = buf;

				submissions.push_back(Submission(name, team, classify, state));
			}
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

			//Get submissions data
			_getSubmissions();
			sort(submissions.begin(), submissions.end());
		}

		/**
		 *
		 * @return all submissions as a string with format:
		 *
		 *  A,12335,Accepted
		 *  A,23456,Accepted
		 *  A,23456,{Wrong Answer}
		 *  B,13456,Accepted
		 *  (...)
		 */
		string All() {
			string ret;

			///lambda way
			for_each(submissions.begin(), submissions.end(),
					[&](const Submission &s){ ret+=s.toString()+'\n'; } );
			return ret;
		}

		/**
		 *
		 * @return all submissions Accepted as a string with format:
		 *
		 *  A,12335,Accepted
		 *  A,23456,Accepted
		 *  A,23456,{Wrong Answer}
		 *  B,13456,Accepted
		 *  (...)
		 */
		string Accepted() {
			string ret;

			for (auto it = submissions.begin(); it != submissions.end(); ++it)
				if (it->classify() == mooshak::Accepted)
					ret += it->toString()+'\n';
			return ret;
		}

		/**
		 *
		 * @return all submissions Accepted and Final as a string with format:
		 *
		 *  A,12335,Accepted
		 *  A,23456,Accepted
		 *  A,23456,{Wrong Answer}
		 *  B,13456,Accepted
		 *  (...)
		 */
		string AcceptedFinal() {
			string ret;

			for (auto it = submissions.begin(); it != submissions.end(); ++it)
				if (it->classify() == mooshak::Accepted &&
				    it->state() == mooshak::Final)
					 ret += it->toString()+'\n';
			return ret;
		}

		/**
		 *
		 * @param os    output stream
		 * @param mcnt  mooshak contest
		 * @return 		mooshak contest as string
		 */
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

#endif //MOOSHAKTOOLS_CONTEST_H
