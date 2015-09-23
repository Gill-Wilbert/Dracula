// set.c - Used to manage a set of LocationIDs
// Adapted from week 8 lab, written by John Shepherd
// Adapted and expanded for FoD by Will Gilbert 22nd Sept 2015

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "set.h"
#include "Map.h"
	
typedef struct SetRep {
	int   nelems;
	LocationID elems[NUM_MAP_LOCATIONS];
} SetRep;

Set newLocSet();
void disposeSet(Set);
void insertInto(Set, LocationID);
void dropFrom(Set, LocationID);
int  isElem(Set, LocationID);
int  nElems(Set);
void showSet(Set);
LocationID *condensedSet(Set s);

// newSet()
// Creates set with all locations set to 0
Set newLocSet()
{
	Set new = malloc(sizeof(SetRep));
	assert(new != NULL);
	new->nelems = 0;
	int i;
	for(i = 0; i < NUM_MAP_LOCATIONS; i++) {
        new->elems[i] = 0;
    }
	return new;
}

// disposeSet(Set)
// - clean up memory associated with Set
void disposeSet(Set s)
{
	if (s == NULL) return;
	free(s);
}

// insertInto(Set,LocationID)
// set elems[LocationID] to 1
void insertInto(Set s, LocationID id)
{
	assert(s != NULL);
	if(s->elems[id] == 0) s->nelems++;
    s->elems[id] = 1;
}

// dropFrom(Set,LocationID)
// Revert elems[LocationID] to 0
void dropFrom(Set s, LocationID id)
{
	assert(s != NULL);
	if(s->elems[id] != 0) s->nelems--;
	s->elems[id] = 0;
}

// isElem(Set,LocationID)
// Check if location is in set
int isElem(Set s, LocationID id)
{
	assert(s != NULL);
	
	return s->elems[id];
}

// nElems(Set)
// - return # elements in Set
int  nElems(Set s)
{
	assert(s != NULL);
	return s->nelems;
}

// showSet(Set)
// - display Set (for debugging)
void showSet(Set s)
{
	if (s->nelems == 0)
		printf("Set is empty\n");
	else {
		printf("Set has %d elements:\n",s->nelems);
		int i;
		for(i = 0; i < NUM_MAP_LOCATIONS; i++) {
		    if(isElem(s,i)) {
		        printf("%d\n",i);
		    }
		}
	}
}

// condensedSet(Set)
// Condenses array of all possible locations down to array of only locations
// which are now in the set
LocationID *condensedSet(Set s)
{
    LocationID *condensed = malloc(sizeof(LocationID)*s->nelems);
    assert(condensed != NULL);
    int i, j;
    for(i = 0, j = 0; i < NUM_MAP_LOCATIONS; i++) {
        if(s->elems[i] == 1) {
            condensed[j] = i;
            j++;
        }
    }
    return condensed;
}
