/*
 * Zadanie 11:
 * Napisz program wyznaczający wszystkie dzielniki pierwsze liczby 80.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

bool czy_pierwsza(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

int main() {
    const int liczba = 80;
    std::cout << "Dzielniki pierwsze liczby " << liczba << ":\n";
    for (int i = 1; i <= liczba; ++i) {
        if (liczba % i == 0 && czy_pierwsza(i))
            std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Stała liczba=80 — ta sama liczba co w zadaniu 1.
 * 2. Pętla i od 1 do 80 — szukamy wszystkich dzielników (warunek liczba%i==0).
 * 3. Dodatkowy warunek czy_pierwsza(i) — zostają tylko dzielniki będące liczbami pierwszymi.
 * 4. Wypisujemy 2 i 5 (jedyne dzielniki pierwsze liczby 80).
 * 5. Łączymy więc pomysł z zad. 1 z testem pierwszości z zad. 2.
 * =============================================================================
 */
