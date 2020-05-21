

#include <iostream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

/**
 * get dirs
 * @param count
 * @param argv
 * @return
 */
int main(int argc, char** argv) {
std::vector<fs::path> v;

	for (const auto& p: fs::recursive_directory_iterator(".."))
		if (std::regex_match(p.path().filename().c_str(), std::regex( "(.*)(.txt)"))) {
			v.push_back(p.path());
	}

	for (const auto& p : v)
		std::cout << p << '\n';

	std::cout << "ended\n";
}
