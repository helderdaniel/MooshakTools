//
// Created by hdaniel on 19/05/2020.
//
#include <catch2/catch.hpp>
#include "../src/File.hpp"

const std::string path   = "../test/samples/files/";

std::string searchPathToString(const std::string& dir, const std::string& regex) {
	std::vector<fs::path> v;
	std::string ret = "";

	v = File::search(dir, regex);
	sort(v.begin(), v.end());
	for (const auto& p : v) {
		ret += p;
		ret += '\n';
	}
	return ret;
}

TEST_CASE( "Search" "[File]" ) {
	const std::string expA =
						"../test/samples/files/file0.txt\n"
				      	"../test/samples/files/file1.txt\n"
		 			  	"../test/samples/files/file2.txt\n"
					  	"../test/samples/files/file2n.txt\n";
	const std::string expB =
						"../test/samples/files/inner/file0.txt\n";

	const int cases = 3;
	const std::string expected[] = {
						"",
						expA + expB,
						expA +
					   	"../test/samples/files/file3.txt\n"
					   	"../test/samples/files/file3e.txt\n"
					   	"../test/samples/files/file3n.txt\n"
					   	"../test/samples/files/file4.txt\n"
					   	+ expB };

	const std::string regex[] = {
						"",					//null
						"file[0-2](.*)",	//filenames started with: "file[0-2]"
						"(.*)txt" };        //filenames ended with:   "txt"

	for (int i = 0; i < cases; ++i) {
		auto s = searchPathToString(path, regex[i]);
		REQUIRE(expected[i] == s);
	}
}


TEST_CASE( "Compare" "[File]" ) {
	const std::string file0  = path + "file0.txt";
	const std::string file1  = path + "file1.txt";
	const std::string file2  = path + "file2.txt";
	const std::string file2n = path + "file2n.txt";
	const std::string file3  = path + "file3.txt";
	const std::string file3e = path + "file3e.txt";
	const std::string file3n = path + "file3n.txt";
	const std::string file4  = path + "file4.txt";
	const std::string fileNE = "__NotExist__";
	const std::string fileNull = "";

	SECTION("Not found") {
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNull, file0),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(file0, fileNull),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNull, fileNull),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNE, file0),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(file0, fileNE),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNE, fileNE),
				std::invalid_argument);

		REQUIRE_THROWS_AS(
				File::cmptext(fileNull, file0),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(file0, fileNull),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNull, fileNull),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNE, file0),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(file0, fileNE),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNE, fileNE),
				std::invalid_argument);
	}

	SECTION("Size") {
		REQUIRE(File::cmpsize(file0, file0));
		REQUIRE(File::cmpsize(file3, file3e));
		REQUIRE(File::cmpsize(file0, file1) == false);
		REQUIRE(File::cmpsize(file2, file2n) == false);
	}

	SECTION("Binary") {
		REQUIRE(File::cmpbin(file0, file0));
		REQUIRE(File::cmpbin(file3, file3e));
		REQUIRE(File::cmpbin(file0, file1) == false);
		REQUIRE(File::cmpbin(file2, file2n) == false);
	}

	SECTION("Text") {
		const std::string s01 =
							"0:\n"
						   	"one\n";
		const std::string s22n =
							"2:\n"
					       	"\n";
		const std::string s33n =
							"1:\n"
					       	"two\n"
						   	"two!\n";
		const std::string s13n =
							"1:\n"
						   	"two\n"
		 				   	"2:\n"
						   	"three\n";
		const std::string s34n =
							"0:\n"
						   	"one\n"
						   	"one,\n"
						   	"2:\n"
						   	"three\n"
						   	"three,\n"
						   	"3:\n"
						   	"four\n";
		const std::string s43n =
							"0:\n"
						   	"one,\n"
						   	"one\n"
						   	"2:\n"
						   	"three,\n"
						   	"three\n"
						   	"3:\n"
		 				   	"four\n";

	   	//Equal files
		REQUIRE(File::cmptext(file0, file0) == "");
		REQUIRE(File::cmptext(file3, file3e) == "");

		//Different files
		REQUIRE(File::cmptext(file0, file1) == s01);
		REQUIRE(File::cmptext(file1, file0) == s01);

		REQUIRE(File::cmptext(file2, file2n) == s22n);
		REQUIRE(File::cmptext(file3, file3n) == s33n);

		REQUIRE(File::cmptext(file1, file3) == s13n);
		REQUIRE(File::cmptext(file3, file1) == s13n);

		//Different files and different report if diff order
		REQUIRE(File::cmptext(file3, file4) == s34n);
		REQUIRE(File::cmptext(file4, file3) == s43n);
	}

	SECTION("Test") {
		const std::string s01 =
				"Expected:\n"
				"Actual:\n"
				"one\n";
		const std::string s10 =
				"Expected:\n"
				"one\n"
				"Actual:\n";
		const std::string s34n =
				"Expected:\n"
				"one\n"
				"two\n"
				"three\n"
				"Actual:\n"
				"one,\n"
				"two\n"
				"three,\n"
				"four\n";
		const std::string s43n =
				"Expected:\n"
				"one,\n"
				"two\n"
				"three,\n"
				"four\n"
				"Actual:\n"
				"one\n"
				"two\n"
				"three\n";

		//Equal files
		REQUIRE(File::test(file0, file0) == "");
		REQUIRE(File::test(file3, file3e) == "");

		//Different files
		REQUIRE(File::test(file0, file1) == s01);
		REQUIRE(File::test(file1, file0) == s10);

		//Different files and different report if diff order
		REQUIRE(File::test(file3, file4) == s34n);
		REQUIRE(File::test(file4, file3) == s43n);
	}
}
