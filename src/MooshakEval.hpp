/**
 * Mooshak evaluation like
 * hdaniel@ualg.pt may 2020
 */

#ifndef MOOSHAKTOOLS_MOOSHAKEVAL_H
#define MOOSHAKTOOLS_MOOSHAKEVAL_H

#include <array>

using namespace std;

/**
 *  Perform Mooshak like executable evaluation
 */
class MooshakEval {
inline static const string DFLTINPUTFN  = "input";
inline static const string DFLTOUTPUTFN = "output";

const string inputFN;
const string outputFN;
const string executePath;

	/**
	 * Creates a shell command for expression evaluation
	 *
	 * @return differences between inputFN and outputFN (diff inputFN outputFN)
	 */
	string cmd() const {
		return "";
	}

public:
	/**
	 *
	 * @param executePath	path to executable
	 * @param inputFn 		path to input file name
	 * @param outputFn 		path to output file name
	 *
	 */
	MooshakEval(const std::string& executePath, const string& inputFn=DFLTINPUTFN,
				const string& outputFn=DFLTOUTPUTFN) : 	inputFN(inputFn),
			    										outputFN(outputFn),
														executePath(executePath) {}
	/**
	 * Perform expression evaluation
	 *
	 * @return
	 */
	string run() const {

		std::string ret = "";

		string c = cmd();

		return ret;
	}


	/**
	 * Inserts in output stream os a string representing the
	 * Evaluation expression in the form:
	 *
	 * diff: (<executable> < <input filename> , <output filename>)
	 *
	 * @param os 	output stream
	 * @param meval MooshakEval object
	 * @pre			os
	 *
	 * @return 		os stream with evaluation expression inserted
	 */
	friend ostream& operator<<(ostream& os, const MooshakEval& meval);
};


ostream& operator<<(ostream& os, const MooshakEval& meval) {
	os << "diff: (" + meval.executePath + " < " + meval.inputFN +  " , " + meval.outputFN + ")";
	return os;
}


#endif //MOOSHAKTOOLS_MOOSHAKEVAL_H
