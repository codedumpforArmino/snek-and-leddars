#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SnakeAndLadderChecker(int CurrentPlayer, int Snakes[], int Ladders[])
{
    static int counter;

    //this loop checks if the player is on a snake or ladder
    for (counter = 0; counter <= 16; counter += 2) //used counter += 2 because I need to access start value
    {
        if (CurrentPlayer == Ladders[counter])
        {
            printf("Player %d found a ladder! move forward to %d", CurrentPlayer+1, Ladders[counter+1]);
            return Ladders[counter+1]; //since the end value of the ladder is on the next index, new position of current player is now the next index
        }

        if (counter < 15) //since there are only 7 snakes, that would mean theres 7 start and 7 end values totalling to 14
        {
            if (CurrentPlayer == Snakes[counter])
            {
                printf("Player %d step on a snake! move back to %d", CurrentPlayer+1, Snakes[counter+1]);
                return Snakes[counter+1];
            }
        }
    }
    //loop is done checking the snakes and ladders, meaning that player is not on any snake or ladder
    return CurrentPlayer;
}

void LadderandSnakePrinter (int Position, int L[], int S[]) //function checks with 1 Block and compare with Ladders and Snakes
{
    static int counter;
    static int occupied;

    for (counter = 0; counter <= 15; counter++) //mmmm...how to skip obvious false
    {
        if ((counter+1)%2 == 1) //check if index is using the end value or not
        {
            if (L[counter] == Position)
            {
                occupied = 1;
                printf("L");
            }
                
            if (S[counter] == Position)
            {
                occupied = 1;
                printf("s");
            }
                
        }
        else
        {
            if (L[counter] == Position)
            {
                occupied = 1;
                printf("l");
            }
            else if (S[counter] == Position)
            {
                occupied = 1;
                printf("S");
            }
        }
    }

    printf("  ");
    if (occupied == 1) //if occupied by snake or ladder
        printf(" "); //print only 1 space
    else 
        printf("  "); //otherwise print only 2
    occupied = 0;
}

void PrintBoard(int Player[], int Snakes[], int Ladders[]) //changed so it accepts the array instead of individual players
{
    static int row;
    static int column;
    static int PlayerAmount;

    for (row = 9; row >= 0; row--)
        {
            for (column = 0; column <= 9; column++)
                printf("+----");
            printf("+\n");

            //print in zig zag pattern
            if (row%2 == 0)
            {
                for (column = 1; column <= 10; column++)
                {   
                    //print snake and ladder
                    printf("|");
                    LadderandSnakePrinter((row*10)+column, Ladders, Snakes);
                    //printf("%d", ((row*10)+column));
                }
                printf("|\n");
                for (column = 1; column <= 10; column++) //need to change to 10 as 'Humans' start counting at 1
                {
                    //apparently the only way I know how to print the player pieces
                    PlayerAmount = 0;
                    printf("|");
                    if (Player[PlayerAmount++] == (row*10)+column) //check if Player1's position is the same as the block being printed
                        printf("A");         
                    else //PlayerAmount is now 1, check for player 2
                        printf(" "); 
                    if (Player[PlayerAmount++]== (row*10)+column) 
                        printf("B");
                    else
                        printf(" ");
                    if (Player[PlayerAmount++] == (row*10)+column)
                        printf("C");
                    else
                        printf(" ");
                    if (Player[PlayerAmount++] == (row*10)+column)
                        printf("D");
                    else
                        printf(" ");
                    
                } //this code is not the most efficient as it checks every block if there's a player in it
                printf("|\n");
            }
            else
            {
                for (column = 10; column >= 1; column--)
                {   
                    //print snake and ladder
                    printf("|");
                    LadderandSnakePrinter((row*10)+column, Ladders, Snakes);
                    //printf("%d", ((row*10)+column));
                }
                printf("|\n");
                for (column = 10; column >= 1; column--)
                {
                    PlayerAmount = 0;
                    printf("|");
                    if (Player[PlayerAmount++] == (row*10)+column)
                        printf("A");
                    else
                        printf(" ");
                    if (Player[PlayerAmount++] == (row*10)+column)
                        printf("B");
                    else
                        printf(" ");
                    if (Player[PlayerAmount++] == (row*10)+column)
                        printf("C");
                    else
                        printf(" ");
                    if (Player[PlayerAmount++] == (row*10)+column)
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
    int boardposition[101] = { 4,//keeps track of players where they are
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int snek[14] = {97, 78, 95, 56, 88, 24, 62, 18, 48, 26, 36, 6, 32, 10}; //odds are start, even are ends. 98, 62, 68, 32, 14, 1
    int ledar[16] = {1, 38, 4, 14, 8, 30, 21, 42, 28, 76, 50, 67, 71, 92, 80, 99};
    int PlayerPos[4] = {0, 0, 0, 0}; //player position start at pos: 0
    int PlayerTurn = 0; //dictates whos turn it is
    int Totalturn = -1; //in order to tell whose turn it is by using modulo
    static int dice; //need to display dice
    

    srand(time(NULL));

    do
    {
        
        //print board
        Totalturn++; //start the game
        PrintBoard(PlayerPos, snek, ledar);

        //roll dice and place piece to
        PlayerTurn = Totalturn%4;
        WaitForEnter(PlayerTurn, 0);
        dice = (rand() % 6) + 1;
        boardposition[PlayerPos[PlayerTurn]]--; //move away from old position
        
        switch (PlayerTurn)
        {
            case 0:
                printf("\nPlayer 1 rolls %d!", dice);
                PlayerPos[0] += dice; //roll dice and add to player to position
                printf("\nPlayer 1 moves to %d", PlayerPos[0]);
                PlayerPos[0] = SnakeAndLadderChecker(PlayerPos[0], snek, ledar);
                break;
            case 1:
                printf("\nPlayer 2 rolls %d!", dice);
                PlayerPos[1] += dice;
                printf("\nPlayer 2 moves to %d", PlayerPos[1]);
                PlayerPos[1] = SnakeAndLadderChecker(PlayerPos[1], snek, ledar);
                break;
            case 2:
                printf("\nPlayer 3 rolls %d!", dice);
                PlayerPos[2] += dice;
                printf("\nPlayer 3 moves to %d", PlayerPos[2]);
                PlayerPos[2] = SnakeAndLadderChecker(PlayerPos[2], snek, ledar);
                break;
            case 3:
                printf("\nPlayer 4 rolls %d!", dice);
                PlayerPos[3] += dice;
                printf("\nPlayer 4 moves to %d", PlayerPos[3]);
                PlayerPos[3] = SnakeAndLadderChecker(PlayerPos[3], snek, ledar);
                break;
        }
        printf("\nend of turn\n");
        
        
        boardposition[PlayerPos[PlayerTurn]]++; //move to new position
        WaitForEnter(PlayerTurn, 1);
        //make winner function
       //does this all for 1 player, then proceed to do the same for next player    

    }while(PlayerPos[PlayerTurn] < 100);
    printf("\nPlayer %d wins, moved to %d", PlayerTurn+1, PlayerPos[PlayerTurn]);
}

