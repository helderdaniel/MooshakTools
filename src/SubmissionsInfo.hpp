/**
 * Get information about mooshak contest submissions
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
#include <vector>
#include <algorithm>
//#include <execution>
#include <file/File.hpp>
#include <string/String.hpp>
#include "Submission.hpp"
//#include <appTest/IdentifyType.hpp>

using std::cout;
using std::map;
using std::string;
using std::vector;
using std::tuple;
using std::ostream;

using had::File;
using had::String;

namespace mooshak {

	class SubmissionsInfo {
        static constexpr int defaultWidthClass = 5;
        static constexpr char defaultCsvSeparator = ',';

        static constexpr const char *folderSep = "/";
        static constexpr const char *datafile = ".data.tcl";
        static constexpr const char *problemsFN = "problems";
        static constexpr const char *submissionsFN = "submissions";

        string contestFolder;
        bool filterNames;
        string problemsFolder;
        string submissionsFolder;
        map<const string, const string> problemName;
        vector<Submission> submissions;

        map<const string, array<int, ClassificationsSize>> mapCountAll, mapCountFinal;
        map<const string, array<int, UniqueSize>> mapCountUnique;

        typedef tuple<string, string> filterTuple;
        typedef vector<filterTuple> customFilter;
        customFilter fteam;

        /**
         * Create map with problem directory name as key and Mooshak problem name as value
         */
        void _getProblemNames() {
            string buf, key, value;

            auto probInfo = File::search(problemsFolder, datafile);
            for (const auto &pi : probInfo) {

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
            for (const auto &p : problemName) {
                array<int, ClassificationsSize> all = {0};
                mapCountAll.insert({p.second, all});
                array<int, ClassificationsSize> final = {0};
                mapCountFinal.insert({p.second, final});
                array<int, UniqueSize> unique = {0};
                mapCountUnique.insert({p.second, unique});
            }
        }

        /**
         *
         * @param str string to transform according to filter file specs
         */
        void _filter(string &str) {

            //for (customFilter::const_iterator i = fteam.begin(); i != fteam.end(); ++i) {
            for (const auto &i : fteam) {
                const string &regexp(get<0>(i));
                const string &replacement = get<1>(i);

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
            ulong idx;

            auto subfiles = File::search(submissionsFolder, datafile, 1);
            for (const auto &sf : subfiles) {

                //ignore datafile in submissions root dir
                String::lastSubstring(sf, folderSep, folderSep, buf);
                if (buf == submissionsFN) continue;

                //read datafile
                file = File::read(sf.c_str());

                //Add problem name
                idx = String::firstSubstring(file, Submission::Problem, "\n", buf);
                pname = problemName[buf];

                //Add team
                idx = String::firstSubstring(file, Submission::Team, "\n", team, idx);

                if (filterNames) _filter(team);

                //Add classification
                idx = String::firstSubstring(file, Submission::Classify, "\n", classify, idx);

                //Add state
                String::firstSubstring(file, Submission::ClassifyFinal, "\n", state, idx);

                //Add submission
                //const here does NOT give better performance
                //compiler should optimize it anyway
                const Submission sub(pname, team, classify, state);
                submissions.emplace_back(sub);
                //using std::move() does not give better performance
                //since using const&
                //Submission s(std::move(pname), std::move(team), std::move(classify), std::move(state));
                //submissions.emplace_back(std::move(s));

                //Update classification counters
                mapCountAll.at(pname)[sub.classification()]++;
                if (sub.isFinal()) mapCountFinal.at(pname)[sub.classification()]++;
            }
        }


        /**
         * @param os output stream to insert table
         * @param map map to be converted to table
         * @return table that represents the map
         */
        ostream &_report(ostream &os, map<const string, array<int, ClassificationsSize>> map) const {
            //Header
            os << std::setw(defaultWidthClass) << "nofail";
            auto f = Submission::noFailSet.begin();
            for (int i = 0; i < mooshak::ClassificationsSize; ++i) {
                if (i == *f) {
                    os << "  *  ";
                    f++;
                }
                else { os << "     "; }
            }
            os << '\n';
            os << "Prob  Acc CTEr Eval InFn InSb MLEx OLEx PErr PSEx REvl RTEr TLEx WrAn Total Fails\n";

            //Body
            for (auto entry : map) {
                os << std::setw(defaultWidthClass - 2) << entry.first << " ";
                int total = 0;
                int fails = 0;
                for (int i = 0; i < mooshak::ClassificationsSize; ++i) {
                    int val = map.at(entry.first)[i];
                    total += val;
                    bool isFail = Submission::noFailSet.find(static_cast<const Classifications>(i)) ==
                                  Submission::noFailSet.end();
                    if (isFail) fails += val;
                    os << std::setw(defaultWidthClass) << val;
                }
                os << std::setw(defaultWidthClass + 1) << total;
                os << std::setw(defaultWidthClass + 1) << fails << '\n';
            }
            return os;
        }


    public:
        /**
         *
         * @param contestFolder Mooshak contest root folder
         * @param filterNames   Filter Team names if true
         */
        explicit SubmissionsInfo(const string &contestFolder, const string &filterFN = "") :
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
            } else {
                filterNames = true;
                ifstream input(filterFN);
                if (!input)
                    throw std::runtime_error("I/O error opening filter");

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
         * Applies f() to every element in SubmissionsInfo. F() cannot change elemnts.
         *
         * @tparam Func template function accepts: function pointers, functor classes, and lambdas
         * @param f 	function pointers, functor classes, and lambdas
         */
        //Accepts functor classes, function pointers and lambdas
        //This is slower than specialized methods, to prevent function f() to modify vector elements, see below
        template<typename Func>
        void foreach(Func f) {
            //Slower 15% than (but ensures vector cannot be changed)
            //for (const auto& s : submissions)
            for (const auto s : submissions) f(s);

            //Note: even this ways <const_cast> will give access to modify element
            //for (vector<Submission>::const_iterator it = submissions.cbegin(); it < submissions.cend(); ++it)
            //	f(std::as_const(*it));
        }

        /*Slower 25% but ensures vector cannot be changed
        void foreach0(const std::function<void(Submission)> f) {
            for (const auto& s : submissions) f(s);
        }
        */


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
            for (const auto &s : submissions)
                ret += to_string(s) + '\n';

            return ret;
        }

        //About 25% slower
        ostream &All(ostream &os) const {
            for (const auto &s : submissions) os << s << '\n';
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
            string ret;

            for (const auto &s : submissions)
                if (s.classification() == mooshak::Accepted)
                    ret += to_string(s) + '\n';
            return ret;
        }

        //About 25% slower
        ostream &Accepted(ostream &os) const {
            for (const auto &s : submissions)
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
            string ret;

            ///for iterator way
            for (const auto &s : submissions)
                if (s.classification() == mooshak::Accepted &&
                    s.state() == mooshak::Final)
                    ret += to_string(s) + '\n';
            return ret;
        }

        //About 25% slower
        ostream &AcceptedFinal(ostream &os) const {
            for (const auto &s : submissions)
                if (s.classification() == mooshak::Accepted &&
                    s.state() == mooshak::Final)
                    os << s << '\n';
            return os;
        }


    private:
        /**
         *
         * @tparam U   use to accept a function pointer, functor or lambda for comparision
         * @tparam V   use to accept a function pointer, functor or lambda for insertion
         * @param os   stream to insert
         * @param cmp  comparator
         * @param ins  stream insertion and formatter
         * @param sep  field separator
         * @return     a stream with all submissions that fulfill cmp() as a string defined by ins()
         */
        //About 25% slower than string version
        template<typename U, typename V>
        ostream &_Failed(ostream &os,
                         U cmp, V ins,
                //or:
                //bool(*cmp)(const Submission&, const Submission&),
                //void (*ins)(ostream&, const Submission&,
                //  		   const int count, const char sep),
                         const char sep = defaultCsvSeparator) const {
            int count = 0;
            Submission s0;

            for (const auto &s : submissions)
                if (s.isFailure()) {
                    //Another failed group submission
                    if (!cmp(s0, s)) {
                        //Only print if count > 0, last failed accounted submission
                        //Does NOT print at first iteration
                        if (count > 0) ins(os, s0, count, sep);
                        count = 1;
                        s0 = s;
                    }
                        //same failed group submission
                    else count++;
                }
            //If there was any failed accounted submission, print it
            if (count > 0) ins(os, s0, count, sep);
            return os;
        }

        /**
         * @param   s0 a Submission to compare
         * @param   s1 another Submission to compare
         * @return  true if _problem, _team and _classification are equal
         */
        static bool cmpFailed(const Submission &s0, const Submission &s1) {
            return s0.problem() == s1.problem() &&
                   s0.team() == s1.team() &&
                   s0.classification() == s1.classification();
        }

        /**
         * @param   s0 a Submission to compare
         * @param   s1 another Submission to compare
         * @return  true if _problem and _team are equal
         */
        static bool cmpFailedType(const Submission &s0, const Submission &s1) {
            return s0.problem() == s1.problem() &&
                   s0.team() == s1.team();
        }


        /**
         * insert submission in stream os, with format:
         *
         *  A,12335,Runtime Error,final
         *  A,12335,Wrong Answer,pending
         *  B,13456,Wrong Answer,pending
         *  (...)
         *
         * @param os    stream to insert
         * @param sub   submission
         * @param count counter
         * @param sep   field, separator
         */
        static void insFailed(ostream &os, const Submission &sub, const int count,
                              const char sep = defaultCsvSeparator) {
            os << sub.problem() << sep << sub.team() << sep
               << sub.classificationStr() << sep << count << '\n';
        }

        /**
         * insert count of submission in stream os, with format:
         *
         *  A,12335,0
         *  A,12565,3
         *  B,13456,3
         *  (...)
         *
         * @param os    stream to insert
         * @param sub   submission
         * @param count counter
         * @param sep   field, separator
         */
        static void insFailedType(ostream &os, const Submission &sub, const int count,
                                  const char sep = defaultCsvSeparator) {
            os << sub.problem() << sep << sub.team() << sep << count << '\n';
        }

    public:
        /**
         * @param os   stream to insert
         * @param sep  field separator
         * @return     a stream with failed submissions
         */
        ostream &Failed(ostream &os, const char sep = defaultCsvSeparator) const {
            return _Failed(os, cmpFailed, insFailed, sep);
        }

        /**
         * @param os   stream to insert
         * @param sep  field separator
         * @return     a stream with the count of failed submissions, group for problem and team
         */
        ostream &FailedType(ostream &os, const char sep = defaultCsvSeparator) const {
            return _Failed(os, cmpFailedType, insFailedType, sep);
        }

        /**
         * @param os   stream to insert
         * @param sep  field separator
         * @return     a stream with the count of failed submissions, group for problem
         * 			   and team, only for teams that have the problem marked as Accepted
         */
        ostream &FailedTypeAccepted(ostream &os, const char sep = defaultCsvSeparator) const {
            int count = -1;
            Submission sub;

            for (const auto &s : submissions)
                if (!cmpFailedType(sub, s)) {
                    //Add to stream only if count >= 0, last failed accounted submission
                    //Does NOT print at first iteration
                    if (count >= 0) insFailedType(os, sub, count, sep);

                    if (s.classification() == mooshak::Accepted && s.isFinal()) {
                        count = 0;
                        sub = s;
                    } else count = -1;
                } else if (s.isFailure()) count++;

            //If there was any failed accounted submission, print it
            if (count >= 0) insFailedType(os, sub, count, sep);
            return os;
        }


        /**
         * @param os output stream to insert table
         * @return table with counting of All submissions by classification type
         */
        ostream &reportAll(ostream &os) const { return _report(os, mapCountAll); }

        /**
         * @param os output stream to insert table
         * @return table with counting of only Final submissions by classification type
         */
        ostream &reportFinal(ostream &os) const { return _report(os, mapCountFinal); }


        /**
         * @param os output stream to insert table
         * @param map map to be converted to table
         * @return table that represents the map
         */
        ostream &reportUnique(ostream &os) {
            //Create vector of pointers to submissions without duplicates
            vector<Submission const*> all;
            all.reserve(submissions.size());
            for (auto & s : submissions)
                all.emplace_back(&s);

            //all.erase( unique( all.begin(), all.end(), CompareSubmissionPointers() ), all.end() );
            auto predUnique = [](Submission const* lhs, Submission const* rhs) { return *lhs == *rhs; };
            all.erase(unique(all.begin(), all.end(), predUnique ), all.end() );

            //Unique submissions count
            vector<Submission const*> subs(all);
            //subs.erase( unique( subs.begin(), subs.end(), CompareSubmissionProblemTeam() ), subs.end() );
            auto predProbTeam = [](Submission const* lhs, Submission const* rhs) { return lhs->problem() == rhs->problem() && lhs->team() == rhs->team(); };
            subs.erase(unique(subs.begin(), subs.end(), predProbTeam ), subs.end() );
            for (auto &sub : subs)
                mapCountUnique.at(sub->problem())[0]++;


            //Unique accepted submissions count
            vector<Submission const*> acc;
            auto predAcc = [](Submission const *sub) { return sub->classification() == mooshak::Accepted; };
            copy_if(subs.begin(), subs.end(), back_inserter(acc), predAcc);
            for (auto &sub : acc)
                mapCountUnique.at(sub->problem())[1]++;


            //Unique accepted and final submissions count
            vector<Submission const*> accf;
            auto predAccFinal = [](Submission const *sub) { return sub->classification() == mooshak::Accepted && sub->state() == mooshak::Final; };
            copy_if(all.begin(), all.end(), back_inserter(accf), predAccFinal);
            for (auto &sub : accf)
                mapCountUnique.at(sub->problem())[2]++;


            //Header
            os << "Unique person count\n";
            os << "Problem Submissions Accepted Final\n";

            //Body
            for (auto entry : mapCountUnique) {
                os << std::setw(defaultWidthClass) << entry.first << "    ";
                for (int i = 0; i < mooshak::UniqueSize; ++i) {
                    int val = mapCountUnique.at(entry.first)[i];
                    os << std::setw(defaultWidthClass+3) << val;
                }
                os << '\n';
            }
            return os;
        }


        /**
         * @param os    output stream
         * @param mcnt  mooshak contest
         * @return 		mooshak contest as string
         */
        friend ostream &operator<<(ostream &os, const SubmissionsInfo &mcnt);
    };

    ostream& operator<<(ostream &os, const SubmissionsInfo &mcnt) {
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
