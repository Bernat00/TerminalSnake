#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "econio.h"
#include "states.h"
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
    node->value = value;
    node->prev = NULL;

    if(s->head == NULL){
        s->head = node;
        s->tail = node;
        node->next = NULL;
        return true;
    }

    node->next = s->head;
    s->head->prev = node;
    s->head = node;
    return true;
}

bool snakeDeleteLast(Snake *s) {
    if (s == NULL || s->tail == NULL)
        return false;

    SnakeNode *oldTail = s->tail;
    s->tail = oldTail->prev;

    if (s->tail == NULL) {
        s->head = NULL;
    } else {
        s->tail->next = NULL;
    }

    free(oldTail);
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

int snakeGetLen(Snake *s){
    if(s == NULL || s->head == NULL || s->tail == NULL){
        return -1;
    }

    int c = 0;
    
    for(SnakeNode *n = s->head; n != NULL; n = n->next){
        c++;
    }

    return c;
}





