#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

int knight_jump(int x, int y, int[8][8]);
int calculate_possible_jumps(int x, int y, int[8][2]);
void copy_board(int from[8][8], int to[8][8]);
int board_full(int board[8][8]);

int main()
{
    int board[8][8];

    int start_x, start_y;

    printf("Enter starting coordinate (e.g. a1, g7): ");
    scanf("%c%c", &start_x, &start_y);

    // format coordinates to match array
    start_x -= 'a';
    start_y -= '1';

    knight_jump(start_x, start_y, board);

    return 0;
}

int knight_jump(int x, int y, int board[8][8])
{
    // low-level data structures are a pain in the ass
    int possible_jumps[8][2];
    int length = calculate_possible_jumps(x, y, possible_jumps);

    if (board_full(board))
    {
        return 1;
    }


    for (int i = 0; i < length; i++)
    {
        int board_copy[8][8];
        copy_board(board, board_copy);
        
        if (knight_jump(possible_jumps[i][0], possible_jumps[i][1], board_copy))
        {
            return 1;
        }
    }

    return 0;
}

void copy_board(int from[8][8], int to[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            to[i][j] = from[i][j];
        }
    }
}

int board_full(int board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

// i should have done this way differently
int calculate_possible_jumps(int x, int y, int target[8][2])
{
    int index = 0;
    for (int i = -2; i <= 2; i++)
    {
        if (i == 0)
            continue;
        int temp_x = x + i;
        if (temp_x < 0 || temp_x > 7)
            continue;

        for (int j = -2; j <= 2; j++)
        {
            if (abs(i) == abs(j))
                continue;
            if (j == 0)
                continue;

            int temp_y = y + j;
            if (temp_y < 0 || temp_y > 7)
                continue;

            target[index][0] = temp_x;
            target[index][1] = temp_y;
            index++;
        }
    }
    return index;
}
