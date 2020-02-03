//
//  Param.cpp
//  cs_236_lab1
//
//  Created by Tanner Green on 1/28/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Param.h"
using namespace std;

//*********************************************************************************************
void Param::addParam(string currentParam) {
    paramString = currentParam;
}

//*********************************************************************************************
void Param::addParamExp(string currentParam) {
    paramExp = paramExp + currentParam;
}

//*********************************************************************************************
void Param::convert() {
    paramString = paramExp;
}

//*********************************************************************************************
string Param::print() {
    return paramString;
}
