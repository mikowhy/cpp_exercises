/*
 * Zadanie 17:
 * Znajdź jak największą liczbę będącą iloczynem dwóch liczb pierwszych (typ int).
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>
// climits — stała INT_MAX (największy int)
#include <climits>
#include <cmath>

bool czy_pierwsza(int n) {
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d)
        if (n % d == 0) return false;
    return true;
}

int main() {
    long long najlepszy = 0;
    int naj_p = 0, naj_q = 0;

    // Największe p nie może przekroczyć sqrt(INT_MAX) ≈ 46340
    int max_p = static_cast<int>(sqrt(static_cast<double>(INT_MAX))) + 1;

    for (int p = max_p; p >= 2; --p) {
        if (!czy_pierwsza(p))
            continue;
        int max_q = INT_MAX / p;
        for (int q = max_q; q >= p; --q) {
            if (czy_pierwsza(q)) {
                long long il = (long long)p * q;
                if (il > najlepszy) {
                    najlepszy = il;
                    naj_p = p;
                    naj_q = q;
                }
                break;  // dla danego p największe q jest pierwsze trafione w dół
            }
        }
    }

    std::cout << "Najwiekszy iloczyn: " << najlepszy << " = " << naj_p << " * " << naj_q << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Startujemy od max_p ≈ √INT_MAX — większe p dałyby za duży iloczyn.
 * 2. Pętla p malejąco; pomijamy niepierwsze (continue).
 * 3. Dla pierwszego p: max_q = INT_MAX/p — największe q, które jeszcze mieści się w int.
 * 4. Szukamy q od max_q w dół; pierwsze pierwsze q daje największy iloczyn dla tego p.
 * 5. Mnożenie na long long (il), porównanie z najlepszy — zapamiętujemy rekord globalnie.
 * 6. break po znalezieniu q — dla danego p nie trzeba mniejszych q.
 * 7. Na końcu wypisujemy najlepszy iloczyn i pary (p, q).
 * =============================================================================
 */
