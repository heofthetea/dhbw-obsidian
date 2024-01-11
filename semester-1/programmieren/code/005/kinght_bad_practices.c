#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    int moves_made;
    int board[8][8];
} board;


board copy_board(board from)
{
    board new;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            new.board[i][j] = from.board[i][j];
        }
    }

    new.moves_made = from.moves_made;
}


typedef struct
{
    int jump_coordinates[8][2];
    int length;
} possible_jumps;


void append_jump(int x, int y, possible_jumps jumps)
{
    jumps.jump_coordinates[jumps.length][0] = x;
    jumps.jump_coordinates[jumps.length][1] = y;
    jumps.length ++;
}

possible_jumps new_possible_jumps()
{
    possible_jumps new;
    new.length = 0;
    return new;
}




possible_jumps calculate_possible_jumps(int x, int y)
{
    possible_jumps jumps = new_possible_jumps();
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

            append_jump(temp_x, temp_y, jumps);
        }
    }
    return jumps;
}

int main()
{
    return 0;
}