/*
 * Zadanie 13:
 * Znajdź pary dwucyfrowych i trzycyfrowych liczb bliźniaczych.
 *
 * Uwaga: Liczby bliźniacze to dwie liczby pierwsze, których różnica wynosi 2.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

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
