/*
 * Zadanie 18:
 * Wypisz wszystkie pary liczb bliźniaczych z przedziału [2; 3000].
 *
 * Uwaga: Liczby bliźniacze — dwie pierwsze w odległości 2.
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
