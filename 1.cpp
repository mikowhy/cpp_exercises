/*
 * Zadanie 1:
 * Napisz program wyznaczający wszystkie dzielniki liczby 80.
 */

// iostream — wejście/wyjście (cout do wypisywania na ekran)
#include <iostream>

// main() — tu zaczyna się program (PORADNIK.md §5)
int main() {
    // Liczba, której dzielniki szukamy (z treści zadania)
    const int liczba = 80;

    std::cout << "Dzielniki liczby " << liczba << ":\n";

    // Pętla for — PORADNIK.md §10; % i == 0 — §8
    // Sprawdzamy każdy możliwy dzielnik od 1 do liczby włącznie
    for (int i = 1; i <= liczba; ++i) {
        // Jeśli reszta z dzielenia jest 0, to i dzieli liczbę bez reszty
        if (liczba % i == 0) {
            std::cout << i << ' ';
        }
    }

    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Ustawiamy liczbę 80 (stała — nie zmienia się w programie).
 * 2. Pętla for: i biegnie od 1 do 80 — każde i to kandydat na dzielnik.
 * 3. Warunek (liczba % i == 0): sprawdzamy resztę z dzielenia; zero = dzieli się równo.
 * 4. Gdy warunek prawdziwy, wypisujemy i i spację (cout << i << ' ').
 * 5. Po pętli wypisujemy nową linię (
) i kończymy program (return 0).
 * =============================================================================
 */
