#pragma once
#ifndef SCANNER_H
#define SCANNER_H
#include <iostream> 
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include "token.h"
using namespace std;

class Scanner: public ScannerLanguage {
	protected:
		unsigned int currentPointerPlacement = 0;
		bool isCommenting = false;
		bool commentRecentChange = false;
		int commentCounter = 0;
		string lastCommentPosition = "";

		const enum {
			ERROR_UNK = -4, // TODO: -3 and -2 visual studio doesnt like give vector out of bounds??
			ERROR_COM = -3,
			ERROR_INT = -2,
			ERROR_ID = -1,
			STATE_0 = 0,
			STATE_1 = 1,
			STATE_2 = 2,
			STATE_3 = 3,
			FINAL_STATE = 1000,
			FINAL_ID = 1001,
			FINAL_INT = 1003,
			FINAL_OP = 1004,
			FINAL_EOF = 1005
		};

		const int FSA_TABLE[4][8] = {
			{ ERROR_ID, STATE_2, STATE_2, STATE_3, STATE_1, STATE_0, FINAL_EOF, ERROR_UNK },
			{ FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, FINAL_OP, ERROR_UNK },
			{ STATE_2, STATE_2, FINAL_ID, STATE_2, FINAL_ID, FINAL_ID, FINAL_ID, ERROR_UNK },
			{ ERROR_INT, ERROR_INT, ERROR_INT, STATE_3, FINAL_INT, FINAL_INT, FINAL_INT, ERROR_UNK },
		};

		const char SCANNER_DELIMITER = ' ';


	public:
		int scan(int, string&, Token&);
		char checkComment(int, char, char);
		int getCategory(char);
		void getError(int, int, char);
};
#endif





/* FSA TABLE
--------------------------------------------------------------------------------------------------------------
| uppercase |lowercase  | $         | digit     | operator  | whitespace| EOF       | other     | &          |
--------------------------------------------------------------------------------------------------------------
| ERROR_ID  | STATE_2   | STATE_2   | STATE_3   | STATE_1   | STATE_0   | STATE_EOF | ERROR_UNK |  STATE_4   | s0 (initial)
--------------------------------------------------------------------------------------------------------------
| STATE_OP  | STATE_OP  | STATE_OP  | STATE_OP  | STATE_OP  | STATE_OP  | STATE_OP  | ERROR_UNK |  STATE_OP  | s1 (operator)
--------------------------------------------------------------------------------------------------------------
| STATE_2   | STATE_2   | STATE_ID  | STATE_2   | STATE_ID  | STATE_ID  | STATE_ID  | ERROR_UNK |  STATE_ID  | s2 (identifier)
--------------------------------------------------------------------------------------------------------------
| ERROR_INT | ERROR_INT | ERROR_INT | STATE_3   | STATE_INT | STATE_INT | STATE_INT | ERROR_UNK |  STATE_INT | s3 (integer)
--------------------------------------------------------------------------------------------------------------
| ERROR_UNK | ERROR_UNK | ERROR_UNK | ERROR_UNK | ERROR_UNK | ERROR_UNK | ERROR_UNK | ERROR_UNK |  FINAL_COM | s4 (comment)
--------------------------------------------------------------------------------------------------------------
*/