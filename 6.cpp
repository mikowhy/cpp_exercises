/*
 * Zadanie 6:
 * Napisz program, który dla danej liczby rzeczywistej a wyświetli wartości:
 * cos(a) oraz sin(a). Skorzystaj z gotowych funkcji sin oraz cos z biblioteki cmath.
 */

// iostream — cin, cout (PORADNIK.md §3, §7)
#include <iostream>
// cmath — sin, cos (PORADNIK.md §12); kąt w radianach
#include <cmath>

int main() {
    double a;  // liczba z częścią ułamkową (PORADNIK.md §6)
    std::cout << "Podaj kat w radianach: ";
    std::cin >> a;

    std::cout << "cos(" << a << ") = " << cos(a) << '\n';
    std::cout << "sin(" << a << ") = " << sin(a) << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Zmienna double a — kąt może być ułamkowy (np. 1.57 rad).
 * 2. cout prosi o kąt; cin wczytuje wartość po Enter (użytkownik musi podać radiany).
 * 3. cos(a) i sin(a) pochodzą z #include <cmath> — gotowe wzory, nie liczymy ręcznie.
 * 4. Dwa osobne cout wypisują cosinus i sinus z podpisem, co to za wartość.
 * 5. return 0 — koniec programu po jednym obliczeniu.
 * =============================================================================
 */
