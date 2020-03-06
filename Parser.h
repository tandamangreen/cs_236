//
//  Parser.hpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/26/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "Scanner.h"
#include "Rule.h"
#include "Predicate.h"
#include "Param.h"
#include "Datalog.h"
#include <stdio.h>

class Parser {
public:
    Parser();
    void datalogProgram();
    void parse();
    void matchScan(vector<Token>);
    void printParse();

    void schemeList();
    void factList();
    void ruleList();
    void queryList();

    void scheme();
    void fact();
    void rule();
    void query();

    void headPredicate();
    void predicate();

    void predicateList();
    void parameterList();
    void stringList();
    void idList();

    void parameter();
    void expression();
    void op();

    void match(tokenType);
    void error(tokenType);

    tokenType getToken();
    void addParam();
    void addParamExp();
    void addPredicate();

    Datalog getDatalog();

private:
    tokenType currentTokenType;
    int tokenCount = 0;
    vector<Token> myTokens;
    Rule currentRule;
    Predicate currentPred;
    Param currentParam;
    Datalog myDataLog;
    bool exp = false;

};

#endif /* Parser_hpp */
