![[05-Planungsprozess und Aufwandsschaetzung_vorl.pdf]]
## Einstieg: Elbphilharmonie
[[Übung Elbphilharmonie]]
#### Lösung
==> **Planungsphase war Schrott**
###### Rollenverteilung
_Stadt Hamburg_ --> Auftraggeber (Bauherr)
_Baukonzern Hochtief_ --> Auftragnehmer
_Architekturbüro_ --> PROJEKTLEITER

###### Faktoren
1) Baustopp:
2) mangelnde Kommunikation
	- Zeit in Magischem Dreieck verschiebt sich
	- Kosten haben sich erhöht
3) keine einheitlichen Ziele
4) Einen haufen spontane Änderungen: _Exchange Management_[^1]
5) Stadt eigentlich nicht verantwortlich für Geld

###### Konsequenz
_Massive_ Extrakosten
	--> Ursprüngliche Planung um ca. 10-fache erhöht
Bezahlt durch _Steuergelder_
	--> Bürger leiden


## Planungsprozess
> Planungsphase _makes or breaks_ ein Projekt!!
> Sehr Intensive Phase


Fragen:
- Was soll gemacht werden?
- mit welchen Mitteln?
- welche Kosten entstehen? 
- Welche Termine notwendig/möglich?
- Wie soll Pojekt organisiert?

![[Planungsprozess.png]]

##### Planung:
1) [[#Projektstrukturplan]]
2) Netzplan
3) --> Zeitplan (entsteht aus Netzplan)
4) etc.


### Strukturierein eines Projekts
==> *Bildet ab, was im Pflichtenheft steht*
warum? 
	--> Übersicht erhalten, Zusammenhänge entdecken
	Einteilung in überschaubare Projektteile
Naheliegend: _Baumstruktur_
##### Strukturebenen:
1) Gesamtprojekt
2) Teilprojekte
3) ...
4) [[Arbeitspaket]]

So _detailliert_ wie _nötig_, nicht so detailliert wie _möglich_ !!
	Detaillierungsgrad wird besser, je weiter das Projekt voranschreitet

--> Leaves sind immer Arbeitspakete!! Können aber auch in höheren Ebenen auftreten.


## Projektstrukturplan
![[Projektstrukturplan]]

## Arbeitspakete
![[Arbeitspaket]]



## Schätzungsproblematik

### Übung: Gesamtwert aller Münzen im Raum
> Für gute Schätzung ist viel Wissen über Projekt erforderlich! [[#Garbage in, Garbage out]]
#### 15 sekunden Zeit
```python
>>> students = 25
>>> average = 7
>>> students * average
175
```
#### 60 sekunden Zeit
25 Studenten
- average: 6
bissl weniger --> 160

==> Problem: _kein_ Wissen
==> [[#Garbage in, Garbage out]] Prinzip
Zeit ist demnach irrelevant

### Garbage in, Garbage out
| information | ==> | Aussagequalität |
| ---- | ---- | ---- |
| 100% | Wissen | _sehr_ sicher |
| 90% | Schätzen | fast sicher |
| 50% | Schätzen | mittel sicher |
| 20% | Schätzen | sehr unsicher |
| 0% | Raten | keine Aussage |

### Schätzung
![[Schätzung]]

## Übung Schätzen
[[Projektstrukturplan#Funktionsorientierter PSP|Funktionsorientierter Strukturplan]].
### PSP
tapezieren --> streichen --> Fußboden verlegen
streichen = {{Decken streichen}, {Wände streichen}}

### Schätzen: Decken Streichen
[[Schätzung#PERT-Schätzung|PERT-Schätzung]]
--> 2 Leute streichen Decken
- best case: 1 Tag
- likely: 1.5 Tage
- worst case: 2 Tage
```python
>>> best = 1
>>> avg = 1.5
>>> worst = 2
>>> (best + 4*avg + worst) / 6
1.5
```
==> End-Ergebnis: 1.5 Tage

## Aufgaben bei der Planung
![[Aufgaben_bei_Projektorganisation.png]]


## References
[^1]: Beschäftigt sich mit der Frage, wie man mit kurzfristigen Planungsänderungen umgeht