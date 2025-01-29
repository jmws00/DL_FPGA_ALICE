# System Kontroli Lasera na FPGA Artix-7

## Opis projektu

System kontroli lasera zaimplementowany na płytce Artix-7 FPGA, wykorzystujący procesor MicroBlaze. Projekt umożliwia generowanie precyzyjnych serii impulsów laserowych z konfigurowalnymi parametrami czasowymi.

## Funkcjonalności

* Generowanie serii N impulsów laserowych
* Konfigurowalny czas trwania całej serii (T1)
* Definiowany czas trwania pojedynczego impulsu (T2)
* Komunikacja przez interfejs UART
* Sterowanie poprzez komendy terminala
* Implementacja w języku Verilog i na procesorze MicroBlaze

## Architektura systemu

### Sprzęt

* Płytka rozwojowa: Artix-7 FPGA
* Procesor: MicroBlaze (soft processor)
* Interfejs komunikacyjny: UART

## Zasada działania

1. Użytkownik wprowadza parametry przez terminal UART:
   * N: liczba impulsów w serii
   * T1: całkowity czas trwania serii
   * T2: czas trwania pojedynczego impulsu

2. System generuje serię N impulsów o czasie trwania T2 każdy
3. Jeśli czas T1 jest dłuższy niż czas potrzebny na wygenerowanie wszystkich impulsów, sygnał pozostaje na poziomie 0 do końca czasu T1

## Konfiguracja i użytkowanie

1. Połącz się z systemem przez UART
2. Użyj terminala do wysłania komend konfiguracyjnych


## Autorzy

Jakub Marszałek
Wiktor Szmyd
