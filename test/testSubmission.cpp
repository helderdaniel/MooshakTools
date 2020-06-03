/**
 * @author hdaniel@ualg.pt
 * @version 0.1
 * 27/05/2020.
 */

#include <catch2/catch.hpp>
#include <iostream>
#include "../src/Submission.hpp"

using namespace mooshak;

TEST_CASE( "Mooshak Submission", "[Submission]" ) {

	SECTION("Constructor") {
		const int cases = 4;
		const string  p[] = { "", "A", "X", "B" };
		const string  t[] = { "", "Team0", "Team1", "John Smith" };
		const Classifications c[] = { RequiresReevaluation, Accepted, WrongAnswer, RuntimeError };
		const States  s[] = { Pending, Pending, Final, Final };
		const Submission subs[] = {
			Submission(),  //for testing default construtor
			Submission(p[1], t[1], c[1], s[1]),
			Submission(p[2], t[2], c[2], s[2]),
			Submission(p[3], t[3], "Runtime Error", "final"),
		};

		const string ec[] = { "Requires Reevaluation", "Accepted", "Wrong Answer", "Runtime Error" };
		const string es[] = { "pending", "pending", "final", "final" };
		const string estr[] = {
				",,Requires Reevaluation,pending",
				"A,Team0,Accepted,pending",
				"X,Team1,Wrong Answer,final",
				"B,John Smith,Runtime Error,final"
				};

		for (int i = 0; i < cases; ++i) {
			REQUIRE(subs[i].problem() == p[i]);
			REQUIRE(subs[i].team() == t[i]);
			REQUIRE(subs[i].classify() == c[i]);
			REQUIRE(subs[i].classifys() == ec[i]);
			REQUIRE(subs[i].state() == s[i]);
			REQUIRE(subs[i].states() == es[i]);
			REQUIRE(subs[i].toString() == estr[i]);
		}
	}

}
