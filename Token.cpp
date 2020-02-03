//
//  Token.cpp
//  CS_236
//
//  Created by Tanner Green on 1/18/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Token.h"

Token::Token(tokenType token, string tokenVal, int lineNum) {
    this->token = token;
    this->tokenVal = tokenVal;
    this->lineNum = lineNum;
}

string Token::tokenToString(tokenType val) {
    switch (val) {
        case COMMA: return "COMMA";
            break;
        case PERIOD: return "PERIOD";
            break;
        case Q_MARK: return "Q_MARK";
            break;
        case LEFT_PAREN: return "LEFT_PAREN";
            break;
        case RIGHT_PAREN: return "RIGHT_PAREN";
            break;
        case COLON: return "COLON";
            break;
        case COLON_DASH: return "COLON_DASH";
            break;
        case MULTIPLY: return "MULTIPLY";
            break;
        case ADD: return "ADD";
            break;
        case SCHEMES: return "SCHEMES";
            break;
        case FACTS: return "FACTS";
            break;
        case RULES: return "RULES";
            break;
        case QUERIES: return "QUERIES";
            break;
        case ID: return "ID";
            break;
        case STRING: return "STRING";
            break;
        case COMMENT: return "COMMENT";
            break;
        case UNDEFINED: return "UNDEFINED";
            break;
        case EOFILE: return "EOF";
            break;
        default:
            cout << "Error\n\r";
            return "Error";
            break;
    }
}

string Token::getTokenVal() {
    return tokenVal;
}

void Token::printTokens() {
    cout << '(' << tokenToString(token) << ",\"" << tokenVal << "\"," << lineNum << ")" << endl;
}

tokenType Token::getTokenType() {
    return token;
}

int Token::getLineNum() {
    return lineNum;
}

