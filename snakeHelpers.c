#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "econio.h"
#include "states.c"
#include "debugmalloc.h"


void snakeInit(Snake *s){
    SnakeNode *f;
    SnakeNode *l;
    f->prev = NULL;
    f->next = l;

    l->prev = f;
    l->next = NULL;

    s->head = f;
    s->tail = l;
}


bool snakeAddFhirst(Snake *s, Point value){ //todo megkerdezni h erdemes e az ilyewneket pointerrel?
    SnakeNode *node = (SnakeNode*)malloc(sizeof(SnakeNode));
    if(node == NULL)
        return false;

    node->value = value;
    node->prev = 
    node->next = s->head;
    
    s->head = node;
    s->tail->prev = node;

    return true;
}

bool snakeDeleteLast(Snake *s){
    if(s->tail == NULL || s->tail->prev == NULL)
        return false;

    s->tail->prev = s->tail->prev->prev;
}

bool snakeFree(Snake *s){
    for(SnakeNode *n = s->head.)
}


