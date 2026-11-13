#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "econio.h"
#include "states.c"
#include "snakeHelpers.c"


typedef enum
{
    NONE,
    SELF_OR_WALL,
    APPLE
} Collidable;



Collidable collide(GameState *gs){
    TerminalSize *ts = &(gs->settings.terminalSize); //todo ez mennyire számít mókolásnak?
    SnakeNode *s = gs->snake.head;
    
    if(s->value.x == gs->apple.x && s->value.y == gs->apple.y)
        return APPLE;
    
    if(s->value.x == 0 || s->value.y == 0 || s->value.x == ts->w-1 || s->value.y == ts->h-1)
        return SELF_OR_WALL;


    for(SnakeNode *tmp = s; tmp != NULL; tmp = tmp->next){
        if(tmp->value.x == tmp->value.x && s->value.y == tmp->value.y)
            return SELF_OR_WALL;
    }

    return NONE;
}


void handleInput(GameState *gs){ //ezt egy kissé tulgondoltam
    if(econio_kbhit()) {       
        int key = econio_getch();

        switch (key)
        {
        case 'w':
        case 'W':
        case KEY_UP:
            gs->snakeDirection = UP;
            break;

        
        case 's':
        case 'S':
        case KEY_DOWN:
            gs->snakeDirection = DOWN;
            break;

        
        case 'a':
        case 'A':
        case KEY_LEFT:
            gs->snakeDirection = LEFT;
            break;

        
        case 'd':
        case 'D':
        case KEY_RIGHT:
            gs->snakeDirection = RIGHT;
            break;
        
        }
    }
}

Point calcNextHeadPos(GameState *gs){
    Point next;

    switch (gs->snakeDirection)
    {
    case UP:
        next.y = gs-> snake.head->value.y + 1;
        break;
    

    case DOWN:
        next.y = gs-> snake.head->value.y - 1;
        break;
    

    case LEFT:
        next.x = gs-> snake.head->value.x - 1;
        break;
    

    case RIGHT:
        next.x = gs-> snake.head->value.x + 1;
        break;
    }

    return next;
}



void thaLoop(GameState *gs){
    /*
        wait
        get input
        modify snake in gamestate
        handle collide (apple, gameover)
        render
    */

    

    while(true){
        struct timespec start, end;
        timespec_get(&start, TIME_UTC);


        handleInput(gs);

        Point next = calcNextHeadPos(gs);
        snakeAddFhirst(&(gs->snake), next);

        switch (collide(gs))
        {
        case APPLE:
            //todo kirajzolni
            break;

        } 

        //todo linked list addFhirst, addLast, FreeAll, RemoveLast


        timespec_get(&end, TIME_UTC);

        double elapsedMs =
            (end.tv_sec - start.tv_sec) * 1000.0 +
            (end.tv_nsec - start.tv_nsec) / 1000000.0;
        
        double toSleep = gs->settings.difficulty - elapsedMs;

        if(toSleep > 0)
            econio_sleep(toSleep);

    }

    

}


int runGame(TerminalSize *ts){
    GameState gs;


    SnakeNode *tmp = s;
    for(; tmp != NULL; tmp = tmp->next){
        
    }
}