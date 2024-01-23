[[Prolog Syntax]]
### Übung Terme
[[Term (Prolog)]]
[[semester-1/goodnotes/Logik/source/Logik-handout.pdf#page=217|Logik-handout, page 217]]
1. vINCENT = [[Atom (Prolog)]]
2. Footmassage = [[Variable (Prolog)]]
3. variable23 = [[Atom (Prolog)]]
4. Variable2000 = [[Variable (Prolog)]]
5. big_kahuna_burger = [[Atom (Prolog)]]
6. 'big kahuna burger' = [[Atom (Prolog)]]
7. big kahuna burger = 3x [[Atom (Prolog)]] _or_ Nonsense
8. 'Jules' = [[Atom (Prolog)]]
9. `_Jules` = [[Variable (Prolog)]]
10. `'_Jules'` = [[Atom (Prolog)]]

---
### Übung komplexe Terme
[[Komplexer Term (Prolog)]]
[[semester-1/goodnotes/Logik/source/Logik-handout.pdf#page=221|Logik-handout, page 221]]
1. `loves(Vincent, mia)` = [[Komplexer Term (Prolog)]]
	1. Argument: Vincent ([[Variable (Prolog)]]), mia ([[Atom (Prolog)]])
	2. `loves` ist [[Prädikat (Prolog)]]
2. `'loves(Vincent, mia)'` = [[Atom (Prolog)]]
3. `Butch(Boxer)` = _Nonsense_ (groß geschriebener Funktor)
4. `boxer(Butch)` = [[Komplexer Term (Prolog)]]
	1. Argument: Butch [[Variable (Prolog)]]
	2. `boxer` ist [[Prädikat (Prolog)]]
5. `and(big(burger), kahuna(buger))` = [[Komplexer Term (Prolog)]]
	1. [[Prädikat (Prolog)]]: `and`
	2. Argumente:
		1. [[Komplexer Term (Prolog)]] big(burger)
			1. big: [[Komplexer Term (Prolog)]] - _FUNKTOR_ 
6. `and(big(X), kahuna(X))` = [[Komplexer Term (Prolog)]]
	1. gleich wie _5._, except mit Variablen anstatt Atomen
7. `_and(big(X), kahuna(X))` = _Nonsense_ (Prädikat mit leading Underscore)
8. `(Butch kills Vincent)` = _Nonsense_ (what the fuck????)
9. `kills(Butch Vincent)` = _Nonsense_ (kein Trennkomma)
10. `kills(Butch, Vincent` = _Nonsens_ (no closing Bracket)
11. `kills(Butch, Vincent)` = [[Komplexer Term (Prolog)]]
	1. Argumente: 2x verschiedene [[Variable (Prolog)]]
	2. kills ist [[Prädikat (Prolog)]]
12. `kills(Butch(X), Vincent(Y))` = _Nonsense_ (Funktoren groß geschrieben)
