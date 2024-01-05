## Idea:
1) search for all primes up to $sqrt(n)$
	- reaason (trivial): $a*b > n\ (if\quad a>b \ \lor \ b > a)$ for $a, b, c,\in \mathbb{N}$
	- uses _regular_ [[Sieve of Erathostenes]]
	--> represented as _array_ of 1 and 0
1) split array up into _segments_
	- instead of one giant _numbers_ array, the array is only created with the length of a segment
	- orientate towards CPU _L1d cache_ (`lscpu | grep "cache"`)
		--> maximum efficiency
3) for each segment:
	- check for multiples of _all_  primes found in _1)_


```python
primes: list = regular_sieve(until sqrt(n))

```


--> I still need to figure out why exactly this actually optimizes the algorithm
## Stolen implementation
[[segmented_sieve_stolen.c]]
--> explanation of algorithm: https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes


## Own shot at implementation
[[segmented_sieve.c]]
> since I need `stdio` for this and it redefines `timeval` from `linux/time.h`, I'm not working with Nimmzeit, instead using `clock()` to measure the time. A giant Fuck You to hoever wrote that stupid module.
### Storage of primes 
we _could_ simply use an array of size _5 761 455_ , because we only need to search until 10⁸
	 _Problem_: how do we know what place we're in?
		--> use seperate variable for this
	==> runs straight into a _Segmentation fault_

==> scratch that, HERE GOES LISTS WITH MANUAL MEMORY ALLOCATION

#### store primes
```c
typedef struct
{
    uint64_t *data;
    uint64_t max_size;
    uint64_t length;
} list_uint64;

// creates a new list filled with default values
list_uint64 new_list(uint64_t size)
{
    list_uint64 list = {
        malloc(size * sizeof(uint64_t)),
        size,
        0 
    };

    return list;
}

// appends an item to given list. List is passed as reference.
void list_append(list_uint64 *list, uint64_t value) {
    list->data[list->length++] = value;
}
```

The _list_uint64_ struct roughly emulates a _list_ in python.
##### Attributes
-  _data_ -> Pointer to where the _actual data_ of the list lies. This can be used synonimously with an array using bracket syntax: `list.data[index]`.
- _max_size_ -> How much _memory_ has been allocated. Can be used to reallocate in case there should ever be Segmentation faults to occur.
- _length_ -> equivalent to the return value of `len(list)` in python. Stores how many elements the list currently holds.
##### Appending
This is more or less a very fancy _array syntax_. It first accesses the data list via pointer operations (`list->data`), then stores the value at the end (`list->length`) and then increases the length attribute by one.



