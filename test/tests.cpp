//
// Created by hdaniel on 19/05/2020.
//
#include <catch2/catch.hpp>
#include <sstream>
#include "../src/MooshakEval.hpp"


TEST_CASE( "Mooshak Evaluation", "[MooshakEval]" ) {
	MooshakEval e0("run.sh");
	MooshakEval e1("run.sh", "inputf", "outputf");

	string se0 = "diff: (run.sh < input , output)";
	string se1 = "diff: (run.sh < inputf , outputf)";


	SECTION("Constructor") {
		stringstream out;
		out << e0;
		REQUIRE(out.str() == se0);

		out.str("");
		out << e1;
		REQUIRE(out.str() == se1);
	}
}
