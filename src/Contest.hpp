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
#include <algorithm>
//#include <execution>
#include <file/File.hpp>
#include <string/String.hpp>
#include "Submission.hpp"

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::tuple;
using std::ostream;

using had::File;
using had::String;

namespace mooshak {

	class Contest {
		static constexpr int defaultWidthClass = 5;

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

		map<const string, array<int,ClassificationsSize>> mapCountAll, mapCountFinal;

		typedef tuple<string,string> filterTuple;
		typedef vector<filterTuple> customFilter;
		customFilter fteam;

		/**
		 * Create map with problem directory name as key and Mooshak problem name as value
		 */
		void _getProblemNames() {
			string buf, key, value;

			auto probInfo = File::search(problemsFolder, datafile);
			for (const auto& pi : probInfo) {

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

		//Init counters
		void initCounters() {
			for (auto p : problemName) {
				array<int,ClassificationsSize> all = {0};
				mapCountAll.insert({p.second, all});
				array<int,ClassificationsSize> final = {0};
				mapCountFinal.insert({p.second, final});
			}
		}

		/**
		 *
		 * @param str string to transform according to filter file specs
		 */
		void _filter(string &str) {

			//for (customFilter::const_iterator i = fteam.begin(); i != fteam.end(); ++i) {
			for (const auto& i : fteam) {
				const string& regexp(get<0>(i));
				const string& replacement = get<1>(i);

				/* Same as:  str = regex_replace(str, regexp, replacement);
				 * but determines if matched (when begin and end of iterator are NOT equal)
				 * to abort further filter search
				 */
				if (String::regex_replace(str, regexp, replacement))
					break;
			}
		}

		/**
		 *	Fills submission vector with every submission in contest
		 */
		void _getSubmissions() {
			string file, buf, pname, team, classify, state;
			Submission sub;
			ulong idx;

			auto subfiles = File::search(submissionsFolder, datafile, 1);
			for (const auto& sf : subfiles) {

				//ignore datafile in submissions root dir
				String::lastSubstring(sf, folderSep, folderSep, buf);
				if (buf == submissionsFN) continue;

				//read datafile
				file = File::read(sf.c_str());

				//Add problem name
				idx = String::firstSubstring(file, Submission::Problem, "\n", buf);
				pname = problemName[buf];

				//Add team
				idx = String::firstSubstring(file, Submission::Team, "\n", buf, idx);

				if (filterNames) _filter(buf);
				team = buf;

				//Add classification
				idx = String::firstSubstring(file, Submission::Classify, "\n", buf, idx);
				classify = buf;

				//Add state
				String::firstSubstring(file, Submission::ClassifyFinal, "\n", buf, idx);
				state = buf;

				//Add submission
				Submission s(pname, team, classify, state);
				submissions.emplace_back(s);

				//Update classification counters
				mapCountAll.at(pname)[s.classification()]++;
				if (s.isFinal()) mapCountFinal.at(pname)[s.classification()]++;
			}
		}


	public:
		/**
		 *
		 * @param contestFolder Mooshak contest root folder
		 * @param filterNames   Filter Team names if true
		 */
		explicit Contest(const string &contestFolder, const string &filterFN="") :
				contestFolder(contestFolder) {

			problemsFolder = contestFolder + folderSep + problemsFN;
			submissionsFolder = contestFolder + folderSep + submissionsFN;

			//Get names of problems as displayed in Mooshak: A,B,C,...
			_getProblemNames();

			//Previously init counters for fast map update
			initCounters();

			//Get filter
			if (filterFN.empty()) {
				filterNames = false;
			}
			else {
				filterNames = true;
				ifstream input(filterFN);

				for (;;) {
					string rgx;
					string rpl;

					getline(input, rgx, ',');
					if (input.eof()) break;
					getline(input, rpl, '\n');
					fteam.emplace_back(filterTuple(rgx, rpl));
					if (input.eof()) throw std::runtime_error("bad filter format");
				}
			}

			//Get submissions data
			//submissions.reserve(2000);  //Do not show improvement with -Ofast ~164 us
			_getSubmissions();
			submissions.shrink_to_fit();  //Since is immutable clear vector extra reserved space for new elements
			sort(submissions.begin(), submissions.end());

			//Need to add lib to target in CmakeLists.txt ${TBBLIB} ("/usr/lib/x86_64-linux-gnu/libtbb.so")
			//sort(std::execution::par, submissions.begin(), submissions.end()); //not useful for 2000 subs
			//sort(std::execution::par_unseq, submissions.begin(), submissions.end()); //not useful for 2000 subs
		}

		/**
		 *
		 * @return all submissions as a string with format:
		 *
		 *  A,12335,Accepted,final
		 *  A,23456,Accepted,pending
		 *  A,23456,Wrong Answer,pending
		 *  B,13456,Accepted,final
		 *  (...)
		 */
		string All() const {
			string ret;

			//lambda way (same performance)
			//for_each(submissions.begin(), submissions.end(),
			//		 [&](const Submission &s){ ret += to_string(s) + '\n'; } );
			for (const auto& s : submissions)
				ret += to_string(s) + '\n';

			return ret;
		}

		//About 25% slower
		ostream& All(ostream &os) const {
			for (const auto& s : submissions) os << s << '\n';
			return os;
		}

		/**
		 *
		 * @return all submissions Accepted as a string with format:
		 *
		 *  A,12335,Accepted,final
		 *  A,23456,Accepted,pending
		 *  B,13456,Accepted,pending
		 *  (...)
		 */
		string Accepted() const {
			string ret;  //faster to *= a string than << a stringstream (about 8x)

			for (const auto& s : submissions)
				if (s.classification() == mooshak::Accepted)
					ret += to_string(s) + '\n';
			return ret;
		}

		//About 25% slower
		ostream& Accepted(ostream &os) const {
			for (const auto& s : submissions)
				if (s.classification() == mooshak::Accepted) os << s << '\n';
			return os;
		}

		/**
		 *
		 * @return all submissions Accepted and Final as a string with format:
		 *
		 *  A,12335,Accepted,final
		 *  (...)
		 */
		string AcceptedFinal() const {
			string ret;  //faster to *= a string than << a stringstream (about 8x)

			///for iterator way
			for (const auto& s : submissions)
				if (s.classification() == mooshak::Accepted &&
				    s.state() == mooshak::Final)
					ret += to_string(s) + '\n';
			return ret;
		}

		//About 25% slower
		ostream& AcceptedFinal(ostream &os) const {
			for (const auto& s : submissions)
				if (s.classification() == mooshak::Accepted &&
					s.state() == mooshak::Final)
					os << s << '\n';
			return os;
		}


		/**
		 * @param os output stream to insert table
		 * @param map map to be converted to table
		 * @return table that represents the map
		 */
		ostream& countMap(ostream& os, map<const string, array<int,ClassificationsSize>> map) const {
			//Header
			os << std::setw(defaultWidthClass) << "nofail";
			auto f = Submission::noFailSet.begin();
			for (int i = 0; i < mooshak::ClassificationsSize; ++i) {
				if (i == *f) { os << "  *  "; f++; }
				else         { os << "     "; }
			}
			os << '\n';
			os << "Prob  Acc CTEr Eval InFn InSb MLEx OLEx PErr PSEx REvl RTEr TLEx WrAn Total Fails\n";

			//Body
			for (auto entry : map) {
				os << std::setw(defaultWidthClass-2) << entry.first << " ";
				int total=0;
				int fails=0;
				for (int i = 0; i < mooshak::ClassificationsSize; ++i) {
					int val = map.at(entry.first)[i];
					total += val;
					bool isFail = Submission::noFailSet.find(static_cast<const Classifications>(i)) == Submission::noFailSet.end();
					if (isFail)  fails += val;
					os << std::setw(defaultWidthClass) << val;
				}
				os << std::setw(defaultWidthClass+1) << total;
				os << std::setw(defaultWidthClass+1) << fails << '\n';
			}
			return os;
		}

		/**
		 * @param os output stream to insert table
		 * @return table with counting of All submissions by classification type
		 */
		ostream& countAll(ostream& os) const { return countMap(os, mapCountAll); }

		/**
		 * @param os output stream to insert table
		 * @return table with counting of only Final submissions by classification type
		 */
		ostream& countFinal(ostream& os) const { return countMap(os, mapCountFinal); }

		/**
		 *
		 * @param os    output stream
		 * @param mcnt  mooshak contest
		 * @return 		mooshak contest as string
		 */
		friend ostream& operator<<(ostream &os, const Contest &mcnt);
	};


	ostream& operator<<(ostream &os, const Contest &mcnt) {
		os << mcnt.contestFolder + '\n' <<
		   mcnt.filterNames << '\n' <<
		   mcnt.problemsFolder << '\n' <<
		   mcnt.submissionsFolder << '\n';

		for (auto e : mcnt.problemName)
		//slows down in benchContest
		//which does NOT uses <<. WHY?
		//for (const auto& e : mcnt.problemName)
			os << e.first << ' ' << e.second << '\n';

		return os;
	}

}

#endif //MOOSHAKTOOLS_CONTEST_H
