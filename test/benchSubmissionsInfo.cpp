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
#include "../src/SubmissionsInfo.hpp"
#include <stopwatch/stopwatch.hpp>

using namespace mooshak;

class Allf {
	string ret;
public:
	Allf(string s) : ret(s) {}
	void operator()(const Submission& s) {
		ret += to_string(s) + '\n';
	}
};

TEST_CASE( "Mooshak SubmissionsInfo", "[SubmissionsInfo]" ) {
	std::string contestPath = "../test/samples/contests/POO1920";
	SubmissionsInfo csub (contestPath);
	std::string output;
	std::stringstream ss;

	SECTION("benchmark") {
		BENCHMARK("All string") {
			output = csub.All();
	   	};

		BENCHMARK("All stream") {
			csub.All(ss);
		};

		BENCHMARK("All traverse0") {
			  std::string ret;
			  csub.foreach(
				  [&](const Submission &s){
					  //This allows change to vector element even if const ref or const pointer is passed
					  //need to copy element to ensure no write access to container elements
					  //Submission& s0 = const_cast<Submission&>(s);
					  //s0 = Submission();
					  ret += to_string(s) + '\n';
				  }
			  );
		};

		BENCHMARK("All traverse1") {
			   std::string ret;
			   csub.foreach(
					Allf(ret)
			   );
		};

		BENCHMARK("Failed") {
			std::string ret;
			csub.Failed(ss);
		};

		BENCHMARK("Failed by type") {
			std::string ret;
			csub.FailedType(ss);
		};

		BENCHMARK("Failures of accepted") {
			std::string ret;
			csub.FailedTypeAccepted(ss);
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
