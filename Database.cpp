#include "Database.h"


//*********************************************************************************************
void Database::addRelation(string name, vector<Param> schemeParams) {
  for (int i = 0; i < schemeParams.size(); i++) {
    currentScheme.push_back(schemeParams[i]);
  }
  currentRelation.add(name, currentScheme);
  myRelations.push_back(currentRelation);
}

//*********************************************************************************************
int Database::relationSize() {
  return myRelations.size();
}

//*********************************************************************************************
void Database::printRelation(int index) {
  myRelations[index].print();
}
