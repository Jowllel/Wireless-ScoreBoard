# Notes Review Malacarne WSBR Board
Hw Konzept in signale und speisungen trennen
Pfeil nach Load switch zu board power, dass der pfad ersichtlich ist.
peripherie mcu gegenchecken
C über R10 um batms zu sieben
alternate functions stm in doc
nrf24 genauer ansehen evtl alternatives BT modul
2.4GHz neben nrf24 schreiben
sichtverbindung rf und distanz nachschauen. evtl nRf24 mit verstärker
oder 433MHz modul.
antenne richten zum display und nicht um körper.
nRF signale als TPs auf Rückseite, falls ersatz nötig.
vibrationsmotor oder buzzer als haptisches feedback
keep alive procedure in SW, falls code nicht gesendet werden konnte wiederholen und FB, wenn funktioniert oder nicht.
antnne theorie in doc lambda viertel (isotropischer strahler)
ISM Bänder
RGB LED mit connected state, wenn zu display verbunden. (Watchdog / ping)
click recognition acc und sampling mit 800Hz ausreichend?
battery far away from RF IC, dass es nicht RF absorbiert.