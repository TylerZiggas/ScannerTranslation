#pragma once
#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum tokenIDEnum { idTk, keywordTk, intTk, opTk, eofTk };

typedef struct token {
	tokenIDEnum tokenID;
	string tokenInstance;
	int lineNumber = 0;
} Token;

class ScannerLanguage {
	protected:
		map<string, string> allOperators = {
			{"=", "equalTk"}, {">", "greaterThanTk"}, {"<", "lessThanTk"}, {"==", "equalEqualTk"}, {":", "colonTk"}, {":=", "colonEqualTk"}, {"+", "plusTk"},
			{"-", "minusTk"}, {"*", "multiplyTk"}, {"/", "divideTk"}, {"%", "modulusTk"}, {".", "dotTk"}, {"(", "leftParenTk"}, {")", "rightParenTk"}, {",", "commaTk"}, 
			{"{", "leftCurlyTk"}, {"}", "rightCurlyTk"}, {";", "semiColonTk"}, {"[", "leftBracketTk"}, {"]", "rightBracketTk"}
		};

		map<string, string> allKeywords = {
			{"start", "startTk"}, {"stop", "stopTk"}, {"loop", "loopTk"}, {"while", "whileTk"}, {"for", "forTk"}, {"label", "labelTk"}, {"exit", "exitTk"}, {"listen", "listenTk"},
			{"talk", "talkTk"}, {"program", "programTk"}, {"if", "ifTk"}, {"then", "thenTk"}, {"assign", "assignTk"}, {"declare", "declareTk"}, {"jump", "jumpTk"}, {"else", "elseTk"}
		};

		const vector<string> tokenTypes = {
			"Identifier", "Keyword", "Integer", "Operator", "End Of File"
		};

		const vector<string> keywords = {
			"start", "stop", "loop", "while", "for", "label", "exit", "listen", "talk", "program", "if", "then", "assign", "declare", "jump", "else"
		};

		const vector<char> charOperators = {
			'=', '>', '<', ':', '+', '-', '*', '/', '%', '.', '(', ')', ',', '{', '}', ';', '[', ']'
		};

		const vector<string> stringOperators = {
			":=", "=="
		};

		const char COMMENT_DELIMITER = '&';

	public:
		void printToken(Token);
		int isCharOperator(char);
		int isStringOperator(string);
		int getOperator(Token&);
		int getKeyword(Token&);
};

#endif