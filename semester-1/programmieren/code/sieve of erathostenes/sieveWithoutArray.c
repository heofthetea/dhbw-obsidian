
// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include "Nimmzeit.c"
#include <stdbool.h>

#define LEN_ARRAY 100000000

void populateArray();
void printArray(int, int);
int sieve();
int countPrimes();

char numbers[LEN_ARRAY];

int main()
{

    double mw1, mw2, mw3, mw4;
    int primes;

    mw1 = nimmzeit();
    populateArray();
    char *first = &numbers[0];
    mw2 = nimmzeit();
    sieve();
    mw3 = nimmzeit();
    primes = countPrimes();
    mw4 = nimmzeit();

    double timeInitialization = mw2 - mw1;
    double timeSieving = mw3 - mw2;
    double timeEvaluation = mw4 - mw3;
    double timeTotal = timeInitialization + timeSieving + timeEvaluation;

    printf("\ntime for initialization: \t %.3f", timeInitialization);
    printf("\ntime for sieving: \t\t %.3f", timeSieving);
    printf("\ntime for evaluation: \t\t %.3f", timeEvaluation);
    printf("\n--------------------------------------------");
    printf("\ntime total: \t\t\t %.3f", timeTotal);

    printf("\n\nnumber of primes: %d\n\n", primes);
    printArray(2, 13);

    return 0;
}

void populateArray()
{
    memset(numbers, 1, LEN_ARRAY);
}

int sieve()
{
    for (int i = 2; i * i < LEN_ARRAY; i++)
    {
        if (!numbers[i])
        {
            continue;
        }
        for (int j = i * i; j < LEN_ARRAY; j += i)
        {
            numbers[j] = 0;
        }
    }

    return 0;
}

int countPrimes()
{
    int sum = 1;
    for (int i = 3; i < LEN_ARRAY; i += 2)
    {
        sum += numbers[i];
    }
    return sum;
}

void printArray(int start, int end)
{
    if (start > end)
    {
        return;
    }

    for (int i = start; i <= end; i++)
    {
        printf("%d", numbers[i]);
    }
}
