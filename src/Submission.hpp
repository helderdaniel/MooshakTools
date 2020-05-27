/**
 * @author hdaniel@ualg.pt 
 * @version 0.1
 * 27/05/2020.
 */

#ifndef MOOSHAKTOOLS_SUBMISSION_H
#define MOOSHAKTOOLS_SUBMISSION_H

using std::string;

namespace mooshak {

	enum States { Pending, Final };
	const string StatesString [] = { "Pending", "Final"};

	enum Results {
		Accepted,
        PresentationError,
        WrongAnswer,
        OutputLimitExceeded,
        MemoryLimitExceeded,
        TimeLimitExceeded,
        InvalidFunction,
        RuntimeError,
        CompileTimeError,
        InvalidSubmission,
        ProgramSizeExceeded,
        RequiresReevaluation,
        Evaluating
	};

	const string ResultsString [] = {
		"Accepted"
        "Presentation Error"
        "Wrong Answer"
        "Output Limit Exceeded"
        "Memory Limit Exceeded"
        "Time Limit Exceeded"
        "Invalid Function"
        "Runtime Error"
        "Compile Time Error"
        "Invalid Submission"
        "Program Size Exceeded"
        "Requires Reevaluation"
        "Evaluating"
	};

	class Submission {
		string  _problem;
		string  _team;
		Results _classify;
		States  _state;
		//there are more data about submissions

	public:
		Submission(const string &problem, const string &team,
				   Results classify, States state) :
						_problem(problem),
						_team(team),
						_classify(classify),
						_state(state) {}

		const string &problem() const  { return _problem; }
		const string &team() const     { return _team; }
		const Results classify() const { return _classify; }
		const string classifys() const { return ResultsString[_classify]; }
		const States state() const	   { return _state;	}
		const string states() const	   { return StatesString[_state]; }
	};

}

#endif //MOOSHAKTOOLS_SUBMISSION_H
