//
//  Scanner.cpp
//  CS_236
//
//  Created by Tanner Green on 1/18/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Scanner.h"
using namespace std;


//*************************************************************************************************
//Constructor
Scanner::Scanner(string fileName) {
    this->fileName = fileName;
    ifstream file;
    vector<Token> myTokens;
}


//*************************************************************************************************
//Scans file entirely
void Scanner::scan() {
    file.open(fileName);
    if (file.is_open()) {
        //Enters loop to check the whole file
        while (!file.eof()) {
            //Gets the current char and evaluates it
            file.get(currentChar);
            //EOF
            if (file.eof()) {
                break;
            }
            //Token will most likely be a comment
            else if (currentChar == '#') {
                scanComment();
            }
            //Token will most likely be a string
            else if (currentChar == '\'') {
                scanString();
            }
            //Token will most likely be an ID
            else if (isalpha(currentChar)) {
                scanID();
            }
            //Token is a space, tab, newline, etc...
            else if (isspace(currentChar)) {
                //Newline is accounted for while not inside a token
                if (currentChar == '\n') {
                    lineNum++;
                }
            }
            //Token will most likely be an ID
            else {
                switch(currentChar) {
                    //Token types are set here for each case
                    case ',':
                        myTokenType = COMMA;
                        scanChar();
                        break;
                    case '.':
                        myTokenType = PERIOD;
                        scanChar();
                        break;
                    case '?':
                        myTokenType = Q_MARK;
                        scanChar();
                        break;
                    case '(':
                        myTokenType = LEFT_PAREN;
                        scanChar();
                        break;
                    case ')':
                        myTokenType = RIGHT_PAREN;
                        scanChar();
                        break;
                    case ':':
                        myTokenType = COLON;
                        scanChar();
                        break;
                    case '*':
                        myTokenType = MULTIPLY;
                        scanChar();
                        break;
                    case '+':
                        myTokenType = ADD;
                        scanChar();
                        break;
                    default:
                        //Nothing else has been recognized, must be an undefined token
                        scanUndefined();
                        break;
                }
            }
        }
        //Token type set to EOF
        myTokenType = EOFILE;
        //Initializes a Token object with type, token value and line number where the token started
        Token currentToken(myTokenType, "", lineNum);
        //Pushes the current token to a vector of token objects
        myTokens.push_back(currentToken);
        tokenCount++;
        file.close();
    }
    else {
        cout << "File not found\n\r";
    }
}


//*************************************************************************************************
//Scans char IDs
void Scanner:: scanChar() {
    //Initialized string for token value
    string tokenString;
    //Checks for a colon dash ID
    if (currentChar == ':' && file.peek() == '-') {
        myTokenType = COLON_DASH;
        tokenString = currentChar;
        file.get(currentChar);
    }
    //Adds char ID to token value
    tokenString = tokenString + currentChar;
    //Initializes a Token object with type, token value and line number where the token started
    Token currentToken(myTokenType, tokenString, lineNum);
    //Pushes the current token to a vector of token objects
    myTokens.push_back(currentToken);
    tokenCount++;
}


//*************************************************************************************************
//Scans Comments
void Scanner::scanComment() {
    //Token type is set to comment
    myTokenType = COMMENT;
    //Initialized string for token value
    string tokenString;
    //Keeps track of where comment started with respect to line number
    //int currentLineNum = lineNum;
    //Adds the # symbol at the beginning
    tokenString = tokenString + currentChar;
    //Checks to see if it is a block comment
    if (file.peek() == '|') {
        //Adds | to comment and moves onto while loop
        file.get(currentChar);
        tokenString = tokenString + currentChar;
        //Checks for all cases to end block comment
        while (1) {
            file.get(currentChar);
            //Checks to see if |# is found to end block comment
            if (currentChar == '|' && file.peek() == '#') {
                tokenString = tokenString + currentChar;
                file.get(currentChar);
                tokenString = tokenString + currentChar;
                break;
            }
            //Accounts for line number
            else if (currentChar == '\n') {
                lineNum++;
            }
            //EOF
            else if (file.eof()) {
                myTokenType = UNDEFINED;
                break;
            }
            //Adds to comment
            tokenString = tokenString + currentChar;
        }
        //Initializes a Token object with type, token value and line number where the token started
        //Token currentToken(myTokenType, tokenString, currentLineNum);
        //Pushes the current token to a vector of token objects
        //myTokens.push_back(currentToken);
        //tokenCount++;
    }
    //Regular line comment
    else {
        //Checks for a newline
        while (currentChar != '\n') {
            file.get(currentChar);
            //Accounts for line number
            if (currentChar == '\n') {
                lineNum++;
            }
            //EOF
            else if (file.eof()) {
                break;
            }
            //Adds to comment
            else {
                tokenString = tokenString + currentChar;
            }
        }
        //Initializes a Token object with type, token value and line number where the token started
        //Token currentToken(myTokenType, tokenString, currentLineNum);
        //Pushes the current token to a vector of token objects
        //myTokens.push_back(currentToken);
        //tokenCount++;
    }
}


//*************************************************************************************************
//Scans IDs
void Scanner::scanID() {
    //Token type is set to ID
    myTokenType = ID;
    //Initialized string for token value
    string tokenString;
    //Keeps track of where ID started with respect to line number
    int currentLineNum = lineNum;
    //Adds ID to token val
    tokenString = tokenString + currentChar;
    //Checks for ID of 1 char
    if (!isalpha(file.peek()) && !isdigit(file.peek())) {
    }
    else {
        //While loop stops at any value not a letter or digit
        while (isalpha(currentChar) || isdigit(currentChar)) {
            file.get(currentChar);
            //Skips all whitespace
            if (isspace(currentChar)) {
                //Loops through consecutive whitespace
                while (isspace(currentChar)) {
                    //Accounts for line number
                    if (currentChar == '\n') {
                        lineNum++;
                    }
                    file.get(currentChar);
                    //If another letter/digit appears after space, token type is undefined
                    if (isalpha(currentChar) || isdigit(currentChar)) {
                        myTokenType = UNDEFINED;
                        break;
                    }
                }
            }
            //Adds to token value and checks for keywords
            else {
                tokenString = tokenString + currentChar;
                //These statements check for properly written keywords
                if ((tokenString == "Schemes") && !(isdigit(file.peek()) || isalpha(file.peek()))) {
                    myTokenType = SCHEMES;
                    break;
                }
                else if ((tokenString == "Queries") && !(isdigit(file.peek()) || isalpha(file.peek()))) {
                    myTokenType = QUERIES;
                    break;
                }
                else if (((tokenString == "Facts") && !(isdigit(file.peek()) || isalpha(file.peek())))) {
                    myTokenType = FACTS;
                    break;
                }
                else if ((tokenString == "Rules") && !(isdigit(file.peek()) || isalpha(file.peek()))) {
                    myTokenType = RULES;
                    break;
                }
                //If true, ID token has been evaluated correctly
                else if (!isalpha(file.peek()) && !isdigit(file.peek())) {
                    break;
                }
                //EOF
                else if (file.eof()) {
                    myTokenType = UNDEFINED;
                    break;
                }
            }
            
        }
    }
    //Initializes a Token object with type, token value and line number where the token started
    Token currentToken(myTokenType, tokenString, currentLineNum);
    //Pushes the current token to a vector of token objects
    myTokens.push_back(currentToken);
    tokenCount++;
}


//*************************************************************************************************
//Scans Strings
void Scanner::scanString() {
    //Token type is set to string
    myTokenType = STRING;
    //Initialized string for token value
    string tokenString = "";
    //Keeps track of the line number where the string started
    int currentLineNum = lineNum;
    //Adds first qoute to string and gets next char
    tokenString = tokenString + currentChar;
    //While loop looking for the end of the string
    while (1) {
        file.get(currentChar);
        //Checks for pairs of consecutive strings
        if (currentChar == '\'' && file.peek() == '\'') {
            //Will check for infinite amount of quote pairs in a row
            while (currentChar == '\'' && file.peek() == '\'') {
                tokenString = tokenString + currentChar;
                file.get(currentChar);
                tokenString = tokenString + currentChar;
                file.get(currentChar);
            }
        }
        //Checks for end of file and sets token to undefined because string was supposed to end
        if (file.eof()) {
            myTokenType = UNDEFINED;
            break;
        }
        //Last check to see if the string has an ending quote and will break here if so
        else if (currentChar == '\'') {
            tokenString = tokenString + currentChar;
            break;
        }
        //Checks for a newline and puts it into the string
        else if (currentChar == '\n') {
            lineNum++;
        }
        //Adds current token to string
        tokenString = tokenString + currentChar;
    }
    //Initializes a Token object with type, token value and line number where the token started
    Token currentToken(myTokenType, tokenString, currentLineNum);
    //Pushes the current token to a vector of token objects
    myTokens.push_back(currentToken);
    tokenCount++;
}


//*************************************************************************************************
//Scans Undefined tokens
void Scanner::scanUndefined() {
    //Token type is set to undefined
    myTokenType = UNDEFINED;
    //Initialized string for token value
    string tokenString;
    //Undefined token is added to token value
    tokenString = tokenString + currentChar;
    //Initializes a Token object with type, token value and line number where the token started
    Token currentToken(myTokenType, tokenString, lineNum);
    //Pushes the current token to a vector of token objects
    myTokens.push_back(currentToken);
    tokenCount++;
}


//*************************************************************************************************
//Prints out all of the tokens, their values and their line numbers
void Scanner::printScan() {
    for (uint i = 0; i < myTokens.size(); i++) {
        myTokens[i].printTokens();
    }
    printTokenCount(tokenCount);
}


//*************************************************************************************************
//Prints out token count
void Scanner::printTokenCount(int tokenCount) {
    cout << "Total Tokens = " << tokenCount << endl;
}

//*************************************************************************************************
//Prints out token count
vector<Token> Scanner::passTokenVect() {
    return myTokens;
}

//*************************************************************************************************
//Prints out token count
int Scanner::passTokenCount() {
    return tokenCount;
}
