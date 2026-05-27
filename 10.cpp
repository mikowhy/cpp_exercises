/*
 * Zadanie 10:
 * Napisz program, który po podaniu przez użytkownika liczby typu float wyświetli
 * zaokrąglenia w górę i w dół do najbliższej liczby całkowitej (ceil, floor).
 *
 * Uwaga: Zaokrąglenie w górę to sufit (ceil), w dół — podłoga (floor).
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>
// cmath — funkcje matematyczne (sin, cos, sqrt, ceil, floor)
#include <cmath>

int main() {
    float x;
    std::cout << "Podaj liczbe rzeczywista (float): ";
    std::cin >> x;

    std::cout << "Sufit (ceil, w gore):  " << ceil(x) << '\n';
    std::cout << "Podloga (floor, w dol): " << floor(x) << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Wczytujemy float x — liczba rzeczywista od użytkownika.
 * 2. ceil(x) z cmath: najmniejsza liczba całkowita >= x (sufit, „w górę”).
 * 3. floor(x): największa liczba całkowita <= x (podłoga, „w dół”).
 * 4. Dwa cout z podpisami — uczeń widzi oba zaokrąglenia obok siebie.
 * 5. Np. x=3.7 → ceil=4, floor=3.
 * =============================================================================
 */
