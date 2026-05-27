/*
 * Zadanie 12:
 * Napisz prostą grę: dwóch użytkowników podaje po jednej liczbie 6-cyfrowej.
 * Wygrywa ten, kto ma więcej dzielników właściwych.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

// Dzielniki właściwe: większe niż 1 i mniejsze niż n (bez 1 i bez samej n)
int liczba_dzielnikow_wlasciwych(int n) {
    int ile = 0;
    for (int d = 2; d < n; ++d) {  // dzielniki właściwe: 2 … n-1
        if (n % d == 0)
            ++ile;  // kolejny dzielnik — zwiększ licznik
    }
    return ile;
}

int main() {
    int liczba1, liczba2;
    std::cout << "Gracz 1 — podaj liczbe 6-cyfrowa: ";
    std::cin >> liczba1;
    std::cout << "Gracz 2 — podaj liczbe 6-cyfrowa: ";
    std::cin >> liczba2;

    int d1 = liczba_dzielnikow_wlasciwych(liczba1);
    int d2 = liczba_dzielnikow_wlasciwych(liczba2);

    std::cout << "Gracz 1: " << d1 << " dzielnikow wlasciwych\n";
    std::cout << "Gracz 2: " << d2 << " dzielnikow wlasciwych\n";

    // else if — wiele przypadków (PORADNIK.md §9)
    if (d1 > d2)
        std::cout << "Wygrywa gracz 1!\n";
    else if (d2 > d1)
        std::cout << "Wygrywa gracz 2!\n";
    else
        std::cout << "Remis!\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. liczba_dzielnikow_wlasciwych: pętla d od 2 do n-1 (bez 1 i bez samej n).
 * 2. Przy każdym d, które dzieli n, zwiększamy ile (++ile).
 * 3. main: cin pobiera liczba1 i liczba2 od dwóch graczy.
 * 4. d1 i d2 to wyniki funkcji dla obu liczb — liczba dzielników właściwych każdej.
 * 5. Wypisujemy d1 i d2, żeby gracze widzieli porównanie.
 * 6. if / else if / else: większa liczba dzielników wygrywa; równe → remis.
 * =============================================================================
 */
