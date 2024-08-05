#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>

// If we were to set up a Tic-Tac-Toe game,
// we would want to know whether the board's current state is solved, wouldn't we?
// Our goal is to create a function that will check that for us!

// Assume that the board comes in the form of a 3x3 array,
// where the value is 0 if a spot is empty, 1 if it is an "X", or 2 if it is an "O", like so:

//  [0, 0, 1]
//  [0, 1, 2]
//  [2, 1, 0]
// We want our function to return:

// -1 if the board is not yet finished AND no one has won yet (there are empty spots),
// 1 if "X" won,
// 2 if "O" won,
// 0 if it's a cat's game (i.e. a draw).

// You may assume that the board passed in is valid in the context of a game of Tic-Tac-Toe.


enum game_state 
{
    NOT_FINISHED = -1,
    DRAW = 0,
    X_WON = 1,
    O_WON = 2
};

enum square 
{
    EMPTY = 0,
    X = 1,
    O = 2
};

enum game_state check_game_state(const enum square board[3][3])
{   
    int state = 0;

    // checking horizontal values
    for(int j = 1; j < 3; ++j)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == j)
                return j;
            for(int k = 0; k < 3; ++k)
                if(!board[i][k])
                    state = -1;
        }

    // checking vertical values
        for(int i = 0; i < 3; ++i)
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == j)
                return j;
    
    // checking diagonally values 
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == j)
            return j;
        if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] == j)
            return j;
    }
    
    return state;
}

void game_show(const enum square board[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        printf("[ ");
        for (int j = 0; j < 3; ++j)
            printf("%d ", board[i][j]);
        printf("]\n");
    }
}



int main(void)
{
    enum square board[3][3] = {{O, EMPTY, X},
                               {X, O, O},
                               {X, O, EMPTY}};

    game_show(board);
    
    switch(check_game_state(board))
    {
    case X_WON:
        puts("X win!");
        break;
    case O_WON:
        puts("O win!");
        break;
    case DRAW:
        puts("Draw!");
        break;
    case NOT_FINISHED:
        puts("Not finished!");
        break;
    }
    
    return 0;
}


