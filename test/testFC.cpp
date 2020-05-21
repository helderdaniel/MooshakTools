//
// Created by hdaniel on 19/05/2020.
//
#include <catch2/catch.hpp>
#include "../src/FileCompare.hpp"
#include <cstring>


TEST_CASE( "Mooshak Evaluation", "[MooshakEval]" ) {
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
			FileCompare::binary(fileNull.c_str(), file0.c_str()),
			std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::binary(file0.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::binary(fileNull.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::binary(fileNE.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::binary(file0.c_str(), fileNE.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::binary(fileNE.c_str(), fileNE.c_str()),
				std::invalid_argument);

		REQUIRE_THROWS_AS(
				FileCompare::text(fileNull.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::text(file0.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::text(fileNull.c_str(), fileNull.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::text(fileNE.c_str(), file0.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::text(file0.c_str(), fileNE.c_str()),
				std::invalid_argument);
		REQUIRE_THROWS_AS(
				FileCompare::text(fileNE.c_str(), fileNE.c_str()),
				std::invalid_argument);
	}


	SECTION("Binary") {
		REQUIRE(FileCompare::binary(file0.c_str(), file0.c_str()));
		REQUIRE(FileCompare::binary(file3.c_str(), file3e.c_str()));
		REQUIRE(FileCompare::binary(file0.c_str(), file1.c_str()) == false);
		REQUIRE(FileCompare::binary(file2.c_str(), file2n.c_str()) == false);
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
		REQUIRE(FileCompare::text(file0.c_str(), file0.c_str()) == "");
		REQUIRE(FileCompare::text(file3.c_str(), file3e.c_str()) == "");

		//Different files
		REQUIRE(FileCompare::text(file0.c_str(), file1.c_str()) == s01);
		REQUIRE(FileCompare::text(file1.c_str(), file0.c_str()) == s01);

		REQUIRE(FileCompare::text(file2.c_str(), file2n.c_str()) == s22n);
		REQUIRE(FileCompare::text(file3.c_str(), file3n.c_str()) == s33n);

		REQUIRE(FileCompare::text(file1.c_str(), file3.c_str()) == s13n);
		REQUIRE(FileCompare::text(file3.c_str(), file1.c_str()) == s13n);

		//Different files and different report if diff order
		REQUIRE(FileCompare::text(file3.c_str(), file4.c_str()) == s34n);
		REQUIRE(FileCompare::text(file4.c_str(), file3.c_str()) == s43n);
	}
}
