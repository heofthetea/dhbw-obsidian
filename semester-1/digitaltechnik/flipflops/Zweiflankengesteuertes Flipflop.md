## Funktionalität
- [[Taktsteuerung#Taktflankensteuerung|Taktflankengesteuerter]] FlipFlop
- _Aufnahme_ geschieht bei ansteigender Flanke
- _Durchschalten_ des Signals an den Ausgang erfolgt bei _abfallender_ Flanke

--> Finale Informationsverarbeitung benötigt mehrere Takte
--> Verhindert "durchrutschen" an Information ([[durchrutschende_information_ff.png]]), weil Eingangssignal schneller wechselt als Takt

### Master-Slave Aufbau
Zwei taktflankengesteuerte Flipflops werden hintereinander geschaltet:
- 1. FF wird als Master bezeichnet, 2. als Slave
- $Q_{1_{Master}}$ wird an $S_{Slave}$ angeschlossen; $Q_{2_{Master}}$ an $R_{Slave}$ 

Sowohl _Master_ als auch _Slave_ werden vom selben Takt gesteuert:
- Master reagiert auf _ansteigende_ Flanken
- Slave reagiert auf _abfallende_ Flanken

## Schaltsymbole
Werden von _einspeicher-Flipflop_ unterschieden durch $\lnot$ Symbole an den Ausgängen

--> Funktionsweise ist für jedes FF genau gleich wie als einspeicher, _außer_ dass _Eingänge_ und _Ausgänge_ jeweils 2 Takte auseinander liegen ($t_{n}$ und $t_{n+2}$)

### Zweispeicher SR-Flipflop
[[SR-Flipflop]]
![[Pasted image 20240120171938.png]]

### Zweispeicher JK-Flipflop
