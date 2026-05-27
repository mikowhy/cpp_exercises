/*
 * Zadanie 3:
 * Napisz program, który wyświetli największą liczbę pierwszą mniejszą od dodatniej
 * trzycyfrowej liczby całkowitej podanej przez użytkownika.
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
