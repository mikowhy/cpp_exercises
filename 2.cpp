/*
 * Zadanie 2:
 * Napisz program znajdujący najmniejszą i największą trzycyfrową liczbę pierwszą.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

// czy_pierwsza(n) — sprawdza, czy n jest liczbą pierwszą (dzieli się tylko przez 1 i n).
// Zwraca bool: true = pierwsza, false = nie (np. n < 2 albo ma dzielnik od 2 w górę).
// √n (pierwiastek kwadratowy z n) — liczba x taka, że x*x == n (np. √36 = 6, √17 ≈ 4,1).
// W kodzie nie wołamy sqrt(n): warunek d*d <= n oznacza to samo co d <= √n.
// Dlaczego wystarczy do √n? Gdy n = a * b, co najmniej jeden czynnik jest <= √n
// (np. 36 = 4*9 — mniejszy dzielnik 4 jest poniżej √36 = 6; większy 9 powyżej).
// Pętla d od 2: gdy n % d == 0 → return false; brak dzielnika → return true.
// bool i return — PORADNIK.md §11
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
