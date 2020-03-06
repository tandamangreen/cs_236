#ifndef Relation_h
#define Relation_h

#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include "Scheme.h"
#include "Tuple.h"
using namespace std;

class Relation {
public:
  void add(string, Scheme);
  void print();

private:
  string name;
  Scheme myScheme;
  set<Tuple> myTuples;
};

#endif
