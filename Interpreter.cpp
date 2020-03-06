#include "Interpreter.h"


//*********************************************************************************************
Interpreter::Interpreter(Parser myParse) {
  myDatalog = myParse.getDatalog();
  myDatalog.getDatalogFacts();
  myDatalog.getDatalogQueries();
  myDatalog.getDatalogSchemes();
  //myDatalog.getDatalogRules();
}

//*********************************************************************************************
void Interpreter::print() {
  myDatalog.printScheme();
  myDatalog.printFact();
  myDatalog.printRule();
  myDatalog.printQuery();
}

//*********************************************************************************************
void Interpreter::createRelations() {
  for (int i = 0; i < myDatalog.schemeSize(); i++) {
    currentPred = myDatalog.getCurrentScheme(i);
    myDatabase.addRelation(currentPred.getName(), currentPred.getParams());
  }
}

//*********************************************************************************************
void Interpreter::printRelations() {
  for (int i = 0; i < myDatabase.relationSize(); i++) {
    myDatabase.printRelation(i);
  }
}
