/**
 * Just a stub to call appmain in *.hpp
 *
 * This way full application can be unit tested just by testing appmain()
 *
 * hdaniel@ualg.pt
 * 16th june 2020
 *
 */

#include <iostream>
#include "evaluateApp.hpp"

int main(int argc, char** argv) {
	return evalmain(argc, argv, std::cin, std::cout);
}
