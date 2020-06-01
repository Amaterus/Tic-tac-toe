#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int players, choice;
int checkforwin(void);
void displayboard(void);
void markboard(char mark);
int main()
{
    int gamestatus;
    char mark;
    players = 1;

    do
    {
        displayboard();
        players = (players % 2) ? 1 : 2;
        printf("Player %d, Enter a number:", players);
        scanf("%d", &choice);
        mark = (players == 1) ? 'X' : 'O';
        markboard(mark);
        gamestatus = checkforwin();
        players++;

    }while(gamestatus == -1);

    if (gamestatus == 1)
        printf("==>\aPlayer %d Won!", --players);
    else
        printf("==>\aGame Draw");
        getch();
    return 0;
}
/*************************************
Function to return game status
1 for game is over with the result
0 for game is progress
-1 for game is over and no result
**************************************/
int checkforwin(void)
{
    int returnValue = 0;
    if (square[1] == square[2] && square[2] == square[3])  /// top horizontal
    {
        returnValue = 1;
    }
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7]) /// Left Vertical
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square [9]) /// down horizontal
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])  /// right Vertical
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])  /// diagonal
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7]) /// diagonal
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' &&
             square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' &&
             square[9] != '9')
    {
        returnValue = 0;
    }
    else
        returnValue = -1;

        return returnValue;

}
/*****************************
Function to draw the board
******************************/

void displayboard(void)
{
    system("cls");
     printf("\n\n Tictac toe \n\n");
     printf("Player1 (X)  Player2 (0) \n\n\n");

     printf("   |   |   \n");
     printf("  %c|  %c| %c \n", square[1], square[2], square[3]);
     printf(" __|___|__\n");
     printf("   |   | \n");
     printf("  %c|  %c| %c \n", square[4], square[5], square[6]);
     printf(" __|___|__\n");
     printf("   |   | \n");
     printf("  %c|  %c| %c \n", square[7], square[8], square[9]);
     printf("   |   | \n\n");

}
/*********************************************************************************
Set the board with the correct character, x or o in the correct spot in the array
**********************************************************************************/

void markboard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
   else if (choice == 2 && square[2] == '2')
        square[2] = mark;
   else if (choice == 3 && square[3] == '3')
        square[3] = mark;
   else if (choice == 4 && square[4] == '4')
        square[4] = mark;
   else if (choice == 5 && square[5] == '5')
        square[5] = mark;
   else if (choice == 6 && square[6] == '6')
        square[6] = mark;
   else if (choice == 7 && square[7] == '7')
        square[7] = mark;
   else if (choice == 8 && square[8] == '8')
        square[8] = mark;
   else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    else
    {
        printf("Invalid Move:");

        players--;
        getch();
    }
}












