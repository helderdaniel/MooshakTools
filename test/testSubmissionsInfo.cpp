//
// Created by hdaniel on 25/05/2020.
//

#include <catch2/catch.hpp>
#include <sstream>
#include "../src/SubmissionsInfo.hpp"

using namespace mooshak;

TEST_CASE( "Mooshak SubmissionsInfo", "[SubmissionsInfo]" ) {
	std::string contestsPath = "../test/samples/contests/";
	std::string contestRoot = contestsPath + "POO1920";
	std::string filterFN0 = contestsPath + "filterPOO1920.txt";
	std::string filterFN1 = contestsPath + "filterPOO1920noExistent.txt";
	std::string filterFN2 = contestsPath + "filterPOO1920bad.txt";

	SECTION("Constructor") {
		const int cases = 2;
		const SubmissionsInfo c[] = {
				SubmissionsInfo(contestRoot),
				SubmissionsInfo(contestRoot, filterFN0)};

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


		//I/O error opening filter
		REQUIRE_THROWS_AS(SubmissionsInfo(contestRoot, filterFN1), runtime_error);
		REQUIRE_THROWS_WITH(SubmissionsInfo(contestRoot, filterFN1), "I/O error opening filter");

		//Bad filter format
		REQUIRE_THROWS_AS(SubmissionsInfo(contestRoot, filterFN2), runtime_error);
		REQUIRE_THROWS_WITH(SubmissionsInfo(contestRoot, filterFN2), "bad filter format");
	}


	SECTION("Listings") {
		SubmissionsInfo contest(contestRoot, filterFN0);
		std::stringstream ss;
		std::string s;
		std::string POOAll = "../test/samples/mapscsv/POOAll.csv";
		std::string POOA = "../test/samples/mapscsv/POOA.csv";
		std::string POOAF = "../test/samples/mapscsv/POOAF.csv";
		std::string POOFail = "../test/samples/mapscsv/POOFail.csv";
		std::string POOFailT = "../test/samples/mapscsv/POOFailT.csv";
		std::string POOFailTA = "../test/samples/mapscsv/POOFailTA.csv";

		//All
		contest.All(ss);
		REQUIRE(File::teststr(POOAll, ss.str()).empty());
		s = contest.All();
		REQUIRE(File::teststr(POOAll, s).empty());
		string ret;
		contest.foreach([&](const Submission &s){ ret += to_string(s) + '\n'; } );
		REQUIRE(File::teststr(POOAll, s).empty());

		//Accepted
		ss.str("");  //clear ss
		contest.Accepted(ss);
		REQUIRE(File::teststr(POOA, ss.str()).empty());
		s = contest.Accepted();
		REQUIRE(File::teststr(POOA, s).empty());

		//Accepted final
		ss.str("");  //clear ss
		contest.AcceptedFinal(ss);
		REQUIRE(File::teststr(POOAF, ss.str()).empty());
		s = contest.AcceptedFinal();
		REQUIRE(File::teststr(POOAF, s).empty());

		//Failed
		ss.str("");  //clear ss
		contest.Failed(ss);
		REQUIRE(File::teststr(POOFail, ss.str()).empty());

		//Failed by type
		ss.str("");  //clear ss
		contest.FailedType(ss);
		REQUIRE(File::teststr(POOFailT, ss.str()).empty());

		//Failed Accepted
		ss.str("");  //clear ss
		contest.FailedTypeAccepted(ss);
		REQUIRE(File::teststr(POOFailTA, ss.str()).empty());
	}

	SECTION("count") {
		SubmissionsInfo contest(contestRoot, filterFN0);
		std::stringstream ss;
		std::string POOAllc = "../test/samples/mapscsv/POOAllc.map";
		std::string POOFinalc = "../test/samples/mapscsv/POOFinalc.map";

		//Count All
		ss.str("");  //clear ss
		contest.reportAll(ss);
		REQUIRE(File::teststr(POOAllc, ss.str()).empty());

		//Count All Final
		ss.str("");  //clear ss
		contest.reportFinal(ss);
		REQUIRE(File::teststr(POOFinalc, ss.str()).empty());
	}
}