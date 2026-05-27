/*
 * Zadanie 19:
 * Wyświetl listę wszystkich par liczb zaprzyjaźnionych mniejszych niż milion.
 *
 * Uwaga: Dwie liczby są zaprzyjaźnione, gdy sumy dzielników właściwych są równe.
 */

// iostream — wczytywanie (cin) i wypisywanie (cout) na ekran
#include <iostream>
// vector — tablica o zmiennym rozmiarze (tu: sumy dzielników)
#include <vector>

// Suma dzielników właściwych (wszystkie dzielniki oprócz samej n)
int suma_dzielnikow_wlasciwych(int n) {
    if (n <= 1)
        return 0;
    int suma = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            suma += d;
            int drugi = n / d;
            if (drugi != d)
                suma += drugi;
        }
    }
    return suma - n;  // odejmujemy n, bo w sumie była też liczba n
}

int main() {
    const int limit = 1000000;
    // vector — tablica suma[n] (PORADNIK.md §13)
    std::vector<int> suma(limit, 0);

    for (int n = 2; n < limit; ++n)
        suma[n] = suma_dzielnikow_wlasciwych(n);

    std::cout << "Pary zaprzyjaznione (< 1000000):\n";
    for (int a = 2; a < limit; ++a) {
        int b = suma[a];
        if (b > a && b < limit && suma[b] == a)
            std::cout << "(" << a << ", " << b << ")\n";
    }
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. suma_dzielnikow_wlasciwych: znajdujemy pary dzielników d i n/d do √n, sumujemy, odejmujemy n.
 * 2. vector suma(1000000): pod indeksem n trzymamy sumę dzielników właściwych liczby n.
 * 3. Pierwsza pętla n=2..999999: wypełniamy całą tablicę sum — kosztowne, ale potem szybkie szukanie.
 * 4. Druga pętla: dla każdego a bierzemy b = suma[a] („przyjaciel” według definicji).
 * 5. Warunek b>a: unikamy duplikatów (220,284) i (284,220).
 * 6. b<limit i suma[b]==a: liczby wzajemnie się „odwołują” — para zaprzyjaźniona.
 * 7. Wypisujemy (a,b), np. (220,284), (1184,1210), …
 * =============================================================================
 */
