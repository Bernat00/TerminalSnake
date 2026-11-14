#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "econio.h"
#include "states.h"
#include "snakeHelpers.c"


typedef enum
{
    NONE,
    SELF_OR_WALL,
    APPLE
} Collidable;

const char _snakebody = 219;
const char *snakeBodyP = &_snakebody;



Collidable collide(GameState *gs){
    TerminalSize *ts = &(gs->settings.terminalSize); //todo ez mennyire számít mókolásnak?
    SnakeNode *s = gs->snake.head;
    
    if(s->value.x == gs->apple.x && s->value.y == gs->apple.y)
        return APPLE;
    
    if(s->value.x == 0 || s->value.y == 0 || s->value.x == ts->w-1 || s->value.y == ts->h-1)
        return SELF_OR_WALL;


    for(SnakeNode *tmp = s->next; tmp != NULL; tmp = tmp->next){
        if(s->value.x == tmp->value.x && s->value.y == tmp->value.y)
            return SELF_OR_WALL;
    }

    return NONE;
}


void handleInput(GameState *gs){ //ezt egy kissé tulgondoltam
    if(econio_kbhit()) {       
        int key = econio_getch();


        Direction dir = gs->snakeDirection;

        switch (key)
        {
        case 'w':
        case 'W':
        case KEY_UP:
            dir = UP;
            break;

        
        case 's':
        case 'S':
        case KEY_DOWN:
            dir = DOWN;
            break;

        
        case 'a':
        case 'A':
        case KEY_LEFT:
            dir = LEFT;
            break;

        
        case 'd':
        case 'D':
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        
        }

        if (dir % 2 != gs->snakeDirection % 2)
            gs->snakeDirection = dir;
    }
}

Point calcNextHeadPos(GameState *gs){
    Point next;
    next.x = gs->snake.head->value.x;
    next.y = gs->snake.head->value.y;

    switch (gs->snakeDirection)
    {
    case UP:
        next.y--;
        break;
    

    case DOWN:
        next.y++;
        break;
    

    case LEFT:
        next.x--;
        break;
    

    case RIGHT:
        next.x++;
        break;
    }

    return next;
}



int thaLoop(GameState *gs){
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
            econio_gotoxy(next.x, next.y);
            printf(snakeBodyP);
            break;


        case NONE:
            econio_gotoxy(next.x, next.y);
            printf(snakeBodyP);

            econio_gotoxy(gs->snake.tail->value.x, gs->snake.tail->value.y);
            printf(" ");
            
            snakeDeleteLast(&(gs->snake));
            break;
        
        
        case SELF_OR_WALL:
            return snakeGetLen(&(gs->snake));
        } 


        timespec_get(&end, TIME_UTC);

        double elapsedS =
            (end.tv_sec - start.tv_sec) +
            (end.tv_nsec - start.tv_nsec) / 1000000000.0;
        
        double toSleep = gs->settings.difficulty / 1000.0 - elapsedS;

        if(toSleep > 0)
            econio_sleep(toSleep);

    }

    

}


int runGame(Settings *s){
    econio_clrscr();

    GameState gs;
    Snake snake;
    snakeInit(&snake);

    gs.settings = *s;
    gs.snake = snake;
    gs.snakeDirection = RIGHT;
    


    for (int i = 2; i >= 0; i--)
    {
        Point tmp;
        tmp.y = gs.settings.terminalSize.h/2;
        tmp.x = gs.settings.terminalSize.w/2 - i;
        snakeAddFhirst(&(gs.snake), tmp);
    }

    for(SnakeNode *n = gs.snake.head; n != NULL; n = n->next){
        econio_gotoxy(n->value.x, n->value.y);
        printf(snakeBodyP);
    }
    
    Point apple;
    apple.x = rand() % s->terminalSize.w;
    apple.y = rand() % s->terminalSize.h;

    if (apple.y == s->terminalSize.h/2){
        apple.y++;
    }

    gs.apple = apple;

    int tmp = thaLoop(&gs);
    snakeFree(&gs.snake);

    return tmp;

}