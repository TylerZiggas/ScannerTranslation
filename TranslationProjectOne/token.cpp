#include "token.h"

void ScannerLanguage::printToken(Token token) {
	cout << "Line #" << token.lineNumber << ": " << tokenTypes[token.tokenID] << " | " << token.tokenInstance << endl;
}

int ScannerLanguage::isCharOperator(char currentCharOperator) {
	for (unsigned int i = 0; i < charOperators.size(); i++) {
		if (currentCharOperator == charOperators[i]) {
			return 1;
		}
	}

	return -1;
}

int ScannerLanguage::isStringOperator(string currentStringOperator) {
	for (unsigned int i = 0; i < stringOperators.size(); i++) {
		if (currentStringOperator.compare(stringOperators[i]) == 0) {
			return 1;
		}
	}

	return -1;
}

int ScannerLanguage::getOperator(Token& token) {
	for (unsigned int i = 0; i < charOperators.size(); i++) {
		string op(1, charOperators[i]);
		if (token.tokenInstance.compare(op) == 0) {
			token.tokenInstance = allOperators[token.tokenInstance];
			return i;
		}
	}

	for (unsigned int i = 0; i < stringOperators.size(); i++) {
		if (token.tokenInstance.compare(stringOperators[i]) == 0) {
			token.tokenInstance = allOperators[token.tokenInstance];
			return i;
		}
	}

	return -1;
}

int ScannerLanguage::getKeyword(Token& token) {
	for (unsigned int i = 0; i < keywords.size(); i++) {
		if (token.tokenInstance.compare(keywords[i]) == 0) {
			token.tokenInstance = allKeywords[token.tokenInstance];
			return i;
		}
	}

	return -1;
}