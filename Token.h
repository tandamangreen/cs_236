//
//  Token.hpp
//  CS_236
//
//  Created by Tanner Green on 1/18/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

enum tokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EOFILE
};

class Token {
public:
    Token(tokenType token, string tokenVal, int lineNum);
    string tokenToString(tokenType val);
    void printTokens();
    tokenType getTokenType();
    string getTokenVal();
    int getLineNum();
    
private:
    tokenType token;
    string tokenVal;
    int lineNum;
};

#endif /* Token_hpp */
