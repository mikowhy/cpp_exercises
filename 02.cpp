/*
 * Zadanie 02:
 * Program pyta o wiek, wczytuje liczbe calkowita i wypisuje odpowiedz.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

int main() {
    int wiek;
    std::cout << "Ile masz lat? ";
    std::cin >> wiek;
    std::cout << "Masz " << wiek << " lat.\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIALA?
 * =============================================================================
 * 1. int wiek — zmienna na liczbe calkowita (np. 15).
 * 2. cout pyta uzytkownika; cin >> wiek wczytuje liczbe po Enter.
 * 3. cout skleja tekst "Masz ", wartosc wiek i " lat.", potem nowa linia.
 * 4. return 0 — koniec programu; 0 oznacza sukces.
 * =============================================================================
 */
