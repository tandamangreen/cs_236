//
//  Param.hpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#ifndef Param_hpp
#define Param_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Param {
public:
    void addParam(string);
    void addParamExp(string);
    void convert();

    string print();

private:
    string paramString;
    string paramExp;

};
#endif /* Param_hpp */
