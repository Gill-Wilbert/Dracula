// GameView.c ... GameView ADT implementation

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Globals.h"
#include "Game.h"
#include "GameView.h"
#include "Map.h"
// #include "Map.h" ... if you decide to use the Map ADT

#define PLAY_LENGTH 8
     
     
typedef struct _player {
     int health;
     LocationID currlocation;
} player;

struct gameView {
    player players[NUM_PLAYERS];
    //char *playermessages;
    //char *pastplays;
    int score;
    int roundnum;
    int turnnum;
};

// Creates a new GameView to summarise the current state of the game
GameView newGameView(char *pastPlays, PlayerMessage messages[])
{
     
    GameView g = malloc(sizeof(struct gameView));
    int i = 0;
    int currplay = 0;
    LocationID newlocid = 0;
    char newloc[3];
      
    assert(g != NULL);
    
    //initialize score, roundnum
    g->score = 366;
    g->roundnum = 0;
    g->turnnum = 0;

    //initialize hunters 
    for(i=0; i<(NUM_PLAYERS-1); i++) {
        g->players[i].health = GAME_START_HUNTER_LIFE_POINTS;
        g->players[i].currlocation = UNKNOWN_LOCATION;
    }
        
    //initialize dracula 
    g->players[i].health = GAME_START_BLOOD_POINTS;
    g->players[i].currlocation = UNKNOWN_LOCATION;

    //loop through pastPlays to create game status  
    if (pastPlays[currplay] != '\0') {
         do {   
 
            newloc[0] = pastPlays[currplay+1];
            newloc[1] = pastPlays[currplay+2];  
            newloc[2] = '\0';
                        
            if(strcmp(newloc,"C?") == 0) {
                newlocid = 100;
            } else if (strcmp(newloc,"S?") == 0) {
                newlocid = 101;
            } else {
                newlocid = abbrevToID(newloc);
            }
            

            g->players[g->turnnum].currlocation = newlocid;
            
            g->turnnum++;
            if(g->turnnum > 4) { 
                g->roundnum++; 
                g->turnnum = 0;    
            }
             
            currplay += PLAY_LENGTH;
            
        } while(pastPlays[currplay-1] != '\0');
    }
 
    return g;
}
     
     
// Frees all memory previously allocated for the GameView toBeDeleted
void disposeGameView(GameView toBeDeleted)
{
    //COMPLETE THIS IMPLEMENTATION
    free( toBeDeleted );
}


//// Functions to return simple information about the current state of the game

// Print game information
void printGame(GameView g) {

    int i = 0;
    
    printf("*** Hunters");
    for(i=0; i<(NUM_PLAYERS-1); i++) {
        printf("player %d health: %d\n", i, g->players[i].health);
        printf("player %d location: %d\n", i, g->players[i].currlocation);
    }
    printf("*** Dracula");
    printf("player %d health: %d\n", i, g->players[i].health);
    printf("player %d location: %d\n", i, g->players[i].currlocation);

}

// Get the current round                !! as a total number, or?
Round getRound(GameView currentView)
{
    assert(currentView != NULL);
    return (Round)(currentView->roundnum);
}

// Get the id of current player - ie whose turn is it?
PlayerID getCurrentPlayer(GameView currentView)
{
    assert(currentView != NULL);
    return (PlayerID)(currentView->turnnum);
}

// Get the current score
int getScore(GameView currentView)
{
    assert(currentView != NULL);
    return currentView->score;
}

// Get the current health points for a given player
int getHealth(GameView currentView, PlayerID player)
{
    assert(currentView != NULL);
    assert(player < 5);
    return currentView->players[player].health;
}

// Get the current location id of a given player
LocationID getLocation(GameView currentView, PlayerID player)
{
    assert(currentView != NULL);
    assert(player < 5);     
    return currentView->players[player].currlocation;
}

//// Functions that return information about the history of the game

// Fills the trail array with the location ids of the last 6 turns
void getHistory(GameView currentView, PlayerID player,
                            LocationID trail[TRAIL_SIZE])
{
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
}

//// Functions that query the map to find information about connectivity

// Returns an array of LocationIDs for all directly connected locations

LocationID *connectedLocations(GameView currentView, int *numLocations,
                               LocationID from, PlayerID player, Round round,
                               int road, int rail, int sea)
{
    //REPLACE THIS WITH YOUR OWN IMPLEMENTATION
    return NULL;
}
