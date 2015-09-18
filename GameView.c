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
#define TRAIL_LENGTH 6  

typedef struct _trailnode {
    LocationID location;
    int turnvisited;
    int isdoubleback;
    int ishide;
    int isvampire; 
    int traps;
} trailnode;   
     
typedef struct _player {
     trailnode trail[TRAIL_LENGTH];
     int health;
     LocationID currlocation;
} player;

struct gameView {
    player players[NUM_PLAYERS];
    //char *playermessages;
    //char *pastplays;
    int score;
    int roundnum;
    int currplayer;
};

//function to push location onto the trail[0]
//and shift the rest of the array by 1
static void pushtotrail(GameView g, LocationID newlocid) {
    int i;
    for(i=TRAIL_LENGTH-1; i>0; i--) {
        g->players[g->currplayer].trail[i] = g->players[g->currplayer].trail[i-1];
    }
	g->players[g->currplayer].trail[i].location = newlocid;
    g->players[g->currplayer].trail[i].turnvisited = g->roundnum;
    g->players[g->currplayer].trail[i].isdoubleback = 0;
    g->players[g->currplayer].trail[i].ishide = 0;
    g->players[g->currplayer].trail[i].isvampire = 0; 
    g->players[g->currplayer].trail[i].traps = 0;
}

//function to print trail for debugging
static void printtrail(GameView g) {
    printf("curr: %d\n",g->currplayer);
    printf("trail 0: %d\n",g->players[g->currplayer].trail[0].location);
    printf("trail 1: %d\n",g->players[g->currplayer].trail[1].location);
}

//function to initialize player trails
static void initializetrails(GameView g) {
    int i, k;
    for(i=0; i<NUM_PLAYERS; i++) {
        for(k=0; k<TRAIL_LENGTH; k++) {
            g->players[i].trail[k].location = -1;
        }
    }
}

//function to check if player is at sea
//requires checking for double back, etc
static int isatsea(GameView g, int player) {
    return 0;
}

// Creates a new GameView to summarise the current state of the game
GameView newGameView(char *pastPlays, PlayerMessage messages[])
{
     
    GameView g = malloc(sizeof(struct gameView));
    int i = 0;
    int currplay = 0;
    LocationID newlocid = 0;
    char newloc[3];
    int messagecount = 0;
    int offset;
      
    assert(g != NULL);
    
    //initialize score, roundnum
    g->score = 366;
    g->roundnum = 0;
    g->currplayer = 0;

    //initialize hunters 
    for(i=0; i<(NUM_PLAYERS-1); i++) {
        g->players[i].health = GAME_START_HUNTER_LIFE_POINTS;
        g->players[i].currlocation = UNKNOWN_LOCATION;
    }
        
    //initialize dracula 
    g->players[i].health = GAME_START_BLOOD_POINTS;
    g->players[i].currlocation = UNKNOWN_LOCATION;

    //initialize trails to -1
    initializetrails(g);

    //loop through pastPlays to create game status  
    if (pastPlays[currplay] != '\0') {
         do {   
                
            printf("--'%s'--\n",messages[messagecount]);
            
            newloc[0] = pastPlays[currplay+1];
            newloc[1] = pastPlays[currplay+2];  
            newloc[2] = '\0';
                        
            if(strcmp(newloc,"C?") == 0) {
                newlocid = CITY_UNKNOWN;
            } else if (strcmp(newloc,"S?") == 0) {
                newlocid = SEA_UNKNOWN;
            } else if (strcmp(newloc,"D1") == 0) {
                newlocid = DOUBLE_BACK_1;
            } else if (strcmp(newloc,"D2") == 0) {
                newlocid = DOUBLE_BACK_2;
            } else if (strcmp(newloc,"D3") == 0) {
                newlocid = DOUBLE_BACK_3;
            } else if (strcmp(newloc,"D4") == 0) {
                newlocid = DOUBLE_BACK_4;
            } else if (strcmp(newloc,"D5") == 0) {
                newlocid = DOUBLE_BACK_5;
            } else {
                newlocid = abbrevToID(newloc);
            }
            g->players[g->currplayer].currlocation = newlocid; 

            //push location to trail
            pushtotrail(g, newlocid);
            printtrail(g);

            //if Hunter
            if(g->currplayer < 4) {
                for(offset=3; offset<7; offset++) {
                    if(pastPlays[currplay+offset] == 'T') {
                         //encounter with trap
                         g->players[g->currplayer].health -= 2;      
                    } else if (pastPlays[currplay+offset] == 'D') {
                         //encounter with Dracula
                         g->players[g->currplayer].health -= 4;
                         g->players[4].health -= 10;
                    }
                }
            //else Dracula
            } else {
                for(offset=3; offset<6; offset++) {
                    if(pastPlays[currplay+offset] == 'T') {
                         //trap placed     
                    } else if (pastPlays[currplay+offset] == 'V') {
                         //vampire placed
                    } 
                }
                if(pastPlays[currplay+offset] == 'M') {
                     //trap has left the trail    
                } else if (pastPlays[currplay+offset] == 'V') {
                     //vampire has matured
                }
                
                //if at sea, Dracula loses health
                if(g->players[g->currplayer].currlocation == SEA_UNKNOWN) {
                    g->players[g->currplayer].health -= 2;
                } 
            }
 
            //increment currplayer and roundnum
            g->currplayer++;
            if(g->currplayer > 4) { 
                g->roundnum++; 
                g->currplayer = 0;    
            }
            
            //move through string input 8 chars 
            currplay += PLAY_LENGTH;
            messagecount++;
            
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
    return (PlayerID)(currentView->currplayer);
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
void getHistory(GameView g, PlayerID player, LocationID trail[TRAIL_SIZE])
{

    printf("player: %d\n",g->currplayer);
    printf("trail 0: %d\n",g->players[player].trail[0].location);
    printf("trail 1: %d\n",g->players[player].trail[1].location);
    printf("trail 2: %d\n",g->players[player].trail[2].location);
    int i;
    for(i=0; i<TRAIL_LENGTH; i++) {
        trail[i] = g->players[player].trail[i].location;
    } 
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
