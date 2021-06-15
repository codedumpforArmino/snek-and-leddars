#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//need to work on: the snakes and ladders AND the moving of pieces.
char DetectCharHere (int Xcoordinate[], int Ycoordinate[], int size)
{
    static int inner;
    static int outter;
    
    return 'A';
}

int main()
{
    //declaration
    int boardposition[10][10] = { // 4 is coordinate 0,0 because arrays are weird.
    4, 0, 0, 0, 0, 0, 0, 0, 0, 0, //reading this: 0,0 0,1 0,2...
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //1,0 1,1 1,2...
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, //2,0 2,1 2,2...
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int PlayerPos[4] = {0, 0, 0, 0}; //player position start at pos: 0
    char PlayerPiece[4] = {'A', 'B', 'C', 'D'}; //player are represented as letters
    int PlayerTurn = 0;
    int Totalturn = 0;
    static int placeX[4] = {0, 0, 0, 0};
    static int placeY[4] = {0, 0, 0, 0};
    static int row;
    static int column;

    srand(time(NULL));

    do
    {
        //print board, need to learn how to pass matrices to modularize
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
            }
            else
            {
                for (column = 9; column >= 0; column--)
                    printf("|%d%d  ", row, column);
                printf("|\n");
            }
                
            for (column = 0; column <= 9; column++)
            {
                //row = x, column = y
                if (boardposition[row][column] != 0)
                {
                    switch (boardposition[row][column]) //check if there is player in the board position
                    {
                        case 1:
                        //if Playerpos[row][column], print....check player pos
                            printf("|?   ");
                            //printf("|%c   ", DetectCharHere(placeX, placeY, 4));
                            break;
                        case 2:
                            printf("|??  ");
                            break;
                        case 3:
                            printf("|??? ");
                            break;
                        case 4:
                            printf("|%c%c%c%c", 'A', 'B', 'C', 'D');
                            break;
                    }
                }
                else
                    printf("|    ");
                
            }
            printf("|\n");
        }
        for (column = 9; column >= 0; column--)
            printf("+----");
        printf("+\n");

        //roll dice and place piece to
        PlayerTurn = Totalturn%4;
        switch (PlayerTurn)
        {
            case 0:
                printf("\nPlayer 1 turns");
                PlayerPos[0] += (rand() % 6) + 1; //roll dice and add to player to position
                printf("\nPlayer 1 moves to %d", PlayerPos[0]);
                break;
            case 1:
                printf("\nPlayer 2 turns");
                PlayerPos[1] += (rand() % 6) + 1;
                printf("\nPlayer 2 moves to %d", PlayerPos[1]);
                break;
            case 2:
                printf("\nPlayer 3 turns");
                PlayerPos[2] += (rand() % 6) + 1;
                printf("\nPlayer 3 moves to %d", PlayerPos[2]);
                break;
            case 3:
                printf("\nPlayer 4 turns");
                PlayerPos[3] += (rand() % 6) + 1;
                printf("\nPlayer 4 moves to %d", PlayerPos[3]);
                break;
        }
        printf("\nend of turn\n");
        
        //calculate the which row and column the player is
        boardposition[placeX[PlayerTurn]][placeY[PlayerTurn]]--; //move away from old position
        placeX[PlayerTurn] = PlayerPos[PlayerTurn] % 10; //get the x coordinate from the total position
        placeY[PlayerTurn] = PlayerPos[PlayerTurn] / 10; //get the y coordinate from the total position
        if (placeX[PlayerTurn] == 0)
            placeY[PlayerTurn]--;
        
        boardposition[placeY[PlayerTurn]][placeX[PlayerTurn]]++; //move to new position

        
        Totalturn++;

       //does this all for 1 player, then proceed to do the same for next player    

    }while(PlayerPos[PlayerTurn] < 100); //only stop until 10 (9 is 10), for now
    printf("\nPlayer %d wins, moved to %d", PlayerTurn+1, PlayerPos[PlayerTurn]);
}