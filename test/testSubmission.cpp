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

	SECTION("Constructor") {
		const int cases = 2;
		const string  p[] = { "A", "X" };
		const string  t[] = { "Team0", "Team1" };
		const Results c[] = { Accepted, WrongAnswer };
		const States  s[] = { Pending, Final };
		const Submission subs[] = {
				Submission(p[0], t[0], c[0], s[0]),
				Submission(p[1], t[1], c[1], s[1])
		};
		const string ec[] = { ResultsString[c[0]], ResultsString[c[1]] };
		const string es[] = { StatesString[s[0]], StatesString[s[1]] };

		for (int i = 0; i < cases; ++i) {
			REQUIRE(subs[i].problem() == p[i]);
			REQUIRE(subs[i].team() == t[i]);
			REQUIRE(subs[i].classify() == c[i]);
			REQUIRE(subs[i].classifys() == ec[i]);
			REQUIRE(subs[i].state() == s[i]);
			REQUIRE(subs[i].states() == es[i]);
		}
	}

}
