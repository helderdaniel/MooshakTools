/**
 * @author hdaniel@ualg.pt 
 * @version 0.1
 * 27/05/2020.
 */

#ifndef MOOSHAKTOOLS_SUBMISSION_H
#define MOOSHAKTOOLS_SUBMISSION_H

#include <map>
#include <table2/Table2.hpp>

using std::string;
using std::map;
using std::ostream;
using std::tie;
using had::Table2;

namespace mooshak {

	constexpr int StatesSize = 2;
	constexpr int ClassificationsSize = 13;
	enum States { Final, Pending };
	enum Classifications {
		Accepted,
		CompileTimeError,
		Evaluating,
		InvalidFunction,
		InvalidSubmission,
		MemoryLimitExceeded,
		OutputLimitExceeded,
		PresentationError,
		ProgramSizeExceeded,
		RequiresReevaluation,
		RuntimeError,
		TimeLimitExceeded,
		WrongAnswer
	};

	class Submission {

		static constexpr char bracket = '{';
		static constexpr char defaultSeparator = ',';

		static const map<Classifications, string> classificationsMap;
		static const map<States, string> statesMap;
		static const Table2<Classifications, string> classificationsTbl;
		static const Table2<States, string> statesTbl;

		string  _problem;
		string  _team;
		States  _state;
		Classifications _classification;
		//there are more data about submissions

	public:
		static inline string Problem = "Problem ";
		static inline string Team = "Team ";
		static inline string Classify = "Classify ";
		static inline string ClassifyFinal = "State ";

		static Classifications classificationFromString (const string &str) {
			//strip { } if present
			if (str[0] == bracket)
				return classificationsTbl.key(str.substr(1, str.size() - 2));
			else return classificationsTbl.key(str);
		}

		static States stateFromString (const string &str) {
			return statesTbl.key(str);
		}


		//Allow default constructor
		Submission() : _problem(""), _team(""), _classification(RequiresReevaluation), _state(Pending) {}

		Submission(	const string &problem,
					const string &team,
				   	Classifications classification,
				   	States state) :
				_problem(problem),
				_team(team),
				_classification(classification),
				_state(state) {}

		Submission(	const string &problem,
					const string &team,
					const string &classification,
					const string &state) :
				_problem(problem),
				_team(team),
				_classification(classificationFromString(classification)),
				_state(stateFromString(state)) {}

		const string &problem() const  { return _problem; }
		const string &team() const     { return _team; }
		const Classifications classification() const { return _classification; }
		const string classificationStr() const { return classificationsMap.at(_classification); }
		const States state() const	   { return _state;	}
		const string stateStr() const  { return statesMap.at(_state); }
		const bool isFailure() const   {
			if (_classification == Accepted) return false;
			if (_classification == PresentationError) return false;
			if (_classification == CompileTimeError) return false;
			if (_classification == InvalidSubmission) return false;
			if (_classification == ProgramSizeExceeded) return false;
			return true;
		}
		const bool isFinal() const     { return _state == Final; }


		friend string to_string(const Submission &s, const char sep=Submission::defaultSeparator) {
			string ret;
			ret += s._problem + sep;
			ret += s._team + sep;
			ret += classificationsTbl.value(s._classification) + sep;
			ret += statesTbl.value(s._state);
			return ret;
		}


		//strict-weak-ordering
		//https://en.cppreference.com/w/cpp/language/operators
		//https://stackoverflow.com/questions/11312448/operator-comparing-multiple-fields
		friend bool operator<(const Submission &lhs, const Submission &rhs) {
			return 	tie(lhs._problem,lhs._team,lhs._classification,lhs._state) <
					  tie(rhs._problem,rhs._team,rhs._classification,rhs._state);
		}
	};


	ostream &operator<<(ostream &os, const Submission &s) {
		return os << to_string(s);
	}


	//lexicographic ordering
	const map<States, string> Submission::statesMap = {
			{Final, "final"},
			{Pending, "pending"}
	};

	//lexicographic ordering
	const map<Classifications, string> Submission::classificationsMap = {
			{Accepted,             "Accepted"},
			{CompileTimeError,     "Compile Time Error"},
			{Evaluating,           "Evaluating"},
			{InvalidFunction,      "Invalid Function"},
			{InvalidSubmission,    "Invalid Submission"},
			{MemoryLimitExceeded,  "Memory Limit Exceeded"},
			{OutputLimitExceeded,  "Output Limit Exceeded"},
			{PresentationError,    "Presentation Error"},
			{ProgramSizeExceeded,  "Program Size Exceeded"},
			{RequiresReevaluation, "Requires Reevaluation"},
			{RuntimeError,         "Runtime Error"},
			{TimeLimitExceeded,    "Time Limit Exceeded"},
			{WrongAnswer,          "Wrong Answer"}
	};

	const Table2<States, string> Submission::statesTbl(Submission::statesMap);
	const Table2<Classifications, string> Submission::classificationsTbl(Submission::classificationsMap);
}


#endif //MOOSHAKTOOLS_SUBMISSION_H
