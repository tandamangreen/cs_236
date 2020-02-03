//
//  Parser.cpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/26/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Parser.h"

//*********************************************************************************************
Parser::Parser() {
    currentRule = Rule();
    currentPred = Predicate();
    currentParam = Param();
    myDataLog = Datalog();
}

//*********************************************************************************************
//This function takes in the vector of tokens from the scan object in main and copies it to the vector of tokens in the Parser object
void Parser::matchScan(vector<Token> scanToken) {
    myTokens = scanToken;
    currentTokenType = myTokens[tokenCount].getTokenType();
}

//*********************************************************************************************
//Searches through the vector of tokens to parse
void Parser::parse() {
    try {
        datalogProgram();
    }
    //Takes in the bad token and catches it right here
    catch (tokenType badToken) {
        cout << "Failure!" << endl;
        cout << "  " << '(' << myTokens[tokenCount].tokenToString(badToken) << ",\"";
        cout << myTokens[tokenCount].getTokenVal() << "\"," << myTokens[tokenCount].getLineNum() << ")" << endl;
    }
}

//*********************************************************************************************
//Searches through all types of data and sorts them out
void Parser::datalogProgram() {
    if (currentTokenType == SCHEMES) {
        match(SCHEMES);
        match(COLON);
        scheme();
        schemeList();
        match(FACTS);
        match(COLON);
        factList();
        match(RULES);
        match(COLON);
        ruleList();
        match(QUERIES);
        match(COLON);
        query();
        queryList();
        match(EOFILE);
        myDataLog.printScheme();
        myDataLog.printFact();
        myDataLog.printRule();
        myDataLog.printQuery();
        myDataLog.printDomain();
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
//Searches through all the scheme lists until nothing is left
void Parser::schemeList() {
    if (currentTokenType == ID) {
        scheme();
        schemeList();
    }
}

//*********************************************************************************************
//Searches through fact lists until nothing is left
void Parser::factList() {
    if (currentTokenType == ID) {
        fact();
        factList();
    }
}

//*********************************************************************************************
//Searches through rule lists until nothing is left
void Parser::ruleList() {
    if (currentTokenType == ID) {
        rule();
        ruleList();
    }
}

//*********************************************************************************************
//Searches through query lists until nothing is left
void Parser::queryList() {
    if (currentTokenType == ID) {
        query();
        queryList();
    }
}

//*********************************************************************************************
//Finds each individual scheme and appends all IDs to it if needed
void Parser::scheme() {
    if (currentTokenType == ID) {
        currentPred = Predicate();
        //Adds the ID to predicate
        addPredicate();
        match(ID);
        //Adds the left Paren to predicate
        addPredicate();
        match(LEFT_PAREN);
        //Adds the ID to predicate param vector
        addParam();
        currentPred.addParam(currentParam);
        match(ID);
        //Goes through list of IDs inside predicate params until done
        idList();
        //Checks for right parenthesis to complete scheme
        match(RIGHT_PAREN);
        //Adds the current predicate to the scheme vector and resets the current predicate
        myDataLog.getScheme(currentPred);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
//Searches through each individual fact and appends all parameters to it if needed
void Parser::fact() {
    if (currentTokenType == ID) {
        currentPred = Predicate();
        //Adds the ID to the current predicate
        addPredicate();
        match(ID);
        //Adds the left paren to the current predicate
        addPredicate();
        match(LEFT_PAREN);
        //Adds the string to the params vector in current predicate
        addParam();
        currentPred.addParam(currentParam);
        myDataLog.getCurrentDom(myTokens[tokenCount].getTokenVal());
        match(STRING);
        stringList();
        match(RIGHT_PAREN);
        match(PERIOD);
        myDataLog.getFact(currentPred);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
//Searches through all the rules
void Parser::rule() {
    if (currentTokenType == ID) {
        currentRule = Rule();
        currentPred = Predicate();
        currentParam = Param();
        headPredicate();
        match(COLON_DASH);
        currentPred = Predicate();
        currentParam = Param();
        predicate();
        predicateList();
        match(PERIOD);
        myDataLog.getRule(currentRule);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::query() {
    if (currentTokenType == ID) {
        currentPred = Predicate();
        currentParam = Param();
        predicate();
        match(Q_MARK);
        myDataLog.getQuery(currentPred);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::headPredicate() {
    if (currentTokenType == ID) {
        addPredicate();
        match(ID);
        addPredicate();
        match(LEFT_PAREN);
        addParam();
        currentPred.addParam(currentParam);
        match(ID);
        idList();
        match(RIGHT_PAREN);
        currentRule.getHeadPredicate(currentPred);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::predicate() {
    if (currentTokenType == ID) {
        //Adds the ID to the current predicate
        currentParam = Param();
        addPredicate();
        match(ID);
        //Adds the left paren to the current predicate
        addPredicate();
        match(LEFT_PAREN);
        currentParam = Param();
        parameter();
        currentPred.addParam(currentParam);
        parameterList();
        match(RIGHT_PAREN);
        currentRule.getBodyPred(currentPred);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::predicateList() {
    if (currentTokenType == COMMA) {
        match(COMMA);
        currentPred = Predicate();
        currentParam = Param();
        predicate();
        predicateList();
    }
}

//*********************************************************************************************
void Parser::parameterList() {
    if (currentTokenType == COMMA) {
        match(COMMA);
        currentParam = Param();
        parameter();
        currentPred.addParam(currentParam);
        parameterList();
    }
}

//*********************************************************************************************
void Parser::stringList() {
    if (currentTokenType == COMMA) {
        match(COMMA);
        //Adds the next parameter to param vector until finished
        addParam();
        currentPred.addParam(currentParam);
        myDataLog.getCurrentDom(myTokens[tokenCount].getTokenVal());
        match(STRING);
        stringList();
    }
}

//*********************************************************************************************
void Parser::idList() {
    if (currentTokenType == COMMA) {
        match(COMMA);
        //Adds the next ID to predicate param vector until finished
        addParam();
        currentPred.addParam(currentParam);
        match(ID);
        idList();
    }
}

//*********************************************************************************************
void Parser::parameter() {
    if (currentTokenType == STRING) {
        if (exp) {
            addParamExp();
        }
        else {
            addParam();
        }
        match(STRING);
    }
    else if (currentTokenType == ID) {
        if (exp) {
            addParamExp();
        }
        else {
            addParam();
        }
        match(ID);
    }
    else if (currentTokenType == LEFT_PAREN) {
        expression();
        currentParam.convert();
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::expression() {
    if (currentTokenType == LEFT_PAREN) {
        exp = true;
        addParamExp();
        match(LEFT_PAREN);
        parameter();
        addParamExp();
        op();
        parameter();
        addParamExp();
        match(RIGHT_PAREN);
        exp = false;
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::op() {
    if (currentTokenType == ADD) {
        match(ADD);
    }
    else if (currentTokenType == MULTIPLY) {
        match(MULTIPLY);
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::match(tokenType desiredType) {
    if (currentTokenType == desiredType) {
        currentTokenType = getToken();
    }
    else {
        error(currentTokenType);
    }
}

//*********************************************************************************************
void Parser::error(tokenType badToken) {
    throw badToken;
}

//*********************************************************************************************
tokenType Parser::getToken() {
    tokenCount++;
    return myTokens[tokenCount].getTokenType();
}

//*********************************************************************************************
void Parser::addPredicate() {
    currentPred.setName(myTokens[tokenCount].getTokenVal());
}

//*********************************************************************************************

void Parser::addParam() {
    currentParam.addParam(myTokens[tokenCount].getTokenVal());
}

//*********************************************************************************************
void Parser::addParamExp() {
    currentParam.addParamExp(myTokens[tokenCount].getTokenVal());
}
