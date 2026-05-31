/*
 * Zadanie 8:
 * Stwórz program, który wyznaczy wszystkie trzycyfrowe liczby pierwsze.
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
