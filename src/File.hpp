/**
 * File utilities
 * hdaniel@ualg.pt may 2020
 */

#ifndef MOOSHAKTOOLS_FILE_H
#define MOOSHAKTOOLS_FILE_H

#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;


class File {
	static const int bufsize = 4096;  //4k page size
	static const int maxLinesize = 256;

	/**
	 * Throws exception with fname NOT found
	 *
	 * @param fname name of file NOT found
	 */
	static void fileNotFound(const std::string& fname) {
		throw std::invalid_argument(fname + "Not found");
	}

	/**
	 *
	 * @param fn0 filename of a file to open
 	 * @param fn1 filename of another file to open
	 * @param sf0 first opened file descriptor
	 * @param sf1 second opened file descriptor
	 */
	static void openFiles(const std::string& fn0, const std::string& fn1, FILE* & sf0, FILE* & sf1) {
		sf0 = fopen(fn0.c_str(), "r");
		if (!sf0) fileNotFound(fn0);

		sf1 = fopen(fn1.c_str(), "r");
		if (!sf1) fileNotFound(fn0);
	}

	/**
	 *
	 * @param sf0 first opened file descriptor
	 * @param sf1 second opened file descriptor
	 */
	static void closeFiles(FILE* sf0, FILE* sf1) {
		fclose(sf0);
		fclose(sf1);
	}

	/**
	 * @param  sf0 a file descriptor
  	 * @param  sf1 another file descriptor
 	 * @return true if both file sizes are equal
 	 */
	static bool _cmpsize(FILE* sf0, FILE* sf1) {

		//get fn0 size
		fseek(sf0, 0L, SEEK_END);
		long long sz0 = ftell(sf0);
		fseek(sf0, 0L, SEEK_SET);

		//get fn0 size
		fseek(sf1, 0L, SEEK_END);
		long long sz1 = ftell(sf1);
		fseek(sf1, 0L, SEEK_SET);

		return sz0==sz1;
	}


public:

	/**
	 * @param  fn0 filename of a file
 	 * @param  fn1 filename of another file to compare against
	 * @return true if both file sizes are equal
	 */
	static bool cmpsize(const std::string& fn0, const std::string& fn1) {
		FILE *sf0, *sf1;

		openFiles(fn0, fn1, sf0, sf1);
		bool ret = _cmpsize(sf0, sf1);
		closeFiles(sf0, sf1);
		return ret;
	}


	/**
	 * @param  fn0 filename of a file to compare
	 * @param  fn1 filename of file to compare against
	 * @return true if files fn0 and fn1 are equal
	 */
	static std::string test(const std::string& expected, const std::string& actual) {
		std::array<char, bufsize> buffer;
		std::string ret = "";
		size_t count;
		FILE *sfexp, *sfactual;

		openFiles(expected, actual, sfexp, sfactual);

		//if size differs return both files
		if (!_cmpsize(sfexp, sfactual)) {
			ret += "Expected:\n";
			do {
				count = fread(buffer.data(), 1, bufsize, sfexp);
				ret.insert(ret.end(), std::begin(buffer), std::next(std::begin(buffer), count));
			} while (count>0);

			ret += "Actual:\n";
			do {
				count = fread(buffer.data(), 1, bufsize, sfactual);
				ret.insert(ret.end(), std::begin(buffer), std::next(std::begin(buffer), count));
			} while (count>0);
		}

		closeFiles(sfexp, sfactual);
		return ret;
	}



	/**
	 * @param  fn0 filename of a file to compare
	 * @param  fn1 filename of file to compare against
	 * @return true if files fn0 and fn1 are equal
	 */
	static bool cmpbin(const std::string& fn0, const std::string& fn1) {
		std::array<char, bufsize> buf0;
		std::array<char, bufsize> buf1;
		bool ret = true;
		size_t count0, count1;
		FILE *sf0, *sf1;

		openFiles(fn0, fn1, sf0, sf1);

		//false if size differs
		if (!_cmpsize(sf0, sf1)) return false;

		//files are same size if reaches here
		do {
			count0 = fread(buf0.data(), 1, bufsize, sf0);
			count1 = fread(buf1.data(), 1, bufsize, sf1);

			//Something wrong when reading
			//since files have same size here
			if (count0!=count1) throw std::runtime_error("fread() error: " + std::to_string(errno));

			for (int i=0; i < count0; i++)
				if (buf0[i] != buf1[i])	{
					ret = false;
					break;
				}

		} while (count0>0);


		closeFiles(sf0, sf1);
		return ret;
	}


	/**
	 *
	 * @param fn0 filename of a file to compare
	 * @param fn1 filename of file to compare against
	 * @return string with differences in both files:
	 * 				<line>:
	 * 				<fn0 line>
	 * 				<fn1 line>
	 */
	static std::string cmptext(const std::string& fn0, const std::string& fn1) {
		std::array<char, maxLinesize> buf0;
		std::array<char, maxLinesize> buf1;
		std::string ret = "";
		int line = 0;
		char *str0, *str1;
		FILE *sf0, *sf1;

		openFiles(fn0, fn1, sf0, sf1);
		for(;;) {
			str0 = fgets(buf0.data(), maxLinesize, sf0);
			str1 = fgets(buf1.data(), maxLinesize, sf1);

			//both NULL end (empty files are equal)
			if (!str0 && !str1) break;

			//default false (if one is null)
			int equal=0;

			//General case (both NOT null)
			if (str0 && str1) equal = !strcmp(str0, str1);

			//if different
			if (!equal) {
				char head[10];
				sprintf(head, "%d:\n", line);
				ret += head;
				if (str0 != NULL) ret += buf0.data();
				if (str1 != NULL) ret += buf1.data();
			}

			++line;
		}

		closeFiles(sf0, sf1);
		return ret;
	}


	/**
	 *
	 * @param dir    root dir to search
	 * @param regex  filename regex
	 * @return vector of paths that matches regex, form root directory dir
	 */
	static std::vector<fs::path> search(const std::string& dir, const std::string& regex) {
		std::vector<fs::path> v;

		for(auto& p: fs::recursive_directory_iterator(dir)) {
			if (std::regex_match(p.path().filename().c_str(), std::regex(regex)))
				v.push_back(p.path());

		}
		return v;
	}

};


#endif //MOOSHAKTOOLS_FILE_H
