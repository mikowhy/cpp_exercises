/*
 * Zadanie 16:
 * Wśród podanych liczb znajdź iloczyny dwóch nieparzystych liczb pierwszych.
 * Funkcja sprawdz zwraca dzielnik, jeśli liczba nie jest pierwsza.
 *
 * - 1 838 947 883
 * - 1 004 098 109
 * - 851 260 967
 * - 809 509 261
 *
 * Wskazówka: sprawdz zwraca dzielnik p; drugi czynnik to n/p.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

// czy_pierwsza_long(n) — jak czy_pierwsza, ale dla long long (bardzo duże liczby, zad. 16).
// Zwraca bool: true = pierwsza, false = nie (n < 2 lub ma dzielnik od 2 w górę).
// √n = pierwiastek kwadratowy z n; w kodzie d*d <= n zamiast sqrt(n) — to samo co d <= √n.
// Wystarczy do √n: przy n = a*b co najmniej jeden czynnik jest <= √n (np. 36 = 4*9).
// bool i return — PORADNIK.md §11
bool czy_pierwsza_long(long long n) {
    if (n < 2) return false;
    for (long long d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

// Zwraca 0 gdy pierwsza; inaczej pierwszy znaleziony dzielnik
// long long — bardzo duże liczby (PORADNIK.md §6)
long long sprawdz(long long n) {
    if (czy_pierwsza_long(n))
        return 0;
    for (long long d = 2; d * d <= n; ++d) {
        if (n % d == 0)
            return d;
    }
    return 0;
}

void analizuj(long long n) {
    long long p = sprawdz(n);
    if (p == 0) {
        std::cout << n << " — liczba pierwsza (nie iloczyn dwoch zlozonych)\n";
        return;
    }
    long long q = n / p;
    if (czy_pierwsza_long(q) && (p % 2 == 1) && (q % 2 == 1))
        std::cout << n << " = " << p << " * " << q << " (dwie nieparzyste pierwsze)\n";
    else
        std::cout << n << " — ma dzielnik " << p << ", drugi czynnik " << q << " nie spelnia warunku\n";
}

int main() {
    analizuj(1838947883LL);
    analizuj(1004098109LL);
    analizuj(851260967LL);
    analizuj(809509261LL);
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Dla każdej z czterech stałych liczb w main wołamy analizuj(n).
 * 2. sprawdz(n): jeśli n pierwsza → zwraca 0; inaczej pierwszy znaleziony dzielnik p.
 * 3. Gdy p==0 — komunikat, że to liczba pierwsza (nie iloczyn dwóch złożonych).
 * 4. q = n/p — drugi czynnik rozkładu.
 * 5. Sprawdzamy: czy q pierwsze oraz czy p i q nieparzyste — wtedy n=p*q (dwa nieparzyste pierwsze).
 * 6. Inaczej wypisujemy, że rozkład nie spełnia warunku zadania.
 * =============================================================================
 */
