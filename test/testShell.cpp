//
// Created by hdaniel on 22/05/2020.
//

#include <catch2/catch.hpp>
#include <sstream>
#include "../src/Shell.hpp"

TEST_CASE( "Shell utilities", "[Shell]" ) {
	const std::string path = "../test/samples/files/";

	const int cases = 2;
	const std::string cmd[] =
			{ "ls " + path,				//command OK
			  "_DoNotExist_ 2>&1" };	//Command NOT found error on stderr

	std::string outputExpected[] =
			{	"file0.txt\n"
   				"file1.txt\n"
				"file2n.txt\n"
				"file2.txt\n"
				"file3e.txt\n"
				"file3nes.txt\n"
				"file3n.txt\n"
				"file3.txt\n"
				"file4.txt\n"
				"inner\n",

				"sh: 1: _DoNotExist_: not found\n" };

	int error[] = { 0, 0x7F00 };

	std::string output = "just to make sure it is cleaned by ::execute()";

	SECTION("Execute cmd line") {
		for (int i = 0; i < cases; ++i) {
			int code = Shell::execute(cmd[i], output);
			REQUIRE(output == outputExpected[i]);
			REQUIRE(code == error[i]);
		}
	}
}
