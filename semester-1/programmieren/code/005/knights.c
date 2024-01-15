#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#define DIMENSIONS 8

typedef struct
{
    int x;
    int y;
} tuple;

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

//-------------------------------------------------------------------

typedef struct
{
    tuple *data;    // pointer indicates where the memory of the struct instance lies
    uint64_t max_size; // the size of memory allocated
    uint64_t length;   // equivalent to java `array.length` attribute
} list_tuple;

// creates a new list filled with default values
list_tuple new_list(uint64_t size)
{
    list_tuple list = {
        malloc(size * sizeof(tuple)),
        size,
        0 // haha formatter, now you have to keep the closing brackets in the new line - I WON
    };

    return list;
}

// appends an item to given list. List is passed as reference.
void list_append(list_tuple *list, tuple value)
{
    list->data[list->length++] = value; // stores the value, then increases the lists length attribute by 1
}

int BOARD[DIMENSIONS][DIMENSIONS];

//--------------------------------------------------------------------

void print_board(int board[DIMENSIONS][DIMENSIONS])
{
    for (int i = 0; i < DIMENSIONS; i++)
    {
        for (int j = 0; j < DIMENSIONS; j++)
        {
            printf("%2.0f", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(tuple coordinate)
{
    return (coordinate.x > 0 && coordinate.x < DIMENSIONS) && (coordinate.y > 0 && coordinate.y < DIMENSIONS);
}

bool is_full(int board[DIMENSIONS][DIMENSIONS])
{
    for (int i = 0; i < DIMENSIONS; i++)
    {
        for (int j = 0; j < DIMENSIONS; j++)
        {
            if (!board[i][j])
                return false;
        }
        return true;
    }
}

int get_degree(tuple coordinate, int board[DIMENSIONS][DIMENSIONS])
{
    int count = 0;
    int length_knight_jumps = sizeof(KNIGHT_JUMPS) / sizeof(tuple);
    for (int i = 0; i < length_knight_jumps; i++)
    {
        tuple temp = {
            coordinate.x + KNIGHT_JUMPS[i].x,
            coordinate.y + KNIGHT_JUMPS[i].y};
        if (is_valid(temp))
        {

            if (!board[temp.x][temp.y])
            {
                count++;
            }
        }
    }

    return count;
}

list_tuple get_possible_jumps(tuple current, int board[DIMENSIONS][DIMENSIONS]) {
    list_tuple jumps = new_list(8);
    int length_knight_jumps = sizeof(KNIGHT_JUMPS) / sizeof(tuple);
    for(int i = 0; i < length_knight_jumps; i++) {
        tuple jump_to = {
            current.x + KNIGHT_JUMPS[i].x,
            current.y + KNIGHT_JUMPS[i].y};
        if(!is_valid(jump_to)) {
            continue;
        }
        int degree = get_degree(jump_to, board);

        int pos = 0;
        for(int j = 0; j < jumps.length; j++) {
            if(get_degree(jumps.data[j], board) < degree) {
                pos ++;
            }
        }
        // FUCK I NEED INSERTING SYNTAX
    }

}



int main()
{

    print_board(BOARD);
    // get_degree(KNIGHT_JUMPS[0], BOARD);

    printf("\n");
    return 0;
}