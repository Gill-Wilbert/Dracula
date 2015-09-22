// set.h ... interface for set of LocationIDs
// Written by Will Gilbert 22nd Sept 2015

#ifndef SET_H
#define SET_H
#include "Map.h"

typedef struct SetRep *Set;

// Function signatures

Set newLocSet();
void disposeSet(Set);
void insertInto(Set, LocationID);
void dropFrom(Set, LocationID);
int  isElem(Set, LocationID);
int  nElems(Set);
void showSet(Set);
LocationID *condensedSet(Set s);

#endif
