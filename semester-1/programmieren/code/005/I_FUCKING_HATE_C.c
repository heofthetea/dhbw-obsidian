#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSIONS 8

int board[DIMENSIONS][DIMENSIONS];

void print_board(int board[DIMENSIONS][DIMENSIONS])
{
    for (int i = DIMENSIONS - 1; i >= 0; i--)
    {
        printf("[");
        for (int j = 0; j < DIMENSIONS; j++)
        {
            printf("%02d, ", board[i][j]);
        }
        printf("]\n");
    }
}

int is_valid(int coordinate[2])
{
    return (coordinate[0] >= 0 && coordinate[0] < DIMENSIONS) && (coordinate[1] >= 0 && coordinate[1] < DIMENSIONS);
}

int get_degree(int coordinate[2])
{
    int count = 0;
    int knight_jumps[8][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
    for (int i = 0; i < 8; i++)
    {
        int temp[2] = {coordinate[0] + knight_jumps[i][0], coordinate[1] + knight_jumps[i][1]};
        if (is_valid(temp) && !board[temp[0]][temp[1]])
        {
            count++;
        }
    }
    return count;
}

int *get_possible_jumps(int current[2])
{
    int jumps[8][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}};
    int possible_jumps[8][2];
    int num_jumps = 0;
    for (int i = 0; i < 8; i++)
    {
        int jump_to[2] = {current[0] + jumps[i][0], current[1] + jumps[i][1]};
        if (is_valid(jump_to) && !board[jump_to[0]][jump_to[1]])
        {
            int degree = get_degree(jump_to);
            int pos = 0;
            for (int j = 0; j < num_jumps; j++)
            {
                if (get_degree(possible_jumps[j]) < degree)
                {
                    pos++;
                }
            }
            for (int j = num_jumps; j > pos; j--)
            {
                possible_jumps[j][0] = possible_jumps[j - 1][0];
                possible_jumps[j][1] = possible_jumps[j - 1][1];
            }
            possible_jumps[pos][0] = jump_to[0];
            possible_jumps[pos][1] = jump_to[1];
            num_jumps++;
        }
    }
    int *result = malloc(num_jumps * 2 * sizeof(int));
    for (int i = 0; i < num_jumps; i++)
    {
        result[i * 2] = possible_jumps[i][0];
        result[i * 2 + 1] = possible_jumps[i][1];
    }
    return result;
}

int full(int board[DIMENSIONS][DIMENSIONS])
{
    for (int i = 0; i < DIMENSIONS; i++)
    {
        for (int j = 0; j < DIMENSIONS; j++)
        {
            if (!board[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int knight_jump(int coordinates[2], int move)
{
    board[coordinates[0]][coordinates[1]] = move;
    if (full(board))
    {
        return 1;
    }
    int *jumps = get_possible_jumps(coordinates);
    for (int i = 0; i < jumps[0] * 2; i += 2)
    {
        int jump[2] = {jumps[i], jumps[i + 1]};
        if (knight_jump(jump, move + 1))
        {
            free(jumps);
            return 1;
        }
    }
    board[coordinates[0]][coordinates[1]] = 0;
    free(jumps);
    return 0;
}

int main()
{
    for (int i = 0; i < DIMENSIONS; i++)
    {
        for (int j = 0; j < DIMENSIONS; j++)
        {
            board[i][j] = 0;
        }
    }
    int start[2];
    printf("enter starting coordinate: ");
    char input[3];
    scanf("%s", input);
    start[0] = input[1] - '1';
    start[1] = input[0] - 'a';
    printf("translated to program representation of board: [%d, %d]\n\n", start[0], start[1]);
    clock_t start_time = clock();
    knight_jump(start, 1);
    clock_t end_time = clock();
    print_board(board);
    printf("\ntime taken: %f sec\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    return 0;
}