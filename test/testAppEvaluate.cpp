/**
 * @author hdaniel@ualg.pt
 * @version 0.1
 * 16/06/2020.
 */

#include <catch2/catch.hpp>
#include <iostream>
#include "../apps/evaluateApp.hpp"
#include <appTest/AppTest.hpp>

using std::string;
using had::AppTest;
using namespace mooshak;


TEST_CASE( "Evaluation app", "[evaluation]" ) {

	AppTest apptest;

	const char* noFile = "__fileNotExisting__";
	const char* inputFN = "input";
	const char* outputFN = "output";
	const char* testexe = "../test/samples/apps/conv";
	const char* testspath = "../test/samples/tests";
	const char* appPath = "./evaluate";
	AppTest::cmdlineargs errorNumArgs = { appPath };
	AppTest::cmdlineargs errorEXE = { appPath, noFile, testspath };
	AppTest::cmdlineargs errorTest = { appPath, testexe, noFile };

	string errorUsage("Usage: evaluate <path to executable> <path to root of tests> "
					  "[<input fname regex=input> <output fname regex=output>]\n" );

	string testOK(
			"../test/samples/apps/conv < ../test/samples/tests/T0/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T1/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T2/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T3/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T3forceerror/input\n"
			"Expected:\n"
			"2.00\n"
			"5.00\n"
			"10.00\n"
			"8.00\n"
			"7.00\n"
			"3.00\n"
			"Actual:\n"
			"2.00\n"
			"5.00\n"
			"10.00\n"
			"8.00\n"
			"8.00\n"
			"3.00\n"
			"../test/samples/apps/conv < ../test/samples/tests/T4/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T5/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T6/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T7/input\n"
			"../test/samples/apps/conv < ../test/samples/tests/T8/input\n"
	);


	SECTION("Cmd line Arguments") {
		apptest.clearOUTstream();
		apptest.exec(evalmain, errorNumArgs);
		REQUIRE(apptest.outStream() == errorUsage);

		REQUIRE_THROWS_AS(apptest.exec(evalmain, errorEXE), std::runtime_error);
		REQUIRE_THROWS_AS(apptest.exec(evalmain, errorTest), std::runtime_error);
	}

	SECTION("Operation") {
		apptest.clearOUTstream();
		AppTest::cmdlineargs path0 = { appPath, testexe, testspath };
		apptest.exec(evalmain, path0);
		REQUIRE(testOK == apptest.outStream());

		apptest.clearOUTstream();
		AppTest::cmdlineargs path1 = { appPath, testexe, testspath, inputFN, outputFN };
		apptest.exec(evalmain, path1);
		REQUIRE(testOK == apptest.outStream());
	}


}
