/*
 * Zadanie 14:
 * Liczba 362 881 przy dzieleniu przez 2..9 daje resztę 1.
 * Znajdź najmniejszą liczbę o tej własności.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>

int main() {
    // NWW(2,3,4,5,6,7,8,9) = 2520 — wtedy n-1 musi być podzielne przez 2520
    const int nww = 2520;
    int k = 1;
    // while(true) + break — wyjście gdy znajdziemy odpowiedź (PORADNIK.md §10)
    while (true) {
        int n = nww * k + 1;
        bool ok = true;
        for (int d = 2; d <= 9 && ok; ++d) {
            if (n % d != 1)
                ok = false;
        }
        if (ok) {
            std::cout << "Najmniejsza taka liczba: " << n << '\n';
            break;
        }
        ++k;
    }
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. nww=2520 to najmniejsza liczba podzielna przez 2,3,…,9 — wspólny „krok”.
 * 2. Dla k=1,2,3… budujemy n = 2520*k + 1 (wtedy n-1 dzieli się przez wszystkie 2..9).
 * 3. Pętla for d=2..9: jeśli n%d != 1, ustawiamy ok=false (liczba nie pasuje).
 * 4. Gdy po sprawdzeniu ok nadal true — mamy kandydata; wypisujemy i break z while.
 * 5. Jeśli nie pasuje, ++k i próbujemy następne n — aż pierwsze trafienie: 2521.
 * =============================================================================
 */
