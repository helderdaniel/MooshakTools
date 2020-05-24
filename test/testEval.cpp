//
// Created by hdaniel on 19/05/2020.
//
#include <catch2/catch.hpp>
#include <sstream>
#include "../src/MooshakEval.hpp"


TEST_CASE( "Mooshak Evaluation", "[MooshakEval]" ) {

	SECTION("Constructor") {
		const int cases = 2;
		const MooshakEval e[] = {
				MooshakEval("run.sh", "."),
				MooshakEval("run.sh", ".", "inputf", "outputf") };

		const std::string se[] = {
				"diff: (run.sh (./input, ./output)",
				"diff: (run.sh (./inputf, ./outputf)" };

		stringstream out;

		for (int i = 0; i < cases; ++i) {
			out.str("");
			out << e[i];
			REQUIRE(out.str() == se[i]);
		}
	}

	SECTION("test") {
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
		const MooshakEval e0[] = {
					MooshakEval("../test/samples/apps/conv", "../test"),
					MooshakEval("../test/samples/apps/conv", "../test", "input", "output"),
					MooshakEval("../test/samples/apps/conv", "../test", "inp(.*)", "out(.*)") };

		const int excases = 3;
		const MooshakEval e1[] = {
					MooshakEval("../test/samples/apps/conv", "../test", "input", "__NonExistant__"),
					MooshakEval("../test/samples/apps/conv", "../test", "__NonExistant__", "output"),
					MooshakEval("../test/samples/apps/conv", "../test", "__NonExistant__", "__NonExistant__") };

		for (int i = 0; i < cases; ++i) {
			REQUIRE(e0[i].run()==expected);
		}

		for (int i = 0; i < excases-1; ++i) {
			REQUIRE_THROWS_AS(e1[i].run(), std::runtime_error);
			REQUIRE_THROWS_WITH(e1[0].run(), "Number of input and output files differ");
		}

		REQUIRE_THROWS_AS(e1[2].run(), std::runtime_error);
		REQUIRE_THROWS_WITH(e1[2].run(), "No tests found, with given regexs: \"__NonExistant__\" and \"__NonExistant__\" from root dir: ../test");
	}
}
