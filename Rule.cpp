//
//  Rule.cpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Rule.h"

//*********************************************************************************************
void Rule::getHeadPredicate(Predicate currentPred) {
    headPredicate = currentPred;
}

//*********************************************************************************************
void Rule::getBodyPred(Predicate currentPred) {
    myPredList.push_back(currentPred);
}

//*********************************************************************************************
void Rule::printRule() {
    cout << "  ";
    headPredicate.printRule();
    cout << " :- ";
    for (uint i = 0; i < myPredList.size(); i++) {
        if (i == 0) {
            myPredList[i].printRule();
        }
        else {
            cout << ",";
            myPredList[i].printRule();
        }
    }
    cout << "." << endl;
}

