/*
 * Zadanie 13:
 * Znajdź pary dwucyfrowych i trzycyfrowych liczb bliźniaczych.
 *
 * Uwaga: Liczby bliźniacze to dwie liczby pierwsze, których różnica wynosi 2.
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

void wypisz_blizniacze(int od, int do_wlacznie) {
    for (int p = od; p <= do_wlacznie - 2; ++p) {
        if (czy_pierwsza(p) && czy_pierwsza(p + 2))
            std::cout << "(" << p << ", " << p + 2 << ") ";
    }
}

int main() {
    std::cout << "Pary blizniacze 2-cyfrowe (10..99):\n";
    wypisz_blizniacze(10, 99);
    std::cout << "\n\nPary blizniacze 3-cyfrowe (100..999):\n";
    wypisz_blizniacze(100, 999);
    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Bliźniacze: dwie pierwsze różniące się o 2 (p i p+2).
 * 2. Funkcja wypisz_blizniacze(od, do): pętla p; sprawdzamy p i p+2 funkcją czy_pierwsza.
 * 3. Gdy obie pierwsze, wypisujemy parę (p, p+2).
 * 4. Pierwsze wywołanie: zakres 10..99 (liczby dwucyfrowe).
 * 5. Drugie wywołanie: 100..999 (liczby trzycyfrowe) — osobno, bo para 2+3 cyfrowa przy różnicy 2 nie istnieje.
 * =============================================================================
 */
