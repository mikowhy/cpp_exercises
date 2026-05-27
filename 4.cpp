/*
 * Zadanie 4:
 * Napisz funkcję, która będzie badała podzielność podanej liczby jednocześnie
 * przez 3 i 17. W teście użyj pojedynczej instrukcji logicznej (bez operatora &).
 * (W README literówki: „317”, „&8” — rozwiązujemy 3 i 17, test z &&.)
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

// && = „oraz” — oba warunki naraz (PORADNIK.md §8)
bool podzielna_przez_3_i_17(int liczba) {
    return liczba % 3 == 0 && liczba % 17 == 0;
}

int main() {
    int liczba;
    std::cout << "Podaj liczbe calkowita: ";
    std::cin >> liczba;
    if (podzielna_przez_3_i_17(liczba))
        std::cout << liczba << " dzieli sie przez 3 i 17.\n";
    else
        std::cout << liczba << " NIE dzieli sie jednoczesnie przez 3 i 17.\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Funkcja podzielna_przez_3_i_17: jednym return z dwoma warunkami połączonymi &&.
 * 2. n%3==0 sprawdza podzielność przez 3; n%17==0 — przez 17; oba muszą być prawdą.
 * 3. W main wczytujemy liczbę (cin >> liczba).
 * 4. Jedno if woła funkcję — jeśli true, komunikat „dzieli się”; else — komunikat przeciwny.
 * 5. Nie ma pętli: testujemy dokładnie jedną liczbę podaną przez użytkownika.
 * =============================================================================
 */
