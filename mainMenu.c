#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "econio.h"
#include "states.c"

typedef enum {
    PLAY,
    SETTINGS,
    QUIT
} MenuOption;


const MENU_ITEM_COUNT = 3;
const char* const MENU_NAMES[] = {
    [PLAY] = "Play",
    [SETTINGS] = "Settings",
    [QUIT] = "Quit"
};

void drawMenuOpt(MenuOption opt, TerminalSize *ts, bool isSelected ){ //lehet const terminalsize kene
    int line = ts->h/2 - MENU_ITEM_COUNT/2;

    econio_gotoxy(ts->w/2 - strlen(MENU_NAMES[opt])/2, line + opt);

    if(isSelected) econio_textbackground(COL_BLUE);

    printf(MENU_NAMES[opt]);

    if(isSelected) econio_textbackground(COL_BLACK);
}

int mapToAppState(MenuOption opt){
    switch (opt)
        {
        case PLAY:
            return APPSTATE_GAME;
        case SETTINGS:
            return APPSTATE_SETTINGS;
        default:
            return APPSTATE_QUIT;
        }
}


/// @brief does the main menu
/// @param ts the size of the terminla (at least we hope its that size)
/// @return the selected AppState
AppState mainMenu(TerminalSize *ts) {
    int selectedMenuINdex = 0;

    econio_clrscr();

    

    for (int i = 0; i < MENU_ITEM_COUNT; i++)
    {
        drawMenuOpt(i, ts, selectedMenuINdex == i);
    }
    

    while (true) {       
        int key = econio_getch();

        switch (key)
        {
        case 'w':
        case 'W':
        case KEY_UP:
                drawMenuOpt(selectedMenuINdex, ts, false);

                if(selectedMenuINdex == 0)
                    selectedMenuINdex = MENU_ITEM_COUNT - 1;
                else selectedMenuINdex--;

                drawMenuOpt(selectedMenuINdex, ts, true);
            break;

        
        case 's':
        case 'S':
        case KEY_DOWN:
            drawMenuOpt(selectedMenuINdex, ts, false);
            
            if(selectedMenuINdex == MENU_ITEM_COUNT-1)
                selectedMenuINdex = 0;
            else selectedMenuINdex++;

            drawMenuOpt(selectedMenuINdex, ts, true);
            
            break;


        case 10:
        case 13:

            return mapToAppState(selectedMenuINdex);

        }
    
    }
}
