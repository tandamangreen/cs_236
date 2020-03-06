#ifndef Database_h
#define Database_h

#include <stdio.h>
#include <vector>
#include "Predicate.h"
#include "Relation.h"
#include "Scheme.h"
using namespace std;

class Database {
public:
  void addRelation(string, vector<Param>);

  int relationSize();
  void printRelation(int);

private:
  Scheme currentScheme;
  vector<Relation> myRelations;
  Relation currentRelation;
};

#endif
