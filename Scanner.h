//
//  Scanner.hpp
//  CS_236
//
//  Created by Tanner Green on 1/18/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Scanner_h
#define Scanner_h

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Token.h"
using namespace std;


class Scanner {
public:
    Scanner(string fileName);

    void scan();
    void scanComment();
    void scanID();
    void scanString();
    void scanChar();
    void scanUndefined();
    void printScan();
    void printTokenCount(int tokenCount);
    void pushToken(tokenType, string, int);
    vector<Token> passTokenVect();
    int passTokenCount();

private:
    string fileName;
    ifstream file;
    int lineNum = 1;
    vector<Token> myTokens;
    char currentChar;
    tokenType myTokenType;
    int tokenCount = 0;
};

#endif /* Scanner_hpp */
