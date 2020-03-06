//
//  Datalog.cpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Datalog.h"

//*********************************************************************************************
void Datalog::getScheme(Predicate currentScheme) {
    mySchemes.push_back(currentScheme);
}

//*********************************************************************************************
void Datalog::getFact(Predicate currentFact) {
    myFacts.push_back(currentFact);
}

//*********************************************************************************************
void Datalog::getRule(Rule currentRule) {
    myRules.push_back(currentRule);
}

//*********************************************************************************************
void Datalog::getQuery(Predicate currentQuery) {
    myQueries.push_back(currentQuery);
}

//*********************************************************************************************
Predicate Datalog::getCurrentScheme(int index) {
    return mySchemes[index];
}

//*********************************************************************************************
Predicate Datalog::getCurrentFact(int index) {
    return myFacts[index];
}

//*********************************************************************************************
Predicate Datalog::getCurrentQuery(int index) {
    return myQueries[index];
}

//*********************************************************************************************
Rule Datalog::getCurrentRule(int index) {
    return myRules[index];
}

//*********************************************************************************************
void Datalog::getCurrentDom(string currentString) {
    for (uint i = 0; i < myDomain.size(); i++) {
        if (myDomain[i] != currentString) {
            stringMatch = false;
        }
        else {
            stringMatch = true;
            break;
        }
    }
    if (!stringMatch) {
        myDomain.push_back(currentString);
    }
}

//*********************************************************************************************
vector<Predicate> Datalog::getDatalogFacts() {
  return myFacts;
}
//*********************************************************************************************
vector<Predicate> Datalog::getDatalogQueries() {
  return myQueries;
}
//*********************************************************************************************
vector<Predicate> Datalog::getDatalogSchemes() {
  return mySchemes;
}
//*********************************************************************************************
vector<Rule> Datalog::getDatalogRules() {
  return myRules;
}

//*********************************************************************************************
int Datalog::schemeSize() {
  return mySchemes.size();
}

//*********************************************************************************************
int Datalog::factSize() {
  return myFacts.size();
}

//*********************************************************************************************
int Datalog::querySize() {
  return myQueries.size();
}

//*********************************************************************************************
int Datalog::ruleSize() {
  return myRules.size();
}

//*********************************************************************************************
void Datalog::printScheme() {
    //Checks and prints all schemes in the datalog objects rule vector
    cout << "Schemes(" << mySchemes.size() << "):" << endl;
    //Cycles through the scheme vector
    for (uint i = 0; i < mySchemes.size(); i++) {
        mySchemes[i].printScheme();
        cout << endl;
    }
}

//*********************************************************************************************
void Datalog::printFact() {
    //Checks and prints all schemes in the datalog objects rule vector
    cout << "Facts(" << myFacts.size() << "):" << endl;
    //Cycles through the scheme vector
    for (uint i = 0; i < myFacts.size(); i++) {
        myFacts[i].printFact();
    }
}

//*********************************************************************************************
void Datalog::printQuery() {
    //Checks and prints all schemes in the datalog objects rule vector
    cout << "Queries(" << myQueries.size() << "):" << endl;
    //Cycles through the scheme vector
    for (uint i = 0; i < myQueries.size(); i++) {
        myQueries[i].printQuery();
    }
}

//*********************************************************************************************
void Datalog::printRule() {
    //Checks and prints all schemes in the datalog objects rule vector
    cout << "Rules(" << myRules.size() << "):" << endl;
    //Cycles through the scheme vector
    for (uint i = 0; i < myRules.size(); i++) {
        myRules[i].printRule();
    }
}

//*********************************************************************************************
void Datalog::printDomain() {
    sortDomain();
    cout << "Domain(" << myDomain.size() << "):" << endl;
    for (uint i = 0; i < myDomain.size(); i++) {
        cout << "  " << myDomain[i] << endl;
    }
}

//*********************************************************************************************
void Datalog::sortDomain() {
    sort(myDomain.begin(), myDomain.end());
}
