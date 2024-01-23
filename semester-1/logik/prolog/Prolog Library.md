
## Architektur
- [[Declarative Programming Language]]: Man beschreibt was _ist_, nicht, _wie_ 
- Wesentliche Bestandteile:
	- [[Wissensbank]] - beschreibt _Fakten_
		- [[Wissensbank]] wird in der Prolog Datei beschreiben
	- [[Prolog Interpreter]] - dynamisches User Interface. Vergleicht [[Anfrage|Prompts]] mit den Fakten derr Wissensbank.
- [[Closed World Assumption]]: Wenn etwas nicht _direkt_ und _unwiederlegbar_ aus den Fakten der Wissensbank gefolgert werden kann, wird es $false$ betrachtet

## Syntax
### Naming Conventions:
- [[Variable]]: beginnt mit _Großbuchstabe_ oder _Underscore_
- [[Atom|Atom (= Konstante)]]: beginnt mit Kleinbuchstabe, _oder_ ist wrapped in _single quotes_
- [[Komplexer Term]]: Aufgebaut wie _Funktion_ in anderen Programmiersprachen:
	- Signatur aus _Name_ und _Parametern_
	- gibt entweder $true$  oder $false$ zurück
	- `term_name/n` gibt _Stelligkeit_ für Term an
- Jedes Statement wird abgeschlossen mit einem _Punkt_ (`.`) --> vergl. Semikolon in C

### Bausteine
- Besteht im Wesentllichen aus [[Regeln (Rules)]]
	- [[Regeln (Rules)|Regeln]] sind aufgeteilt in [[Goal|Goals]]
		- Dabei steht immer _links_ genau _ein_ [[Goal]] (genannt _Head_), und _rechts_ (genannt _Body_) stehen beliebig viele _Kindgoals_
			- Syntax: `head :- body.`
				- gesprochen: "head _if_ body" --> funktioniert wie _Subjunktion_, aber umgekehrt
			- _Child Goals_ können mit `,` [[Regeln (Rules)#Konjunktion im Rumpf|konjugiert]]  und mit `;` [[Regeln (Rules)#Disjunktion im Rumpf|disjugiert]] werden
	- [[Goal|Goals]] können $true$ oder $false$ sein
		- bestehen aus [[Komplexer Term|komplexen Termen]] 
			- ein [[Komplexer Term]] besteht aus mehreren [[Term|regulären Termen]]
			- in einem [[Komplexer Term|komplexen Term]] ist stets der _äußerste_ Funktor (respective "_Funktionssymbol_") das [[Prädikat]]
#### Besondere Prädikate
[[Besondere Prädikate]]: sind in built-into Prolog
- [[Unifikation]]: `=/2`
	- Überprüft, ob es einen _Unifikator_ gibt, der zwei Terme _gleich_ macht
		- Gibt diesen Unifikator an, oder $false$ wenn es keinen gibt
	- **ACHTUNG!**: kein Occurs-Check: $X \rightarrow f(X)$ ist _valide_ Abbildung!
- [[Gleichheit]]: `==/2`
	- Überprüft, ob zwei Terme bereits gleich _sind_ --> Führt _keine_ [[Unifikation]] durch
	- Berücksichtigt _zuvor_ getätigte Variablenbindungen durch [[Unifikation]]
	- Hauptsächlich relevant für [[Ganzzahl-Arithmetik]]
		- [[Gleichheit]]

##### Ganzzahl-Arithmetik
[[Ganzzahl-Arithmetik]]
- Arbeitet mit [[Zahl|Zahlen]]
- Unterstützt [[Ganzzahl-Arithmetik#Integer-Operationen|Rechenregeln]] $\{+,-,div,mod\}$ sowie Punkt-vor-Strich und Klammern
- [[Ganzzahl-Arithmetik#Gleichheit|Variablenzuweisung]] wird mit `is` bezeichnet
	- Bindet [[Variable]] auf _linker Seite_ an _Ergebnis_ der rechten Seite
	- Unterschied zu anderen Programmiersprachen: Variable _bleibt_ gebunden!!!
- [[Vergleichsprädikate]]: Vergleichen _zwei_ [[Ganzzahl-Arithmetik|arithmetische Ausdrücke]] miteinander