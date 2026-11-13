


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
    Snake snake;
    Direction snakeDirection;
    Point apple;
    Settings settings;
} GameState;


