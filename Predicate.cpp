//
//  Predicate.cpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Predicate.h"

//*********************************************************************************************
void Predicate::setName(string currentTokenVal) {
    predName = predName + currentTokenVal;
}

//*********************************************************************************************
void Predicate::printScheme() {
    cout << "  " << predName;
    for (uint i = 0; i < myParams.size(); i++) {
        if (i == 0) {
            cout << myParams[i].print();
        }
        else {
            cout << "," << myParams[i].print();
        }
    }
    cout << ")";
}

//*********************************************************************************************
void Predicate::printFact() {
    cout << "  " << predName;
    for (uint i = 0; i < myParams.size(); i++) {
        if (i == 0) {
            cout << myParams[i].print();
        }
        else {
            cout << "," << myParams[i].print();
        }
    }
    cout << ")." << endl;
}

//*********************************************************************************************
void Predicate::printRule() {
    cout << predName;
    for (uint i = 0; i < myParams.size(); i++) {
        if (i == 0) {
            cout << myParams[i].print();
        }
        else {
            cout << "," << myParams[i].print();
        }
    }
    cout << ")";
}

//*********************************************************************************************
void Predicate::printQuery() {
    cout << "  " << predName;
    for (uint i = 0; i < myParams.size(); i++) {
        if (i == 0) {
            cout << myParams[i].print();
        }
        else {
            cout << "," << myParams[i].print();
        }
    }
    cout << ")?" << endl;
}

//*********************************************************************************************
void Predicate::addParam(Param myParam) {
    myParams.push_back(myParam);
}
