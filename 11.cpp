/*
 * Zadanie 11:
 * Napisz program wyznaczający wszystkie dzielniki pierwsze liczby 80.
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
    const int liczba = 80;
    std::cout << "Dzielniki pierwsze liczby " << liczba << ":\n";
    for (int i = 1; i <= liczba; ++i) {
        if (liczba % i == 0 && czy_pierwsza(i))
            std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Stała liczba=80 — ta sama liczba co w zadaniu 1.
 * 2. Pętla i od 1 do 80 — szukamy wszystkich dzielników (warunek liczba%i==0).
 * 3. Dodatkowy warunek czy_pierwsza(i) — zostają tylko dzielniki będące liczbami pierwszymi.
 * 4. Wypisujemy 2 i 5 (jedyne dzielniki pierwsze liczby 80).
 * 5. Łączymy więc pomysł z zad. 1 z testem pierwszości z zad. 2.
 * =============================================================================
 */
