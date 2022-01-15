#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>        
#include <fstream>    
#include "testScanner.h"
using namespace std;

int main(int argc, char* argv[]) {
	string fileName;
	string outputFileName;
	string userInput;

	switch (argc) {
		case 1: {
			ofstream temp_file;
			fileName = "input.fs";
			temp_file.open(fileName.c_str());

			cout << "SCANNER: Please input tokens and enter an empty line when you are finished." << endl;

			do {
				getline(cin, userInput);

				temp_file << userInput << endl;
			} while (!userInput.empty());

			cout << "SCANNER: Done reading from keyboard..." << endl << endl;
			temp_file.close();
			outputFileName = "output";
			break;
		}

		case 2: {
			cout << "SCANNER: Reading from file." << endl << endl;

			fileName = argv[1];
			size_t fileType = fileName.find(".");

			if (fileType == string::npos) {
				outputFileName = fileName;
				fileName.append(".fs");

			} else {
				outputFileName = fileName.substr(0, fileType);

			}
			break;
		}

		default: {
			cout << "SCANNER ERROR: Too many arguments received!" << endl;
			cout << "Use by: " << argv[0] << " [file]" << endl;
			cout << "With [file] is an optional parameter." << endl;
			return EXIT_FAILURE;

		}
	}

	testScanner(fileName);
	return 0;
}