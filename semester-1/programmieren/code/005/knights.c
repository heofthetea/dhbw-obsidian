#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    int x;
    int y;
} tuple;

int board[8][8];

tuple KNIGHT_JUMPS[] = {
    {2, 1},
    {1, 2},
    {2, -1},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
};

int main()
{
    printf("\n%d", KNIGHT_JUMPS[7].x);


    printf("\n");
    return 0;
}