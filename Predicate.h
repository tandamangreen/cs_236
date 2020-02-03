//
//  Predicate.hpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Predicate_hpp
#define Predicate_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "Param.h"
#include "Token.h"
using namespace std;

class Predicate {
public:
    string getName();
    void setName(string);
    void addParam(Param);
    
    void printScheme();
    void printFact();
    void printQuery();
    void printRule();
    
private:
    vector<Param> myParams;
    int paramCount;
    string predName;
};

#endif /* Predicate_hpp */
