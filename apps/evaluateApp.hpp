/**
 * Perform mooshak like evaluation tests.
 *
 * hdaniel@ualg.pt
 * 24th May 2020
 */

/** Operation documentation in markdown:

# evaluate
Evaluation of mooshak tests on command line.

Call with:

`evaluate <path to executable> <path to root of tests> [<input fname regex=input> <output fname regex=output>]`


### The parameters are:

 * **path to executable**:  executable or script to be evaluated
 * **path to root of tests**:  root folder to search for test files
 * **input fname regex**: input test file name regex. By default "input"
 * **<output fname regex>**: output test file name regex. By default "output"

 Note that last 2 parameters are optional by group, which means that they must passed both or none!

###Output
 Outputs a line for each test in the form:\
 \
 **executable < input filename**

Aditionally, for each test failed, ie. if for **input** file there is differences between *executable* actual **output** and **expected output**, ie. **output** file contents, shows them as:

Expected:\
(...)\
Actual:\
(...)


###### Example of output
Let's say that we have a Mooshak contest named *aContest* with a problem named *A* an a tests folder with tests T0 to T8.\
Each test *Tx* is in a subfolder of folder *tests* with the name of the test *Tx*.\
Each test folder x* have an *input* file and an expected output file named *output*.

Running the evaluator on an executable named *anExecutable* stored in the same folder **evaluate** app is, at command line with:

`./evaluate anExecutable data/contests/aContes/problems/A/tests input output`

the output below is sent to stdio.\
Note that for tests T0 to T2 and for tests T4 to T8 no differences have been found between actual output and expected output.\
Only for test T3 differences was found, being presented for this test the *Expectd:* output and the *Actual:* output.
```
 	  ../test/samples/apps/conv < ../test/samples/tests/T0/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T1/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T2/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T3/input
 	  Expected:
 	  2.00
 	  5.00
 	  10.00
 	  8.00
 	  7.00
 	  3.00
 	  Actual:
 	  2.00
 	  5.00
 	  10.00
 	  8.00
 	  8.00
 	  3.00
 	  ../test/samples/apps/conv < ../test/samples/tests/T4/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T5/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T6/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T7/input
 	  ../test/samples/apps/conv < ../test/samples/tests/T8/input
 ```
 */



#ifndef MOOSHAKTOOLS_MOOSHAKEVALAPP_H
#define MOOSHAKTOOLS_MOOSHAKEVALAPP_H

#include <iostream>
#include "src/Evaluate.hpp"

using mooshak::Evaluate;

//app main function.
//called form *.cpp stub
int evalmain(int argc, char* argv[], istream& in, ostream& out) {
std::string input="input";
std::string output="output";

	if (argc != 3 && argc != 5) {
		out << "Usage: evaluate <path to executable> <path to root of tests> "
					 "[<input fname regex=input> <output fname regex=output>]\n";
		return 0;
	}
	if (argc == 5) {
		input=argv[3];
		output=argv[4];
	}

	Evaluate eval(argv[1], argv[2], input, output);
	out << eval.run();
	return 0;
}

#endif //MOOSHAKTOOLS_MOOSHAKEVALAPP_H
