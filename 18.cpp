/*
 * Zadanie 18:
 * Wypisz wszystkie pary liczb bliźniaczych z przedziału [2; 3000].
 *
 * Uwaga: Liczby bliźniacze — dwie pierwsze w odległości 2.
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
    std::cout << "Pary blizniaczych z [2; 3000]:\n";
    for (int p = 2; p + 2 <= 3000; ++p) {
        if (czy_pierwsza(p) && czy_pierwsza(p + 2))
            std::cout << "(" << p << ", " << p + 2 << ")\n";
    }
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. pętla p od 2 w górę; para to (p, p+2), więc warunek p+2 <= 3000.
 * 2. czy_pierwsza(p) i czy_pierwsza(p+2) — obie muszą być pierwsze.
 * 3. Gdy warunek spełniony, cout wypisuje parę w osobnej linii.
 * 4. Nie używamy else if — każda para niezależnie (wiele par w przedziale).
 * 5. Przykłady: (3,5), (5,7), … aż do p takiego, że p+2=3000.
 * =============================================================================
 */
