#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintBoard(int Player1, int Player2, int Player3, int Player4)
{
    static int row;
    static int column;

    for (row = 9; row >= 0; row--)
        {
            for (column = 0; column <= 9; column++)
                printf("+----");
            printf("+\n");

            //print in zig zag pattern
            if (row%2 == 0)
            {
                for (column = 0; column <= 9; column++)
                    printf("|%d%d  ", row, column);
                printf("|\n");
                for (column = 0; column <= 9; column++)
                {
                    //apparently the only way I know how to print the player pieces
                    printf("|");
                    if (Player1 == (row*10)+column) //check if Player1's position is the same as the block being printed
                        printf("A");         
                    else
                        printf(" ");
                    if (Player2 == (row*10)+column)
                        printf("B");
                    else
                        printf(" ");
                    if (Player3 == (row*10)+column)
                        printf("C");
                    else
                        printf(" ");
                    if (Player4 == (row*10)+column)
                        printf("D");
                    else
                        printf(" ");
                    
                } //this code is not the most efficient as it checks every block if there's a player in it
                printf("|\n");
            }
            else
            {
                for (column = 9; column >= 0; column--)
                    printf("|%d%d  ", row, column);
                printf("|\n");
                for (column = 9; column >= 0; column--)
                {
                    
                    printf("|");
                    if (Player1 == (row*10)+column)
                        printf("A");
                    else
                        printf(" ");
                    if (Player2 == (row*10)+column)
                        printf("B");
                    else
                        printf(" ");
                    if (Player3 == (row*10)+column)
                        printf("C");
                    else
                        printf(" ");
                    if (Player4 == (row*10)+column)
                        printf("D");
                    else
                        printf(" ");
                    
                }
                printf("|\n");
            }
        }
        for (column = 9; column >= 0; column--)
            printf("+----");
        printf("+\n");
}

void WaitForEnter(int currentPlayer, int Dice)
{
    //mini switch case
    if (Dice == 0)
        printf("Player %d's Turn, Press Enter to roll dice ", currentPlayer+1);
    else
        printf("Press Enter to continue", currentPlayer+1);
    while(getchar() != '\n');
}

int main()
{
    //declaration
    int boardposition[100] = { //keeps track of players where they are
    4, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int PlayerPos[4] = {0, 0, 0, 0}; //player position start at pos: 0
    int PlayerTurn = 0; //dictates whos turn it is
    int Totalturn = 0; //in order to tell whose turn it is by using modulo
    static int dice; //need to display dice
    

    srand(time(NULL));

    do
    {
        
        //print board
        PrintBoard(PlayerPos[0], PlayerPos[1], PlayerPos[2], PlayerPos[3]);

        //roll dice and place piece to
        PlayerTurn = Totalturn%4;
        //WaitForEnter(PlayerTurn, 0);
        dice = (rand() % 6) + 1;
        boardposition[PlayerPos[PlayerTurn]]--; //move away from old position
        
        switch (PlayerTurn)
        {
            case 0:
                printf("\nPlayer 1 rolls %d!", dice);
                PlayerPos[0] += dice; //roll dice and add to player to position
                printf("\nPlayer 1 moves to %d", PlayerPos[0]);
                break;
            case 1:
                printf("\nPlayer 2 rolls %d!", dice);
                PlayerPos[1] += dice;
                printf("\nPlayer 2 moves to %d", PlayerPos[1]);
                break;
            case 2:
                printf("\nPlayer 3 rolls %d!", dice);
                PlayerPos[2] += dice;
                printf("\nPlayer 3 moves to %d", PlayerPos[2]);
                break;
            case 3:
                printf("\nPlayer 4 rolls %d!", dice);
                PlayerPos[3] += dice;
                printf("\nPlayer 4 moves to %d", PlayerPos[3]);
                break;
        }
        printf("\nend of turn\n");
        
        
        boardposition[PlayerPos[PlayerTurn]]++; //move to new position
        //WaitForEnter(PlayerTurn, 1);
        Totalturn++;

       //does this all for 1 player, then proceed to do the same for next player    

    }while(PlayerPos[PlayerTurn] < 99);
    printf("\nPlayer %d wins, moved to %d", PlayerTurn+1, PlayerPos[PlayerTurn]);
}