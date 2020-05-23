

#include <iostream>
#include <vector>
#include "../src/MooshakEval.hpp"
#include "../src/Shell.hpp"

int main(int argc, char** argv) {
std::string output;
const std::string path   = "../test/samples/files/";
//const std::string path   = "/home/hdaniel";

	Shell::execute("lcs "+path, output);
	std::cout << output;
}
