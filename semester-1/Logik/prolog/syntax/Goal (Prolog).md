> Jedes [[Atom (Prolog)]] und jeder [[Komplexer Term (Prolog)]] ist ein _Goal_

in [[Wissensbank]]: Aussage über Domäne
als [[Prolog Interpreter#Anfragen|Anfrage]]: Frage zur Domäne


[[Variable (Prolog)]], [[Zahl (Prolog)]] sind _keine_ Goals!!

### Syntax:
(Gleich für Fakten und Anfragen)
```Prolog
<Goal>.
```
 Beispiele:
 ```prolog
 woman(mia).
 woman(jody).
 woman(yolanda).
 dances(jody).
 party.
```

im [[Prolog Interpreter]]:
```prolog
?- woman(mia). 
true.

?- dances(jody).
true.

?- dances(mia).
false.
```
--> Es folgt _nicht_, dass Mia nicht tanzen _könnte_!!

> Alle Aussagen, die nicht mit _absoluter Sicherheit_ aus [[Wissensbank]] folgt, werden als _false_ betrachtet.

![[prolog_output_wertigkeit.png]]