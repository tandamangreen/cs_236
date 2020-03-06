#include "Relation.h"


//*********************************************************************************************
void Relation::add(string newName, Scheme newScheme) {
  name = newName;
  myScheme = newScheme;
  set<Tuple> myTuples;
}

//*********************************************************************************************
void Relation::print() {
  cout << "Relation Name: " << name << endl;
  for (int i = 0; i < myScheme.size(); i++) {
    cout << myScheme[i] << " ";
  }
  cout << endl;
  for (Tuple t : myTuples) {
    t.print();
  }
}
