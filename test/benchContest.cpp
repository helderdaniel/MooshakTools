//
// Created by hdaniel on 25/05/2020.
//

/**
 * Too enable catch2 benchmarking
 * it is needed to be defined here before the inclusion of the <cathc.hpp>
 * and also in the file where is defined: CATCH_CONFIG_MAIN if NOT here
 */
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>
#include <sstream>
#include "../src/Contest.hpp"
#include <stopwatch/stopwatch.hpp>

using namespace mooshak;

TEST_CASE( "Mooshak Contest", "[Contest]" ) {
	std::string contestPath = "../test/samples/contests/POO1920";
	Contest contest (contestPath);
	std::string output;

	SECTION("benchmark") {
		BENCHMARK("All") {
			output = contest.All();
	   };
	}
/*
	StopWatch sw;
	sw.reset();
	for (int i=0; i < 100; ++i)
		output = contest._search(false, false);
	sw.lap();
	cout << sw.watch()/100 << endl;
*/

}
