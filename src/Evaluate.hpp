/**
 * Mooshak evaluation like
 * hdaniel@ualg.pt may 2020
 */

#ifndef MOOSHAKTOOLS_MOOSHAKEVAL_H
#define MOOSHAKTOOLS_MOOSHAKEVAL_H

#include <array>
#include <iostream>
#include <file/File.hpp>
#include <shell/Shell.hpp>

using std::string;
using std::runtime_error;
using had::File;
using had::Shell;

/**
 *  Perform Mooshak like executable evaluation
 */
namespace mooshak {

	class Evaluate {
		static constexpr const char* DFLTINPUTFN  = "input";
		static constexpr const char* DFLTOUTPUTFN = "output";

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
		Evaluate(const string &executePath, const string &testsPath,
				 const string &inputFN = DFLTINPUTFN,
				 const string &outputFN = DFLTOUTPUTFN) : executePath(executePath),
				  										  testsPath(testsPath),
				 										  inputFN(inputFN),
														  outputFN(outputFN) {
			if (!std::filesystem::exists(executePath))
				throw runtime_error("executable not found");
			if (!std::filesystem::exists(testsPath))
				throw runtime_error("tests folder not found");
		}

		/**
		 * Perform expression evaluation
		 *
		 * @return
		 */
		string run() const {
			string ret;
			auto inputs = File::search(testsPath, inputFN);
			auto outputs = File::search(testsPath, outputFN);

			if (inputs.size() != outputs.size())
				throw runtime_error("Number of input and output files differ");

			//If inputs == outputs == 0
			if (inputs.size() <= 0)
				throw runtime_error("No tests found, with given regexs: \"" + inputFN +
										 "\" and \"" + outputFN + "\" from root dir: " + testsPath);

			sort(inputs.begin(), inputs.end());
			sort(outputs.begin(), outputs.end());

			int i = 0;
			for (const auto &in : inputs) {
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
		 * Inserts in output stream os, a line for each test, in the form:
		 *
		 * <executable> < <input filename>
		 *
		 * If any differences between <executable> output and <expected output> shows them as:
		 *
		 * Expected:
		 * (...)
		 * Actual:
		 * (...)
		 *
		 * @param os 	output stream
		 * @param meval Evaluate object
		 * @pre			os
		 *
		 * @return 		os stream with evaluation expression inserted
		 */
		friend ostream &operator<<(ostream &os, const Evaluate &meval);
	};


	ostream &operator<<(ostream &os, const Evaluate &meval) {
		os << "diff: (" + meval.executePath + " (" +
			  meval.testsPath + "/" + meval.inputFN + ", " +
			  meval.testsPath + "/" + meval.outputFN + ")";
		return os;
	}

}

#endif //MOOSHAKTOOLS_MOOSHAKEVAL_H
