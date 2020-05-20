//
// Created by hdaniel on 20/05/2020.
//

#include <string>

using namespace std;

/**
 *
 * @param f0 first file to compare descriptor
 * 			 PRE: f0 > 0
 * @param f1
 * @return
 */

/**
 * Compares two files
 */
class FileCompare {
static const int bufsize = 4096;  //4k page size

	///file descriptors
	int f0, f1;

public:
	FileCompare(int f0, int f1) : f0(f0), f1(f1) {}

	string fileComp(int f0, int f1) {
		char *buffer = new char[bufsize];
		string ret = "";


		return ret;
	}

};

int main() {
	return 0;
}