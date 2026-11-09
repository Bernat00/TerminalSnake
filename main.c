#include <stdio.h>
#include <stdbool.h>
#include "econio.h"
#include "mainMenu.c"


#include <windows.h>

bool TERMINAL_GETSIZE_SUPPORT = false;



int get_terminal_size(terminalSize *ts)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    if (h == INVALID_HANDLE_VALUE || h == NULL)
        return 0;

    CONSOLE_SCREEN_BUFFER_INFO info;

    if (!GetConsoleScreenBufferInfo(h, &info))
        return 0;

    ts->w = info.srWindow.Right - info.srWindow.Left + 1;
    ts->h = info.srWindow.Bottom - info.srWindow.Top + 1;

    return 1;
}


void resizeTerminal(int width, int height)
{
    printf("\033[8;%d;%dt", height, width);
    fflush(stdout);
}


int main() {
    printf("\033[?25l"); //gpt azt mondta h ez hide-olja a cursort
    fflush(stdout);


    terminalSize ts;

    if (!get_terminal_size(&ts)){
        printf("Terminal size detection unsupported!\n");
        ts.w = 120;
        ts.h = 40;
    }
    else TERMINAL_GETSIZE_SUPPORT = true;

    
        
    econio_sleep(2);
    
    econio_clrscr();
    printf("nagyon test");

    econio_rawmode();

    
    appState state;
    do{
        state = mainMenu(&ts);
        econio_clrscr();

        switch (state)
        {
        case APPSTATE_GAME:
            while (true)
            {
                if (econio_kbhit())
                    break;
                printf("GAME state\n");
                econio_sleep(0.01);
            }
            break;
            

        case APPSTATE_QUIT:
        default:
            break;
        }
    }while(state != APPSTATE_QUIT);
    
    
    econio_normalmode();
    

    printf("\033[?25h");
    fflush(stdout);
    return 0;
}
