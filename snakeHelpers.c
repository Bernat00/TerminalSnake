#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "econio.h"
#include "states.c"
#include "debugmalloc.h"


void snakeInit(Snake *s){
    s->head = NULL;
    s->tail = NULL;
}


bool snakeAddFhirst(Snake *s, Point value){ //todo megkerdezni h erdemes e az ilyewneket pointerrel?
    if(s == NULL){
        return false;
    }

    SnakeNode *node = (SnakeNode*)malloc(sizeof(SnakeNode));
    if(node == NULL){
        return false;
    }

    if(s->head == NULL){
        s->head = node;
        s->tail = node;
        return true;
    }

    node->next = s->head;
    s->head = node;
    return true;
}

bool snakeDeleteLast(Snake *s){
    if(s->tail == NULL)
        return false;

    
    SnakeNode *utsoElotti = s->tail->prev;
    free(s->tail);

    s->tail = utsoElotti;

    return true;
}

bool snakeFree(Snake *s){
    if(s == NULL || s->head == NULL || s->tail == NULL){
        return false;
    }

    SnakeNode *n = s->head;
    while(n != NULL){
        SnakeNode *tmp = n;
        n = n->next;

        free(tmp);
    }

    return true;
}


