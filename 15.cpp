/*
 * Zadanie 15:
 * Wyznacz wszystkie trzycyfrowe liczby doskonałe.
 * Liczba doskonała = równa sumie dzielników właściwych (bez samej siebie).
 * Np. 28 = 1+2+4+7+14.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

int suma_dzielnikow_wlasciwych(int n) {
    int suma = 0;
    for (int d = 1; d < n; ++d) {
        if (n % d == 0)
            suma += d;
    }
    return suma;
}

int main() {
    std::cout << "Trzycyfrowe liczby doskonale:\n";
    for (int n = 100; n <= 999; ++n) {
        if (suma_dzielnikow_wlasciwych(n) == n)
            std::cout << n << '\n';
    }
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. suma_dzielnikow_wlasciwych: pętla d od 1 do n-1, dodajemy każdy dzielnik d.
 * 2. W main: pętla n od 100 do 999 — tylko trzycyfrowe.
 * 3. Porównanie: jeśli suma == n, liczba jest doskonała (definicja z zadania).
 * 4. Wypisujemy taką liczbę w nowej linii (cout << n << '
').
 * 5. W praktyce jedyna odpowiedź to 496 (28 jest doskonała, ale nie trzycyfrowa).
 * =============================================================================
 */
