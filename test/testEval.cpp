//
// Created by hdaniel on 19/05/2020.
//

#include <catch2/catch.hpp>
#include "../src/Evaluate.hpp"

using namespace mooshak;

TEST_CASE( "Mooshak Evaluation", "[Evaluate]" ) {

	SECTION("Constructor") {
		const int cases = 2;
		const Evaluate e[] = {
				Evaluate("run.sh", "."),
				Evaluate("run.sh", ".", "inputf", "outputf") };

		const std::string se[] = {
				"diff: (run.sh (./input, ./output)",
				"diff: (run.sh (./inputf, ./outputf)" };

		std::stringstream out;

		for (int i = 0; i < cases; ++i) {
			out.str("");
			out << e[i];
			REQUIRE(out.str() == se[i]);
		}
	}

	SECTION("test") {
		std::string testexe = "../test/samples/apps/conv";
		std::string testspath = "../test/samples/tests";
		std::string expected =
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
				"../test/samples/apps/conv < ../test/samples/tests/T8/input\n";

		const int cases = 3;
		const Evaluate e0[] = {
				Evaluate(testexe, testspath),
				Evaluate(testexe, testspath, "input", "output"),
				Evaluate(testexe, testspath, "inp(.*)", "out(.*)")
					};

		const int excases = 3;
		const Evaluate e1[] = {
				Evaluate(testexe, testspath, "input", "__NonExistant__"),
				Evaluate(testexe, testspath, "__NonExistant__", "output"),
				Evaluate(testexe, testspath, "__NonExistant__", "__NonExistant__") };

		for (int i = 0; i < cases; ++i) {
			REQUIRE(e0[i].run()==expected);
		}

		for (int i = 0; i < excases-1; ++i) {
			REQUIRE_THROWS_AS(e1[i].run(), std::runtime_error);
			REQUIRE_THROWS_WITH(e1[0].run(), "Number of input and output files differ");
		}

		REQUIRE_THROWS_AS(e1[2].run(), std::runtime_error);
		REQUIRE_THROWS_WITH(e1[2].run(), "No tests found, with given regexs: \"__NonExistant__\" and \"__NonExistant__\" from root dir: " + testspath);
	}
}
