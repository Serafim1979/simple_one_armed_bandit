#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int main()
{
    //game setting
    const int startingMoney = 500;
    const int turnConst = 50;
    const int doubleBonus = 60;
    const int tripleBonus = 100;

    //Logics variables
    int money = startingMoney;
    char panel0 = 'X';
    char panel1 = 'X';
    char panel2 = 'X';

    //Initialization
    srand(time(0));

    //Main loop
    do
    {
        //Render
        system("cls");

        printf("\n\n");
        printf("\t #########\n");
        printf("\t# BANDITO #\n");
        printf("\t###########\n");
        printf("\t#         #\n");
        printf("\t#  %c %c %c  #\n", panel0, panel1, panel2);
        printf("\t#         #\n");
        printf("\t###########\n");
        printf("\n");
        printf("\n");
        printf("\tMoney: %i$\n", money);

        _getch();

        //Main logics
        money = money - turnConst;

        panel0 = 3 + (rand() % 4);
        panel1 = 3 + (rand() % 4);
        panel2 = 3 + (rand() % 4);

        //Three out of three
        if((panel0 == panel1) && (panel0 == panel2))
        {
            money = money+ tripleBonus;
        }
        else
        {
            if((panel0 == panel1) || (panel1 == panel2) || (panel0 == panel2))
            {
                money = money + doubleBonus;
            }
        }

    }
    while(money >= turnConst);

    return 0;
}
