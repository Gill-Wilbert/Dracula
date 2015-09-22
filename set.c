// set.c - Used to manage a set of LocationIDs
// Written by Will Gilbert 22nd Sept 2015

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "set.h"
	
typedef struct SetRep {
	int   nelems;
	LocationID elems[NUM_MAP_LOCATIONS];
} SetRep;

// Function signatures

Set newSet();
void disposeSet(Set);
void insertInto(Set, LocationID);
void dropFrom(Set, LocationID);
int  isElem(Set, LocationID);
int  nElems(Set);
void showSet(Set);

// newSet()
// Creates set with all locations set to 0
Set newSet()
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
	free(s)
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
		        printf("%d\n",s->elems[i]);
		    }
		}
	}
}

// Helper functions
/*
static Link newNode(char *str)
{
	Link new = malloc(sizeof(Node));
	assert(new != NULL);
	new->val = strdup(str);
	new->next = NULL;
	return new;
}

static void disposeNode(Link curr)
{
	assert(curr != NULL);
	free(curr->val);
	free(curr);
}

// findNode(L,Str)
// - finds where Str could be added into L
// - if already in L, curr->val == Str
// - if not already in L, curr and prev indicate where to insert
// - return value indicates whether Str found or not
static int findNode(Link list, char *str, Link *cur, Link *pre)
{
	Link curr = list, prev = NULL;
	while (curr != NULL && strLT(curr->val,str)) {
		prev = curr;
		curr = curr->next;
	}
	*cur = curr; *pre = prev;
	return (curr != NULL && strEQ(str,curr->val));
}
*/
