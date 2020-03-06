#ifndef Interpreter_h
#define Interpreter_h

#include <stdio.h>
#include <vector>
#include "Parser.h"
#include "Database.h"
using namespace std;

class Interpreter {
public:
  Interpreter(Parser);
  void print();
  void createRelations();
  void printRelations();

private:
  Datalog myDatalog;
  Relation myCurrentRelation;
  Database myDatabase;
  vector<Relation> myRelations;
  Predicate currentPred;
  Scheme currentScheme;

};

#endif
