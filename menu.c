#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "menu_colors.h"

#define cls() printf("%c[2J", (char) 27);
#define cursorHome() printf("%c[H", (char) 27);
#define cursorQueryArea() printf("%c[20J", (char) 27);
#define cursorResultsArea() printf("%c[25J", (char) 27);

uint8_t menuCmd;

uint8_t rxBuf;

void menu();
void subMenu1(void);
void subMenu2(void);
void subMenu3(void);

typedef struct
{
     void (*menuItem[20]) (void); // Array of 20 function pointers (menu queries)
} MainMenu;

MainMenu mainmenu;

void main(void)
{
    menuCmd = 0;

    mainmenu.menuItem[0] = subMenu1; // Menuquery 1
    mainmenu.menuItem[1] = subMenu2; // Menuquery 2
    mainmenu.menuItem[2] = subMenu3; // Menuquery 3

    while(1)
    {
        menu();
    }
    return;
}

void menu()
{
    cls();
    cursorHome();

    printf("Menu 1.0");

    if(menuCmd == 0) 
    { // Main menu
        cls();
        printf("Insert selection number:");
        menuCmd = getchar();
        menuCmd = strtoul(&menuCmd,0,10); // Menucmd, start from 0, 10-base number system
        printf("Command received");
    }
    else
    {
        printf("entering submenu");
        mainmenu.menuItem[menuCmd-1](); // Function call through pointer. Menuitem 0 is subMenu1
    }
    return;
}

void subMenu1() // eg. extMemMenuQuery
{
    printf("subMenu 1");
    while(1){ fflush(stdout);}
    return;
}
void subMenu2()
{
    printf("subMenu 2");
    while(1){ fflush(stdout);}
    return;
}
void subMenu3()
{
    printf("subMenu 3");
    while(1){ fflush(stdout);}
    return;
}
