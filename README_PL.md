# Algorytmy i struktura Danych C++
[English](./README.md)

Kolekcja moich własnych implementacji klasycznych algorytmów, struktur danych oraz logiczno-matematycznych programów napisanych w C++ na przestrzeni ostatnich 6 lat.
Projekt działa jako baza pod testy optymalizacji kodu, eksperymenty z zarządzaniem pamięcią oraz narzędzie pod eksploracje zaawansowanych mechanik językowych.
## Główne kategorie algorytmów
### Matematyka i Optymalizacje
* **Sito Erastotenesa** - wydajne wyszukiwanie liczb pierwszych
* **Algorytm Euklidesa** - obliczanie największego wspólnego dzielnika (NWD)
* **Złota liczba i silnia** - obliczenia proporcji i skomplikowanych operacji iteracyjnych/rekurencyjnych
* **Interpretacja limitów** - programatyczna analiza limitów
### Operacje na sekwencjach
* **Ciąg Fibonacciego / Tribonacciego** (różne opcje implementacji: pętle, generowanie wielu wartości)
* **Ciągi rosnąco-malejące** (znajdowanie maksimów, pozycjonowanie w zbiorach, parsowanie danych z plików)
### Praca z tablicami i pamięcią
* **Algorytm Kadane'a (Suma segmentu)** - znajdowanie podtablicy o największej sumie (złożoność O(N))
* **Tablice jednowymiarowe i dwuwymiarowe** - operacje na wskaźnikach i dynamiczna alokacja
### Narzędzia
* **RNGenerator** - własny system generatora liczb pseudolosowych (PRNG)

## Środowisko
* Język: **C++**
* Architektura: Projekt opiera się na jednym rozwiązaniu (Visual Studio Solution `.slnx`), które łączy niezależne aplikacje konsolowe w spójną całość.

## Jak uruchomić wybrane algorytmy
1. Sklonuj repozytorium na swój dysk.
2. Otwórz plik `CPP-Algorithms-Collection.slnx` w Visual Studio.
3. W oknie *Solution Explorer* kliknij prawym przyciskiem myszy na projekcie, którym jesteś zainteresowany (np. `Sito Erastotenesa`) i wybierz **"Ustaw jako projekt startowy"**.
4. Skompiluj i uruchom (F5).
