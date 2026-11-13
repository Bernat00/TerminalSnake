#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "econio.h"
#include "states.c"
#include <time.h>


typedef enum
{
    NONE,
    SELF_OR_WALL,
    APPLE
} Collidable;



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


void handleInput(GameState *gs){
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