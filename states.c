


typedef enum
{
    APPSTATE_MAIN_MENU,
    APPSTATE_GAME,
    APPSTATE_SETTINGS,
    APPSTATE_QUIT

} AppState;


typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
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
    SnakeNode *next;
    SnakeNode *prev;
} SnakeNode;


typedef struct
{
    SnakeNode *head;
    SnakeNode *tail;
} Snake;

typedef struct 
{
    Snake snake;
    Direction snakeDirection;
    Point apple;
} GameState;
