#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define UPPER_LIMIT 100000000
#define SEGMENT_SIZE 10000
#define PRIMES_UNTIL_10E8 5761455

void setup();
void printArray(int, int);
int sieve();
int countPrimes();

//------------------------------------------------------------------------------------------------

char *is_prime;

typedef struct
{
    uint64_t *data;    // pointer indicates where the memory of the struct instance lies
    uint64_t max_size; // the size of memory allocated
    uint64_t length;   // equivalent to java `array.length` attribute
} list_uint64;

// creates a new list filled with default values
list_uint64 new_list(uint64_t size)
{
    list_uint64 list = {
        malloc(size * sizeof(uint64_t)),
        size,
        0 // haha formatter, now you have to keep the closing brackets in the new line - I WON
    };

    return list;
}

// appends an item to given list. List is passed as reference.
void list_append(list_uint64 *list, uint64_t value)
{
    list->data[list->length++] = value; // stores the value, then increases the lists length attribute by 1
}

int main()
{

    double mw1, mw2, mw3, mw4;
    int primes;

    mw1 = (double)clock() / CLOCKS_PER_SEC;
    setup();
    mw2 = (double)clock() / CLOCKS_PER_SEC;
    sieve(is_prime);
    mw3 = (double)clock() / CLOCKS_PER_SEC;
    primes = countPrimes();
    mw4 = (double)clock() / CLOCKS_PER_SEC;

    double timeInitialization = mw2 - mw1;
    double timeSieving = mw3 - mw2;
    double timeEvaluation = mw4 - mw3;
    double timeTotal = timeInitialization + timeSieving + timeEvaluation;

    printf("\ntime for initialization: \t %.5f", timeInitialization);
    printf("\ntime for sieving: \t\t %.5f", timeSieving);
    printf("\ntime for evaluation: \t\t %.5f", timeEvaluation);
    printf("\n----------------------------------------");
    printf("\ntime total: \t\t\t %.5f", timeTotal);

    printf("\n\nnumber of primes: %d\n\n", primes);
    printArray(2, 13);

    return 0;
}

void setup()
{
    // initialize primes list
    list_uint64 primes = new_list(PRIMES_UNTIL_10E8 + 5);
    list_append(&primes, 2);
    list_append(&primes, 3);
    list_append(&primes, 5);
    list_append(&primes, 7);

    // checking whether appending works - can be removed
    for (int i = 0; i < 10; i++)
        printf("%ld", primes.data[i]);

    // initialize array that is used in the simple iteration of Sieve
    uint64_t sqrt_upper_limit = (uint64_t)sqrt(UPPER_LIMIT);
    char temp_is_prime[sqrt_upper_limit];
    memset(temp_is_prime, 1, sqrt_upper_limit);
    is_prime = temp_is_prime;
}

int sieve(bool *sieving_array)
{
    printf("\n---%lu---\n", sizeof(sieving_array)/sizeof(sieving_array[0]));
    for (int i = 2; i * i < 0; i++)
    {
        if (!sieving_array[i])
        {
            continue;
        }
        for (int j = i * i; j < UPPER_LIMIT; j += i)
        {
            sieving_array[j] = 0;
        }
    }

    return 0;
}

int countPrimes()
{
    int sum = 1;
    // for (int i = 3; i < UPPER_LIMIT; i += 2)
    // {
    //     sum += numbers[i];
    // }
    return sum;
}

//------------------------------------------------------------------------------------------------

void printArray(int start, int end)
{
    // if (start > end)
    // {
    //     return;
    // }

    // for (int i = start; i <= end; i++)
    // {
    //     printf("%d", numbers[i]);
    // }
}
