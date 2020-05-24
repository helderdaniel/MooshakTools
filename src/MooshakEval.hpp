/**
 * Mooshak evaluation like
 * hdaniel@ualg.pt may 2020
 */

#ifndef MOOSHAKTOOLS_MOOSHAKEVAL_H
#define MOOSHAKTOOLS_MOOSHAKEVAL_H

#include <array>
#include <iostream>
#include "File.hpp"
#include "Shell.hpp"

using namespace std;

/**
 *  Perform Mooshak like executable evaluation
 */
class MooshakEval {
inline static const string DFLTINPUTFN  = "input";
inline static const string DFLTOUTPUTFN = "output";

const string inputFN;
const string outputFN;
const string testsPath;
const string executePath;


public:
	/**
	 *
	 * @param executePath	path to executable
	 * @param inputFn 		input file name
	 * @param outputFn 		output file name
	 *
	 */
	MooshakEval(const std::string& executePath, const std::string& testsPath,
				const string& inputFN=DFLTINPUTFN,
				const string& outputFN=DFLTOUTPUTFN) : 	inputFN(inputFN),
			    										outputFN(outputFN),
			    										testsPath(testsPath),
														executePath(executePath) {}

	/**
	 * Perform expression evaluation
	 *
	 * @return
	 */
	std::string run() const {
		std::string ret;
		auto inputs = File::search(testsPath, inputFN);
		auto outputs = File::search(testsPath, outputFN);

		if (inputs.size() != outputs.size())
			throw std::runtime_error("Number of input and output files differ");

		//If inputs == outputs == 0
		if (inputs.size() <= 0)
			throw std::runtime_error("No tests found, with given regexs: \"" + inputFN +
									 "\" and \"" + outputFN + "\" from root dir: "+testsPath);

		sort(inputs.begin(), inputs.end());
		sort(outputs.begin(), outputs.end());

		int i=0;
		for (const auto& in : inputs) {
			std::string stdout;
			std::string output = outputs[i++];
			std::string cmd = executePath + " < ";
			cmd += in;

			Shell::execute(cmd, stdout);
			std::string cmp = File::teststr(output, stdout);
			ret += cmd + '\n';
			if (!cmp.empty())
				ret += cmp;
		}

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
	os << "diff: (" + meval.executePath + " (" +
		   meval.testsPath + "/" + meval.inputFN +  ", " +
		   meval.testsPath + "/" + meval.outputFN + ")";
	return os;
}


#endif //MOOSHAKTOOLS_MOOSHAKEVAL_H
