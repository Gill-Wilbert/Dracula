// set.h ... interface for set of LocationIDs
// Written by Will Gilbert 22nd Sept 2015

#ifndef SET_H
#define SET_H

typedef struct SetRep *Set;

// Function signatures

Set newSet();
void disposeSet(Set);
void insertInto(Set, LocationID);
void dropFrom(Set, LocationID);
int  isElem(Set, LocationID);
int  nElems(Set);
void showSet(Set);

#endif
