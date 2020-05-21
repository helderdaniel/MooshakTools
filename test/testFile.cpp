//
// Created by hdaniel on 19/05/2020.
//
#include <catch2/catch.hpp>
#include "../src/File.hpp"
#include <cstring>

TEST_CASE( "Search" "[File]" ) {
	std::vector<fs::path> fv0;
	std::string s = "";
	std::string exp = "../test/samples/files/file0.txt\n"
				      "../test/samples/files/file1.txt\n"
		  			  "../test/samples/files/inner/file0.txt\n"
		 			  "../test/samples/files/file2.txt\n"
					  "../test/samples/files/file2n.txt\n";

	fv0 = File::search("../test/samples/files", "file[0-2](.*)");
	for (const auto& p : fv0) {
		s += p;
		s += '\n';
	}

	REQUIRE(exp == s);
}

TEST_CASE( "Compare" "[File]" ) {
	std::string path   = "../test/samples/files/";
	std::string file0  = path + "file0.txt";
	std::string file1  = path + "file1.txt";
	std::string file2  = path + "file2.txt";
	std::string file2n = path + "file2n.txt";
	std::string file3  = path + "file3.txt";
	std::string file3e = path + "file3e.txt";
	std::string file3n = path + "file3n.txt";
	std::string file4  = path + "file4.txt";
	std::string fileNE = "__NotExist__";
	std::string fileNull = "";

	SECTION("Not found") {
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNull.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(file0.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNull.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNE.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(file0.c_str(), fileNE.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmpbin(fileNE.c_str(), fileNE.c_str()),
				std::invalid_argument);

		REQUIRE_THROWS_AS(
				File::cmptext(fileNull.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(file0.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNull.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNE.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(file0.c_str(), fileNE.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				File::cmptext(fileNE.c_str(), fileNE.c_str()),
				std::invalid_argument);
	}


	SECTION("Binary") {
		REQUIRE(File::cmpbin(file0.c_str(), file0.c_str()));
		REQUIRE(File::cmpbin(file3.c_str(), file3e.c_str()));
		REQUIRE(File::cmpbin(file0.c_str(), file1.c_str()) == false);
		REQUIRE(File::cmpbin(file2.c_str(), file2n.c_str()) == false);
	}

	SECTION("Text") {
		std::string s01  = "0:\n"
						   "one\n";
		std::string s22n = "2:\n"
					       "\n";
		std::string s33n = "1:\n"
					       "two\n"
						   "two!\n";
		std::string s13n = "1:\n"
						   "two\n"
		 				   "2:\n"
						   "three\n";
		std::string s34n = "0:\n"
						   "one\n"
						   "one,\n"
						   "2:\n"
						   "three\n"
						   "three,\n"
						   "3:\n"
						   "four\n";
		std::string s43n = "0:\n"
						   "one,\n"
						   "one\n"
						   "2:\n"
						   "three,\n"
						   "three\n"
						   "3:\n"
		 				   "four\n";

	   	//Equal files
		REQUIRE(File::cmptext(file0.c_str(), file0.c_str()) == "");
		REQUIRE(File::cmptext(file3.c_str(), file3e.c_str()) == "");

		//Different files
		REQUIRE(File::cmptext(file0.c_str(), file1.c_str()) == s01);
		REQUIRE(File::cmptext(file1.c_str(), file0.c_str()) == s01);

		REQUIRE(File::cmptext(file2.c_str(), file2n.c_str()) == s22n);
		REQUIRE(File::cmptext(file3.c_str(), file3n.c_str()) == s33n);

		REQUIRE(File::cmptext(file1.c_str(), file3.c_str()) == s13n);
		REQUIRE(File::cmptext(file3.c_str(), file1.c_str()) == s13n);

		//Different files and different report if diff order
		REQUIRE(File::cmptext(file3.c_str(), file4.c_str()) == s34n);
		REQUIRE(File::cmptext(file4.c_str(), file3.c_str()) == s43n);
	}
}
