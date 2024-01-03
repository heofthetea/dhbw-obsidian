## keywords
`signed` --> specifies a value should be signed



## stdio
###### printf
prints out something
use: `printf("...", )` 


|placeholder | datatype |
|-------------|----------|
|`%d`, `%i"` | integer |
|`%f` | float |
|`%lf` | double|
|`%c` |char|
|`%u` | unsigned integer|
|`%s` | string|
|`%x, %X` | hex-darstellung |

###### scanf

**Achtung:** input buffer löschen:
```c
scanf("%i" &i);
fflush(stdin); // deletees input buffer
```
Address Operator:
`&i` - initializes variable `i` to input scanf
!! Variablen müssen deklariert sein 
![[Begriffe Programmieren#Deklaration / Definition]]

```c
float f1;
char c;

scanf("%f" &f1);
scanf("%c", &c);
scanf("%lf", &lf);
scanf("%s", text) // here no address operator, because complex data type
```

###### character array
**Strings need ending character** ==> `char[64]` can only hold 63 characters



## Arrays
**You know what an array is, you're only here for the syntax**

Beispiel: Temperatur
- stets drei Messwerte pro Tag (mogen, mittag, abend)
```c
//one-dimensional
int temperature[3];
temperature[0] = 10;

//two-dimensional
int temperatureWeekly[7][3];
temperature[4][2] = 15;

//three-dimensional
int temperature_yearly[52][7][3];
temperature_yearly[48][3][1];
```

**Achtung** keine Exceptions
--> no `IndexOutOfBounds`
==> acesses something not part of the arrey:
1. allowed to access -> writes somewhere it shouldn't be
2. not allowed to access memory -> Acces Right Violation


## Operators
#### increments
###### post-increment
`i ++` -> the usual
###### pre-increment
`++i`

```c
int i = 7;
printf("%d", ++i) // ouptus 8

i = 7;
printf("%d", i++) // outputs 7

```


### bitwise operations

| operator | logical equivalent |
| -------- | ------------------ |
| ~     | $\lnot$            |
| \|       | $\lor$             |
| &        | $\land$            |
| ^        | $\oplus$           |



```c
char a = 7, b;
b = ~a; // b == -8
```

$7_{10} = 0000 0111_2$
$\lnot (0000 0111_2) = 1111 1000_2$ 
$1111 1000_{2}= -8_{10}$

#### shift operations
```c
int a = 7, b;
b = a << 3; // b = 7 * 2³

a = 27;
b >> 2; // b = 6 (27 / 4 = 6 (ignore rest))
```

$1)\;00000111 \rightarrow 00111000$ 
$2)\; 00011011 \rightarrow$


## Pointer / Address Operators

|  Pointer | Address Operator|
|---|---|
| \* | \&|
für Pointer bei Arrays:
	$* \equiv [ ]$

Since pointers are numbers, you can do fancy math with them.
```c
int p1 = some_value;
p1 = p1 + 3; // moves the memory byte the pointer points to 3 bytes to the right
```
Pointers are type-bound:
when running pointer arithmetic, pointer increases 
### Data types

|           |            |
| --------- | ---------- |
| character | 8 bits --> |
|           |            |

### jwd pointers
uninitialized pointer, that doesn't have a value yet

### Random

rand() ==> $0 ... 32565$

```c
srand(value); // set starting value of random generation
int randint = rand();

```

Zahlen folgen _immer_ gleichem System
==> 



## dimensions of a variable
###### data type
###### name
###### value
###### address
