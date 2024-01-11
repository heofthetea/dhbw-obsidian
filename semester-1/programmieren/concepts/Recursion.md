> Function, that calls itself


## Beispiel: Fakultät
![[Pasted image 20240111105539.png]]

```c
int factorial(int n) {
	if (n == 0)
		return 1;
	
	return n * factorial(n - 1);
}
```


## Beispiel: Türme von Hanoi
| Scheiben | Züge |  |
| ---- | ---- | ---- |
| 1 | 1 |  |
| 2 | 3 |  |
| 3 | 7 |  |
Wie viele Züge sind notwendig?
--> rekursiv: 
$A_{1} = 1$
$A_{n+1}= 2\;A_{n} + 1$
--> explizit: $A_{n}= 2^{n} - 1$

--> 64 Scheiben (mit einer Sekunde pro Scheibe): $A_{64} \approx 6*10^{11}$ Jahre


Variable:
1 Zug = 100 instructions
CPU takt = 4 GHz
--> $4 * 10^9$ instructions/seconds --> $4 * 10^8$ seconds
==> AMD Ryzen 7 needs ~150 years


### Implementation

```python
def hanoi(from, to, disc):
	temp_pos = position \ {from, to}
	if disc == 1:
		move(disc, from, to);
	
	hanoi(from, temp_pos, disc - 1)
	move(disc,from, to)
	hanoi(temp_pos, to, disc - 1)
```

to get temp_pos index:
```python
temp_pos = (1 + 2 + 3) - (from + to)
```


## Knight jumps
[[A5 Schach.pdf]]

input: koordinates
output: chess board with  "after which move the knight is where"
(also output: the move)

==> backtracking
Optimizing strategy: Prioritize squares with _less_ opportunities to jump forward (Warnsdorf)