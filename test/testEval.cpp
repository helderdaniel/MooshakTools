//
// Created by hdaniel on 19/05/2020.
//

#include <catch2/catch.hpp>
#include <sstream>
#include "../src/MooshakEval.hpp"


TEST_CASE( "Mooshak Evaluation", "[MooshakEval]" ) {
	const int cases = 2;
	const MooshakEval e[] =
			{ MooshakEval("run.sh"),
			  MooshakEval("run.sh", "inputf", "outputf") };

	const std::string se[] =
			{ "diff: (run.sh < input , output)",
		      "diff: (run.sh < inputf , outputf)" };

	stringstream out;

	SECTION("Constructor") {
		for (int i = 0; i < cases; ++i) {
			out.str("");
			out << e[i];
			REQUIRE(out.str() == se[i]);
		}
	}
}
