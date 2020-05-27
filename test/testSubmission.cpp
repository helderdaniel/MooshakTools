/**
 * @author hdaniel@ualg.pt
 * @version 0.1
 * 27/05/2020.
 */

#include <catch2/catch.hpp>
#include <sstream>
#include "../src/Submission.hpp"

using namespace mooshak;

TEST_CASE( "Mooshak Submission", "[Submission]" ) {
	/*
	std::string contestPath = "../test/samples/contests/POO1920";
	bool filterNames = true;

	SECTION("Constructor") {
		const int cases = 2;
		const Contest c[] = {
				Contest (contestPath),
				Contest (contestPath, filterNames) };

		std::string contest0 = "0\n";
		std::string contest1 = "1\n";
		std::string baseContest =
				"../test/samples/contests/POO1920/problems\n"
 				"../test/samples/contests/POO1920/submissions\n"
				"P1 A\n"
				"P2 B\n"
				"P3 C\n"
				"P4 D\n"
				"P5 E\n"
				"P6 F\n"
				"P7 G\n"
				"P8 H\n";

		const std::string sc[] = {
				contestPath + '\n' + contest0 + baseContest,
				contestPath + '\n' + contest1 + baseContest	};

		std::stringstream out;

		for (int i = 0; i < cases; ++i) {
			out.str("");
			out << c[i];
			REQUIRE(out.str() == sc[i]);
		}
	}

	SECTION("All") {
		Contest contest (contestPath, true);
		std::string output;
		std::string POOAll = "../test/samples/subscsv/POOAll.csv";
		std::string POOA   = "../test/samples/subscsv/POOA.csv";
		std::string POOAF  = "../test/samples/subscsv/POOAF.csv";

		//All
		output = contest.All();
		REQUIRE(File::teststr(POOAll, output).empty());

		//Accepted
		output = contest.Accepted();
		REQUIRE(File::teststr(POOA, output).empty());

		//Accepted final
		output = contest.AcceptedFinal();
		REQUIRE(File::teststr(POOAF, output).empty());
	}
	 */
}
