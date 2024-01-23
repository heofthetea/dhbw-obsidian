Nachteil bei [[Asynchronzähler]]: Zeitlicher Shift von Flipflop zu Flipflop
--> bei hoher Anzahl von Flipflops: Kann so langsam sein, dass es einen Takt überspringt

_Lösung_: Alle Takteingänge parallel ansteuern
- vor Taktsignal erfolgt Festlegung, ob ein Flipflop zum nächsten Takt geschaltet wird
- ==> T-FF nicht mehr feasible --> [[Zweiflankengesteuertes JK-FF]]

### Vorwärts
![[synchronzaehler_binary.png]]
Erstes Flipflop ist ein T-Flipflop (makes sense - kleinste Stelle toggled)
