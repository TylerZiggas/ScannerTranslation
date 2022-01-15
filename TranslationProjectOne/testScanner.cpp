#include "token.h"
#include "scanner.h"
#include "testScanner.h"

int testScanner(string fileName) {
	Scanner scanner;
	ifstream file(fileName.c_str());
	unsigned int currentLine = 1;  
	string input;
	Token token;  

	if (file.is_open()) {
		while (getline(file, input)) {

			while (scanner.scan(currentLine, input, token) == 0) {
				scanner.printToken(token);

			}
			currentLine++;
		}

	} else {
		cout << "SCANNER: File cannot be opened!" << endl;
		return EXIT_FAILURE;
	}

	if (file.eof()) {
		if (currentLine > 1) {
			currentLine--;
		}

		token.tokenID = eofTk;
		token.tokenInstance = "EOF";
		token.lineNumber = currentLine;
		scanner.printToken(token);
	}

	file.close();
	return EXIT_SUCCESS;
}
