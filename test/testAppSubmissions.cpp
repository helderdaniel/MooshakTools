/**
 * @author hdaniel@ualg.pt
 * @version 0.1
 * 15/06/2020.
 */

#include <catch2/catch.hpp>
#include <iostream>
#include "../apps/submissionApp.hpp"
#include <appTest/AppTest.hpp>

using std::string;
using had::AppTest;
using namespace mooshak;

TEST_CASE( "Submissions Info app", "[submissions]" ) {

	AppTest apptest;

	const char* noFile = "__fileNotExisting__";
	const char* contestPath = "../test/samples/contests/POO1920";
	const char* filterPath = "../test/samples/contests/filterPOO1920.txt";
	const char* appPath = "./submissions";
	AppTest::cmdlineargs errorNumArgs = { appPath };
	AppTest::cmdlineargs errorUnknownOP = { appPath, contestPath, "WRONG", filterPath };
	AppTest::cmdlineargs errorContest = { appPath, noFile, "A", filterPath };
	AppTest::cmdlineargs errorFilter = { appPath, contestPath, "A", noFile };
	AppTest::cmdlineargs errorBoth = { appPath, noFile, "A", noFile };

	string errorUsage(
     "Usage: submissions <contest path> <operation> [<filter path>]\n\n"
        "Operation:\n"
        "Accepted          list only \"Accepted\" submissions\n"
        "AcceptedFinal     list only \"Accepted\" and \"final\" submissions\n"
        "All               list all submissions\n"
        "Fail              list failed submissions\n"
        "FailType          list failed submissions grouped by type\n"
        "AcceptedFailType  list failed submissions grouped by type, only if team as one \"Accepted\" submission to the problem\n"
        "                  (used to get info from Mooshak to assessment sheets)\n"
        "mapAll            map counter of all submissions classification for each problem\n"
        "mapFinal          map counter of all submissions classification for each problem, marked as \"final\"\n"
        "mapCountUnique         map counter of different persons that have submitted, have accepted and have accepted marked as \"final\"\n");

    string errorOP("Unknown operation 'WRONG' Valid operations are:\n"
				   "All\n"
				   "Accepted\n"
				   "AcceptedFinal\n"
				   "Fail\n"
				   "FailType\n"
				   "AcceptedFailType\n"
				   "mapAll\n"
				   "mapFinal\n"
                   "mapUnique\n");

	SECTION("Cmd line Arguments") {
		apptest.clearOUTstream();
		apptest.exec(subsmain, errorNumArgs);
		REQUIRE(apptest.outStream() == errorUsage);

		apptest.clearOUTstream();
		apptest.exec(subsmain, errorUnknownOP);
		REQUIRE(apptest.outStream() == errorOP);

		REQUIRE_THROWS_AS(apptest.exec(subsmain, errorContest), std::runtime_error);
		REQUIRE_THROWS_AS(apptest.exec(subsmain, errorFilter), std::runtime_error);
		REQUIRE_THROWS_AS(apptest.exec(subsmain, errorBoth), std::runtime_error);
	}

	SECTION("Operations") {
		std::string POOAll = "../test/samples/mapscsv/POOAll.csv";
		std::string POOA = "../test/samples/mapscsv/POOA.csv";
		std::string POOAF = "../test/samples/mapscsv/POOAF.csv";
		std::string POOFail = "../test/samples/mapscsv/POOFail.csv";
		std::string POOFailT = "../test/samples/mapscsv/POOFailT.csv";
		std::string POOFailTA = "../test/samples/mapscsv/POOFailTA.csv";
		std::string POOAllc = "../test/samples/mapscsv/POOAllc.map";
		std::string POOFinalc = "../test/samples/mapscsv/POOFinalc.map";
        std::string POOUniquec = "../test/samples/mapscsv/POOUniquec.map";

		apptest.clearOUTstream();
		AppTest::cmdlineargs path0 = { appPath, contestPath, "All", filterPath };
		apptest.exec(subsmain, path0);
		REQUIRE(File::teststr(POOAll, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path1 = { appPath, contestPath, "Accepted", filterPath };
		apptest.exec(subsmain, path1);
		REQUIRE(File::teststr(POOA, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path2 = { appPath, contestPath, "AcceptedFinal", filterPath };
		apptest.exec(subsmain, path2);
		REQUIRE(File::teststr(POOAF, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path3 = { appPath, contestPath, "Fail", filterPath };
		apptest.exec(subsmain, path3);
		REQUIRE(File::teststr(POOFail, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path4 = { appPath, contestPath, "FailType", filterPath };
		apptest.exec(subsmain, path4);
		REQUIRE(File::teststr(POOFailT, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path5 = { appPath, contestPath, "AcceptedFailType", filterPath };
		apptest.exec(subsmain, path5);
		REQUIRE(File::teststr(POOFailTA, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path6 = { appPath, contestPath, "mapAll", filterPath };
		apptest.exec(subsmain, path6);
		REQUIRE(File::teststr(POOAllc, apptest.outStream()).empty());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path7 = { appPath, contestPath, "mapFinal", filterPath };
		apptest.exec(subsmain, path7);
		REQUIRE(File::teststr(POOFinalc, apptest.outStream()).empty());

        apptest.clearOUTstream();
        AppTest::cmdlineargs path8= { appPath, contestPath, "mapUnique", filterPath };
        apptest.exec(subsmain, path8);
        REQUIRE(File::teststr(POOUniquec, apptest.outStream()).empty());
	}

}
