/*
 * Zadanie 8:
 * Stwórz program, który wyznaczy wszystkie trzycyfrowe liczby pierwsze.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

bool czy_pierwsza(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

int main() {
    std::cout << "Trzycyfrowe liczby pierwsze:\n";
    for (int n = 100; n <= 999; ++n) {
        if (czy_pierwsza(n))
            std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Funkcja czy_pierwsza — identyczna idea jak w zad. 2 (test do √n).
 * 2. Pętla n od 100 do 999 przechodzi wszystkie liczby trzycyfrowe.
 * 3. if (czy_pierwsza(n)) — tylko dla pierwszych wchodzimy do środka if.
 * 4. cout wypisuje n i spację — wszystkie pierwsze w jednej linii.
 * 5. Na końcu 
 — przejście do nowej linii po liście liczb.
 * =============================================================================
 */
