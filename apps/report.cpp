/**
 * Just a stub to call main in *.hpp
 *
 * This way full application can be unit tested just by testing appmain()
 *
 * hdaniel@ualg.pt
 * 17th june 2020
 *
 */

#include <iostream>
#include "reportApp.hpp"

int main(int argc, char** argv) {
	return repmain(argc, argv, std::cin, std::cout);
}
