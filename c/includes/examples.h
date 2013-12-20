/**
#file   examples.h
#brief  Header for example fizzbuzz type solutions
#author JoYo
*/

#include <stdlib.h>
#include <stdio.h>

/* Debug Strings */

#ifdef DEBUG
#   define DEBUG_PRINT( ... )    fprintf(stderr, __VA_ARGS__ );
#   define ERROR_NOT_ZERO( ... ) if(returnValue != 0){ fprintf( stderr, "error " __VA_ARGS__ ); goto cleanUp; }
#else
#   define DEBUG_PRINT( ... )
#   define ERROR_NOT_ZERO( ... ) if(returnValue != 0){ goto cleanUp; }
#endif

#define NULL_TERMINATED ('\0')
#define NODE_END        (0xFFFFFFFFF)

/* Scrap Structures */

typedef struct scrapNode{
    void *forward;
    void *back;
    void *data;
} scrapNode;

/* Strings */

static int
findFirstUnique(
    char *string,
    char *character
    );

static int
removeDuplicates(
    char *string
    );

static int
reverseString(
    char *string,
    int   length
    );

static int
reverseStringWords(
    char *string,
    char *delimiter
    );

static int
stringLength(
    char *string,
    int  *length
    );

static int
stripString(
    char *string,
    char *character
    );




/* Linked Lists */

/* #todo */
static int
insertNode(
    scrapNode *listHead,
    void      *data
    );

/* #todo */
static int
deleteNode(
    scrapNode *listHead,
    void      *deleteMe
    );

/* #todo */
static int
splitList(
    scrapNode *listHead,
    int        pivot,
    scrapNode *lt,
    scrapNode *gt
    );
