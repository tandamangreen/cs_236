//
//  Datalog.hpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Datalog_hpp
#define Datalog_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Rule.h"
#include "Predicate.h"
#include "Param.h"

using namespace std;

class Datalog {
public:
    void getScheme(Predicate);
    void getFact(Predicate);
    void getRule(Rule);
    void getQuery(Predicate);
    void getCurrentDom(string);

    vector<Predicate> getDatalogFacts();
    vector<Predicate> getDatalogQueries();
    vector<Predicate> getDatalogSchemes();
    vector<Rule> getDatalogRules();

    void printScheme();
    void printFact();
    void printRule();
    void printQuery();
    void printDomain();

    void sortDomain();

    int schemeSize();
    int factSize();
    int querySize();
    int ruleSize();

    Predicate getCurrentScheme(int);
    Predicate getCurrentFact(int);
    Predicate getCurrentQuery(int);
    Rule getCurrentRule(int);

private:
    vector<Predicate> mySchemes;
    vector<Predicate> myFacts;
    vector<Predicate> myQueries;
    vector<Rule> myRules;
    vector<string> myDomain;
    bool stringMatch;

};

#endif /* Datalog_hpp */
