#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "econio.h"
#include "states.c"


typedef enum
{
    NONE,
    SELF_OR_WALL,
    APPLE
} Collidable;

void drawNext(){
    
}

Collidable Collide(TerminalSize *ts, GameState *gs){
    SnakeNode *s = gs->snake.head;
    
    if(s->value.x == gs->apple.x && s->value.y == gs->apple.y)
        return APPLE;
    
    if(s->value.x == 0 || s->value.y == 0 || s->value.x == ts->w-1 || s->value.y == ts->h-1)
        return SELF_OR_WALL;

    SnakeNode *tmp = s;
    for(; tmp != NULL; tmp = tmp->next){
        if(tmp->value.x == tmp->value.x && s->value.y == tmp->value.y)
        return SELF_OR_WALL;
    }

    return NONE;
}


int runGame(TerminalSize *ts){
    GameState gs;

}