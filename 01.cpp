/*
 * Zadanie 01:
 * Program pyta o imie, wczytuje je i wypisuje powitanie.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>
// string — tekst (np. imie) zamiast liczby int
#include <string>

int main() {
    std::string imie;
    std::cout << "Jak masz na imie? ";
    std::cin >> imie;
    std::cout << "Czesc, " << imie << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIALA?
 * =============================================================================
 * 1. std::string imie — zmienna na tekst (jedno slowo bez spacji).
 * 2. cout pyta uzytkownika; cin >> imie wczytuje odpowiedz z klawiatury.
 * 3. cout wypisuje "Czesc, " i wczytane imie, potem nowa linia.
 * =============================================================================
 */
