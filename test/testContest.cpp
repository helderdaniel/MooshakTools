//
// Created by hdaniel on 25/05/2020.
//

#include <catch2/catch.hpp>
#include <sstream>
#include "../src/Contest.hpp"

using namespace mooshak;

TEST_CASE( "Mooshak Contest", "[Contest]" ) {
	std::string contestsPath = "../test/samples/contests/";
	std::string contestRoot = contestsPath + "POO1920";
	std::string filterFN0 = contestsPath + "filterPOO1920.txt";
	std::string filterFN1 = contestsPath + "filterPOO1920bad.txt";

	SECTION("Constructor") {
		const int cases = 2;
		const Contest c[] = {
				Contest(contestRoot),
				Contest(contestRoot, filterFN0)};

		std::string contest0 = "0\n";
		std::string contest1 = "1\n";
		std::string baseContest =
				contestRoot + "/problems\n" +
				contestRoot + "/submissions\n"
							  "P1 A\n"
							  "P2 B\n"
							  "P3 C\n"
							  "P4 D\n"
							  "P5 E\n"
							  "P6 F\n"
							  "P7 G\n"
							  "P8 H\n";

		const std::string sc[] = {
				contestRoot + '\n' + contest0 + baseContest,
				contestRoot + '\n' + contest1 + baseContest};

		std::stringstream out;

		for (int i = 0; i < cases; ++i) {
			out.str("");
			out << c[i];
			REQUIRE(out.str() == sc[i]);
		}


		//Bad filter format
		REQUIRE_THROWS_AS(Contest(contestRoot, filterFN1), runtime_error);
		REQUIRE_THROWS_WITH(Contest(contestRoot, filterFN1), "bad filter format");
	}


	SECTION("Listings") {
		Contest contest(contestRoot, filterFN0);
		std::stringstream ss;
		std::string POOAll = "../test/samples/subscsv/POOAll.csv";
		std::string POOA = "../test/samples/subscsv/POOA.csv";
		std::string POOAF = "../test/samples/subscsv/POOAF.csv";

		//All
		contest.All(ss);
		//File::write("test.txt", ss.str());
		REQUIRE(File::teststr(POOAll, ss.str()).empty());

		//Accepted
		ss.str("");  //clear ss
		contest.Accepted(ss);
		REQUIRE(File::teststr(POOA, ss.str()).empty());

		//Accepted final
		ss.str("");  //clear ss
		contest.AcceptedFinal(ss);
		REQUIRE(File::teststr(POOAF, ss.str()).empty());
	}
}