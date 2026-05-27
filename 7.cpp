/*
 * Zadanie 7:
 * Wyświetl liczby, których pierwiastki mieszczą się w podanym przedziale.
 * Np. [5; 6) → 25, 26, …, 35. Użyj cmath i sqrt.
 * Sprawdź działanie dla [14; 19] (obie granice włącznie).
 */

#include <iostream>
// cmath — funkcje matematyczne (sin, cos, sqrt, ceil, floor)
#include <cmath>

int main() {
    double dolna, gorna;
    char typ;
    std::cout << "Dolna granica (np. 5 lub 14): ";
    std::cin >> dolna;
    std::cout << "Gorna granica (np. 6 lub 19): ";
    std::cin >> gorna;
    std::cout << "Gorna granica wlaczna? (t=tak [14;19], n=nie [5;6)): ";
    std::cin >> typ;
    bool gorna_wlacznie = (typ == 't' || typ == 'T');

    std::cout << "Liczby n, dla ktorych sqrt(n) jest w przedziale:\n";

    // Sprawdzamy n od 1 do rozsądnego limitu (dla [14;19] wystarczy do 361)
    int limit = static_cast<int>(gorna * gorna) + 2;
    for (int n = 1; n <= limit; ++n) {
        double p = sqrt(static_cast<double>(n));
        bool ok_dol = (p >= dolna);
        bool ok_gor = gorna_wlacznie ? (p <= gorna) : (p < gorna);
        if (ok_dol && ok_gor)
            std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. Wczytujemy dolna, gorna (double) oraz znak typ — t/T = górna granica włączna ].
 * 2. gorna_wlacznie = (typ=='t' lub 'T') — decyduje, czy używamy <= czy < przy górnej granicy.
 * 3. limit = gorna²+2 — ograniczamy pętlę po n (nie sprawdzamy nieskończenie wielu liczb).
 * 4. Dla każdego n: p = sqrt(n); ok_dol: p>=dolna; ok_gor: p<=gorna lub p<gorna.
 * 5. Gdy oba warunki (ok_dol && ok_gor), wypisujemy n — to liczby, których pierwiastek wpada w przedział.
 * 6. Przykład: [5;6) → n=25..35; [14;19] z 't' → n=196..361.
 * =============================================================================
 */
