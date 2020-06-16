/**
 * Just a stub to call appmain in *.hpp
 *
 * This way full application can be unit tested just by testing appmain()
 *
 * hdaniel@ualg.pt
 * 15th june 2020
 */

#include <iostream>
#include "submissionApp.hpp"

int main(int argc, char** argv) {
	return subsmain(argc, argv, std::cin, std::cout);
}


