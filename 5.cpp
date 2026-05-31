/*
 * Zadanie 5:
 * Napisz program, który dla dwóch podanych przez użytkownika liczb wyświetli
 * informację o tym, czy ich suma jest liczbą pierwszą. Utwórz funkcję typu bool.
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

// Funkcja bool zwraca wynik do if w main (PORADNIK.md §11)
bool suma_jest_pierwsza(int a, int b) {
    return czy_pierwsza(a + b);
}

int main() {
    int a, b;
    std::cout << "Podaj dwie liczby: ";
    std::cin >> a >> b;
    if (suma_jest_pierwsza(a, b))
        std::cout << "Suma " << a + b << " jest liczba pierwsza.\n";
    else
        std::cout << "Suma " << a + b << " NIE jest liczba pierwsza.\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. czy_pierwsza — pomocnicza funkcja testująca pierwszość (dzielniki do √n).
 * 2. suma_jest_pierwsza(a,b) liczy a+b i zwraca wynik czy_pierwsza dla tej sumy.
 * 3. W main wczytujemy dwie liczby jednym cin >> a >> b.
 * 4. if (suma_jest_pierwsza(...)) wybiera gałąź „TAK” lub „NIE” bez powtarzania logiki.
 * 5. W komunikacie wypisujemy też samą sumę (a+b), żeby uczeń widział sprawdzaną liczbę.
 * =============================================================================
 */
