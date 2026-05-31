/*
 * Zadanie 3:
 * Napisz program, który wyświetli największą liczbę pierwszą mniejszą od dodatniej
 * trzycyfrowej liczby całkowitej podanej przez użytkownika.
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
    int n;
    std::cout << "Podaj dodatnia liczbe trzycyfrowa: ";
    std::cin >> n;
    for (int k = n - 1; k >= 2; --k) {
        if (czy_pierwsza(k)) {
            std::cout << "Najwieksza pierwsza mniejsza od " << n << ": " << k << '\n';
            return 0;
        }
    }
    std::cout << "Brak takiej liczby pierwszej.\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Wczytujemy n od użytkownika (cin) — dodatnia liczba trzycyfrowa z zadania.
 * 2. Pętla: kandydat zaczyna od n-1 i idzie w dół (n-2, n-3, …).
 * 3. Dla każdego kandydata wołamy czy_pierwsza — ta sama logika co w zad. 2.
 * 4. Pierwszy kandydat, dla którego funkcja zwróci true, to największa pierwsza < n.
 * 5. Wypisujemy go i return 0 — program kończy się od razu, nie szukamy dalej.
 * =============================================================================
 */
