#ifndef STATES_H
#define STATES_H


typedef enum
{
    APPSTATE_MAIN_MENU,
    APPSTATE_GAME,
    APPSTATE_SETTINGS,
    APPSTATE_QUIT

} AppState;


typedef enum
{
    UP = 1,
    DOWN = 3,
    LEFT = 2,
    RIGHT = 4
} Direction;

typedef struct
{
    int w;
    int h;
} TerminalSize;

typedef struct
{
    int x;
    int y;
} Point;

typedef struct SnakeNode
{
    Point value;
    struct SnakeNode *next;
    struct SnakeNode *prev;
} SnakeNode;


/// @brief a head és a tail strázsák (nem tartalmaznak adatot)
typedef struct
{
    SnakeNode *head;
    SnakeNode *tail;
} Snake;



typedef enum{
    EASY = 200,
    MEDIUM = 150,
    HARD = 100
} Difficulty;

typedef struct
{
    Difficulty difficulty;
    TerminalSize terminalSize;
    bool autoResize;
} Settings;


typedef struct 
{
    Snake snake; //ennek is pointernek kellett volna lennie
    Direction snakeDirection;
    Point apple;
    Settings settings;
} GameState;

#endif


