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
        const string  m[] = { "20", "10", "30", "-10" };
        const string  t[] = { "", "Team0", "Team1", "John Smith" };
        const Classifications c[] = { RequiresReevaluation, Accepted, WrongAnswer, RuntimeError };
		const States  s[] = { Pending, Pending, Final, Final };
		const Submission subs[] = {
			Submission(),  //for testing default construtor
			Submission(p[1], t[1], c[1], m[1], s[1]),
			Submission(p[2], t[2], c[2], m[2], s[2]),
			Submission(p[3], t[3], "Runtime Error", m[3], "final"),
		};

		const string ec[] = { "Requires Reevaluation", "Accepted", "Wrong Answer", "Runtime Error" };
		const string es[] = { "pending", "pending", "final", "final" };
		const bool   ef[] = { false, false, true, true };
		const bool   eFail[] = { true, false, true, true };
		const string estr[] = {
				",,,Requires Reevaluation,pending",
				"A,Team0,10,Accepted,pending",
				"X,Team1,30,Wrong Answer,final",
				"B,John Smith,-10,Runtime Error,final"
				};

		for (int i = 0; i < cases; ++i) {
			REQUIRE(subs[i].problem() == p[i]);
			REQUIRE(subs[i].team() == t[i]);
			REQUIRE(subs[i].classification() == c[i]);
			REQUIRE(subs[i].classificationStr() == ec[i]);
			REQUIRE(subs[i].state() == s[i]);
			REQUIRE(subs[i].stateStr() == es[i]);
			REQUIRE(subs[i].isFailure() == eFail[i]);
			REQUIRE(subs[i].isFinal() == ef[i]);
			REQUIRE(to_string(subs[i]) == estr[i]);
		}


	}

	SECTION("Converters") {
		REQUIRE(Submission::classificationStr(Accepted) == "Accepted");
		REQUIRE(Submission::classifications("Accepted") == Accepted);
		REQUIRE_THROWS_AS(Submission::classifications(""),std::out_of_range);

		REQUIRE(Submission::stateStr(Final) == "final");
		REQUIRE(Submission::states("final") == Final);
		REQUIRE_THROWS_AS(Submission::states(""),std::out_of_range);
	}

    SECTION("Relational operators") {
        Submission s0;
        Submission s2("A", "a12345", Accepted, "20", Final );
        Submission s3("A", "a12346", Accepted, "20", Final );
        Submission s4("A", "a12345", Evaluating, "20", Final );
        Submission s5("A", "a12345", Accepted, "20", Pending );
        Submission s1("A", "a12345", Accepted, "20", Final );
        Submission s6("B", "a12345", Accepted, "20", Final );
        Submission s7("A", "a00000", Accepted, "20", Final );

        //Relational operators and CompareSubmissionPointers predicate
        REQUIRE(s0==s0);
        REQUIRE(s1==s1);
        REQUIRE(s1==s2);

        REQUIRE(s0!=s1);
        REQUIRE(s1!=s3);

        CompareSubmissionPointers cmp;
        REQUIRE(cmp.operator()(&s0,&s0));
        REQUIRE(cmp.operator()(&s1,&s1));
        REQUIRE(cmp.operator()(&s1,&s2));
        REQUIRE(!cmp.operator()(&s0,&s1));
        REQUIRE(!cmp.operator()(&s1,&s3));

        REQUIRE(s0<s1);
        REQUIRE(s2<s3);
        REQUIRE(s2<s4);
        REQUIRE(s2<s5);
        REQUIRE(s2<s6);

        REQUIRE(s7<s2);
	}
}
