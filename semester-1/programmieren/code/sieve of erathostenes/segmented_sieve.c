#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define UPPER_LIMIT 100000000
#define SEGMENT_SIZE 10000
// #define UPPER_LIMIT 100
// #define SEGMENT_SIZE 50
#define PRIMES_UNTIL_10E8 5761455

void sieve(bool *, size_t);

//------------------------------------------------------------------------------------------------

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

uint64_t segmented_sieve(bool *, size_t, list_uint64);

int main()
{

    double t1, t2, t3, t4;
    int num_primes;

    t1 = (double)clock() / CLOCKS_PER_SEC;
    bool is_prime[(size_t)sqrt(UPPER_LIMIT)];
    memset(is_prime + 2, true, sizeof(is_prime) - 2);
    list_uint64 primes = new_list(PRIMES_UNTIL_10E8 + 5);

    t2 = (double)clock() / CLOCKS_PER_SEC;
    sieve(is_prime, sizeof(is_prime));
    num_primes = segmented_sieve(is_prime, sizeof(is_prime), primes);
    t3 = (double)clock() / CLOCKS_PER_SEC;
    t4 = (double)clock() / CLOCKS_PER_SEC;

    double time_initialization = t2 - t1;
    double time_sieving = t3 - t2;
    double time_evaluation = t4 - t3;
    double time_total = time_initialization + time_sieving + time_evaluation;

    printf("\ntime for initialization: \t %.5f", time_initialization);
    printf("\ntime for sieving: \t\t %.5f", time_sieving);
    printf("\ntime for evaluation: \t\t %.5f, as we count during the sieving process itself", time_evaluation);
    printf("\n----------------------------------------");
    printf("\ntime total: \t\t\t %.5f", time_total);

    printf("\n\nnumber of primes: %d\n\n", num_primes);

    return 0;
}

uint64_t segmented_sieve(bool *is_prime, size_t len_is_prime, list_uint64 primes)
{
    uint64_t low, high;
    uint64_t num_primes = 1; // 2 is already accounted for everywhere, so we need to manually specify it
    uint64_t sieve = 3; // only look at primes larger than 2 (because multiples of 2 are trivial)
    uint64_t n = 3;
    list_uint64 multiples = new_list(primes.max_size); // need to store exactly one multiple for every prime
    bool segment[SEGMENT_SIZE];
    for (low = 0; low <= UPPER_LIMIT; low += SEGMENT_SIZE)
    {
        memset(segment, true, sizeof(segment));
        high = low + SEGMENT_SIZE - 1; // cutting one off to avoid duplicate processing of a number
        if (high > UPPER_LIMIT)
            high = UPPER_LIMIT;

        for (; sieve * sieve <= high; sieve += 2)
        {
            if (is_prime[sieve])
            {
                list_append(&primes, sieve);                    // it is a prime, so we store it
                list_append(&multiples, (sieve * sieve) - low); // appends an index to the multiples so that for every prime at index i, a multiple can be stored at the multiples.data[i]
            }
        }

        // sieves the current segment for primes
        for (int i = 0; i < primes.length; i++)
        {
            int j = multiples.data[i];
            for (; j < SEGMENT_SIZE; j += primes.data[i] * 2)
            {
                segment[j] = false;
            }
            multiples.data[i] = j - SEGMENT_SIZE; // stores the multiple that lies outside of the segment, so that next iteration the loop can be started there
        }

        for (; n <= high; n += 2)
        {
            if (segment[n - low])
            {
                num_primes++;
            }
        }
    }

    return num_primes;
}

// regular implementation of a Sieve of Eratosthenes
void sieve(bool *sieving_array, size_t len_sieving_array)
{
    for (int i = 2; i * i < len_sieving_array; i++)
    {
        if (!sieving_array[i])
        {
            continue;
        }
        for (int j = i * i; j < len_sieving_array; j += i)
        {
            sieving_array[j] = false;
        }
    }
}

