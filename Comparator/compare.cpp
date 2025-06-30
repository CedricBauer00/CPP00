#include <iostream>
#include <fstream>

int main( int argc, char **argv ) {

	if (argc != 3) {
		std::cerr << "Invalid Number of Inputs (./comp 'file1 -> base file' 'file2 -> to compare')!" << std::endl;
		return -1;
	}
	std::ifstream file1(argv[1]);
	if (!file1) {
		std::cerr << "Base File invalid!" << std::endl;
		return -1;
	}
	std::ifstream file2(argv[2]);
	if (!file2) {
		std::cerr << "Compare File invalid!" << std::endl;
		return -1;
	}

	std::string line1, line2;
    int lineNumber = 1;
    bool differencesFound = false;

    std::cout << std::endl;

    while (true) {
        bool file1HasLine = static_cast<bool>(std::getline(file1, line1));
        bool file2HasLine = static_cast<bool>(std::getline(file2, line2));
        if (!file1HasLine && !file2HasLine) {
            break;
        }
        if (file1HasLine != file2HasLine || line1 != line2) {
            std::cout << "\033[38;5;196mDifference at line " << lineNumber << std::endl;
            std::cout << "File1: " << (file1HasLine ? line1 : "[EOF]") << std::endl;
            std::cout << "File2: " << (file2HasLine ? line2 : "[EOF]") << std::endl;
            std::cout << "\033[0m" << std::endl;
            differencesFound = true;
        }
        ++lineNumber;
    }

    if (!differencesFound) {
        std::cout << "\033[38;5;49mThe files are identical.\033[0m\n" << std::endl;
    }

	return 0;
}
