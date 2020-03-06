//
//  main.cpp
//  CS_236
//
//  Created by Tanner Green on 1/14/20.
//  Copyright © 2020 Tanner Green. All rights reserved.
//

#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
#include "Interpreter.h"


int main(int argc, const char* argv[]) {
    Scanner myScan(argv[1]);
    myScan.scan();
    Parser myParse;
    myParse.matchScan(myScan.passTokenVect());
    myParse.parse();
    Interpreter myInterpreter(myParse);
    myInterpreter.createRelations();
    myInterpreter.printRelations();
    return 0;
}
