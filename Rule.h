//
//  Rule.hpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <stdio.h>
#include <vector>
#include "Predicate.h"
using namespace std;

class Rule {
public:
    void getHeadPredicate(Predicate);
    void getBodyPred(Predicate);
    
    void printRule();
    
private:
    vector<Predicate> myPredList;
    Predicate headPredicate;
    int predCount;
    
};
#endif /* Rule_hpp */
