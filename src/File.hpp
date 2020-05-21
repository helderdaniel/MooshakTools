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
	static void fileNotFound(std::string fname) {
		throw std::invalid_argument(fname + "Not found");
	}

public:

	/**
	 * @param  fn0 filename of a file to compare
	 * @param  fn1 filename of file to compare against
	 * @return true if files are equal
	 */
	static bool cmpbin(const char *fn0, const char *fn1) {
		char buf0[bufsize];
		char buf1[bufsize];
		bool ret = true;
		int lf0, lf1;

		int f0 = open(fn0, O_RDONLY);
		if (f0 < 0) fileNotFound(fn0);

		int f1 = open(fn1, O_RDONLY);
		if (f1 < 0) fileNotFound(fn1);

		do {
			lf0 = read(f0, buf0, bufsize);
			lf1 = read(f1, buf1, bufsize);

			if (lf0 != lf1)
				{ ret = false; break; }

			for (int i=0; i < lf0; i++)
				if (buf0[i] != buf1[i])
					{ ret = false; break; }

		} while (lf0>0);

		close(f0);
		close(f1);
		return ret;
	}


	/**
	 *
	 * @param fn0 filename of a file to compare
	 * @param fn1 filename of file to compare against
	 * @return string with differences
	 * 				<line>:
	 * 				<fn0 line>
	 * 				<fn1 line>
	 */
	static std::string cmptext(const char *fn0, const char *fn1) {
		char buf0[maxLinesize];
		char buf1[maxLinesize];
		std::string ret ="";
		int line = 0;

		FILE *sf0 = fopen(fn0, "r");
		if (!sf0) fileNotFound(fn0);

		FILE *sf1 = fopen(fn1, "r");
		if (!sf1) fileNotFound(fn0);

		char *lf0, *lf1;
		/* OLD implementation:
		do {
			lf0 = fgets(buf0, maxLinesize, sf0);
			lf1 = fgets(buf1, maxLinesize, sf1);

			//default false (if one is NULL is false)
			int equal=0;

			//General case (both NOT null)
			if (lf0 && lf1) equal = !strcmp(lf0, lf1);

			//both null (empty files are equal)
			if (!lf0 && !lf1) equal = 1;

			//if different
			if (!equal) {
				char head[10];
				sprintf(head, "%d:\n", line);
				ret += head;
				if (lf0 != NULL) ret += buf0;
				if (lf1 != NULL) ret += buf1;
			}

			++line;

		} while (lf0 || lf1);  //while one is not null
		*/

		for(;;) {
			lf0 = fgets(buf0, maxLinesize, sf0);
			lf1 = fgets(buf1, maxLinesize, sf1);

			//both NULL end (empty files are equal)
			if (!lf0 && !lf1) break;

			//default false (if one is null)
			int equal=0;

			//General case (both NOT null)
			if (lf0 && lf1) equal = !strcmp(lf0, lf1);

			//if different
			if (!equal) {
				char head[10];
				sprintf(head, "%d:\n", line);
				ret += head;
				if (lf0 != NULL) ret += buf0;
				if (lf1 != NULL) ret += buf1;
			}

			++line;
		}

		fclose(sf0);
		fclose(sf1);
		return ret;
	}


	/**
	 *
	 * @param dir    root dir to search
	 * @param regex  filename regex
	 * @return vector of pth that mathces regex form directory dir
	 */
	static std::vector<fs::path> search(const char *dir, const char *regex) {
		std::vector<fs::path> v;

		for(auto& p: fs::recursive_directory_iterator(dir)) {
			if (std::regex_match(p.path().filename().c_str(), std::regex(regex)))
				v.push_back(p.path());

		}
		return v;
	}
};


#endif //MOOSHAKTOOLS_FILE_H
