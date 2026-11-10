


typedef enum
{
    APPSTATE_MAIN_MENU,
    APPSTATE_GAME,
    APPSTATE_SETTINGS,
    APPSTATE_QUIT

} AppState;


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
    Point apple;
} GameState;
