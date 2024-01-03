

[[sieve.c]]

![[List of potential optimizations]]

## Initial attempt
---
- Array gets populated via play for-loop

```c
int sieve()
{
	int primes = 0;
    for (int i = 2; i < LEN_ARRAY; i++)
    {
        if (!numbers[i])
        {
            continue;
        }
        primes ++;
        for (int j = i + i; j < LEN_ARRAY; j += i)
        {
            numbers[j] = 0;
        }
    }

    return primes;
}
```
### time complexity analysis
#### initialization array
reserve space for array:
	O(n)
loop over to populate:
	O(n)

_==> $O(2n)$_
#### search of primes
_==> $O(n^2)$_

_==> HELLA SLOOOWWWWWWW_ 
	Dangles around _2.000 seconds



## Attempt 2
---
### population
For some reason this is _hella_ fast
```c
void populateArray()
{
    memset(numbers, 1, LEN_ARRAY);
}
```
_==>_ Dangles around _40 ms_ 
	--> break even with example
### search
```c
int sieve()
{
    for (int i = 2; i * i < LEN_ARRAY; i++)
    {
        if (!numbers[i])
        {
            continue;
        }
        for (int j = i + i ; j < LEN_ARRAY; j += i)
        {
            numbers[j] = 0;
        }
    }

    return 0;
}
```
### evaluation
```c
int countPrimes()
{
    int sum = 0;
    for (int i = 2; i < LEN_ARRAY; i++)
    {
        sum += numbers[i];
    }
    return sum;
}
```
- populate array via `memset` 
	- very fast lul
- split up search and evaluation:
	- search only to _square root_ of number
	- count number of primes seperately
		- [ ] use pre-built function for this?
### time complexity analysis
##### initialization
`memset` hella fast --> constant time
_==>_ $O(1)$
##### search of primes
- loop over $\sqrt{n}$
	- but still 2 loops 
_==>_ $O(n\sqrt{n})$


**==> still pretty slow** 
	Dangles around _1.400 seconds_

## Attempt 3
---
Time Complexity is now optimized
	--> Only way forward is to optimize process itself
		--> quit using array
### Search for primes
eliminate numbers starting from
	$i * i$
_==> time complexity now reduced to $O(n\ log(n))$_

```c
	for (int j = i * i ; j < LEN_ARRAY; j += i)
	{
	    numbers[j] = 0;
	}
```

### Evaluation
since every even number cannot be prime, all those get skipped 
	--> halves the number of additions that need to be performed
_==>_ Dangles around _60 ms_
	--> a bit slower than example 
```c
int countPrimes()
{
    int sum = 1;
    for (int i = 3; i < LEN_ARRAY; i += 2)
    {
        sum += numbers[i];
    }
    return sum;
}
```

