

#include <fstream>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

/**
 * get dirs
 * @param count
 * @param argv
 * @return
 */
int main(int argc, char** argv) {
	//std::ofstream("sandbox/file1.txt");
	//fs::create_symlink("a", "sandbox/syma");
	for(auto& p: fs::recursive_directory_iterator(".."))
		std::cout << p.path() << '\n';
	std::cout << "ended\n";
}
