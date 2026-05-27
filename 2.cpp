/*
 * Zadanie 2:
 * Napisz program znajdujący najmniejszą i największą trzycyfrową liczbę pierwszą.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

// Funkcja bool — PORADNIK.md §11
bool czy_pierwsza(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

int main() {
    int min_pierwsza = -1, max_pierwsza = -1;  // -1 = jeszcze nie znaleziono
    for (int n = 100; n <= 999; ++n) {
        if (czy_pierwsza(n)) {
            if (min_pierwsza == -1) min_pierwsza = n;  // pierwsza trafiona = minimum
            max_pierwsza = n;  // każda kolejna pierwsza aktualizuje maximum
        }
    }
    std::cout << "Najmniejsza trzycyfrowa pierwsza: " << min_pierwsza << '\n';
    std::cout << "Najwieksza trzycyfrowa pierwsza: " << max_pierwsza << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Funkcja czy_pierwsza(n): jeśli n<2 → false; inaczej szukamy dzielnika od 2 do √n.
 * 2. Gdy znajdziemy dzielnik (n%d==0), od razu return false — n nie jest pierwsza.
 * 3. W main: min_pierwsza=-1 i max_pierwsza=-1 oznaczają „jeszcze brak wyniku”.
 * 4. Pętla for: n od 100 do 999 — każda trzycyfrowa liczba.
 * 5. Jeśli czy_pierwsza(n): przy pierwszym trafieniu zapisujemy min; zawsze aktualizujemy max.
 * 6. Po pętli wypisujemy obie znalezione wartości (101 i 997).
 * =============================================================================
 */
