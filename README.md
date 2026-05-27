# C++ exercises

**Nie znasz jeszcze C++?** Zacznij od **[Poradnika dla początkujących](PORADNIK.md)** — wyjaśnia `main`, `#include`, pętle `for`, funkcje, `if` i resztę używaną w zadaniach.

1. Napisz program wyznaczający wszystkie dzielniki liczby 80.

[ROZWIĄZANIE TUTAJ - kliknij](1.cpp)

2. Napisz program znajdujący najmniejszą i największą trzycyfrową liczbę pierwszą.

[ROZWIĄZANIE TUTAJ - kliknij](2.cpp)

3. Napisz program, który wyświetli największą liczbę pierwszą mniejszą od dodatniej trzycyfrowej liczby calkowitej podanej przez użytkownika.

[ROZWIĄZANIE TUTAJ - kliknij](3.cpp)

4. Napisz funkcję, która będzie badała podzielność podanej liczby jednocześnie przez 317. W teście użyj pojedynczej instrukcji logicznej (bez operatora `&8`).

[ROZWIĄZANIE TUTAJ - kliknij](4.cpp)

5. Napisz program, który dla dwóch podanych przez użytkownika liczb wyświetli informację o tym, czy ich suma jest liczbą pierwszą. Utwórz w tym celu funkcję typu bool.

[ROZWIĄZANIE TUTAJ - kliknij](5.cpp)

6. Napisz program, który dla danej liczby rzeczywistej a wyświetli wartości: `cos(a)` oraz `sin(a)`. Skorzystaj z gotowych funkcji sin oraz cos z biblioteki cmath.

[ROZWIĄZANIE TUTAJ - kliknij](6.cpp)

7. Napisz program wyświetlający liczby, których pierwiastki mieszczą się w podanym przez uzytkownika przedziale. Na przykład dla przedziału `[5; 6)]` są to liczby: 25, 26, 22, 28, 29, 30, 31, 32, 33, 34, 35, 36. W kodzie wykorzystaj biblioteke `cmath` i funkcje `sqrt`. Sprawdź działanie programu dla przedziału `[14; 19]`.

[ROZWIĄZANIE TUTAJ - kliknij](7.cpp)

8. Stwórz program, który wyznaczy wszystkie trzycyfrowe liczby pierwsze.

[ROZWIĄZANIE TUTAJ - kliknij](8.cpp)

9. Przygotuj w arkuszu kalkulacyjnym skoroszyt, który pozwoli rozstrzygnać, czy prawdziwe jest nastepujące twierdzenie: każda liczba złożona mniejsza od 100 dzieli się przynajmniej przez jedną z liczb: 2, 3, 5, 7. Skorzystaj z funkcji `MOD`.

[ROZWIĄZANIE TUTAJ - kliknij](9.md)

10. Napisz program, który po podaniu przez użytkownika liczby typu `float` wyświetli zaokrąglenia tej liczby w górę i w dół do najbliższej liczby całkowitej. Skorzystaj z funkcji `ceil` i `floor` z biblioteki `cmath`.

**Uwaga**: Zaokrąglenie do najbliższej liczby cafkowitej w gorę nazywa się sufitem, a w dół - podłogą. Stad nazwy funkcji pochodzące od angielskich stów celling i floor.

[ROZWIĄZANIE TUTAJ - kliknij](10.cpp)

11. Napisz program wyznaczający wszystkie dzielniki pierwsze liczby 80.

[ROZWIĄZANIE TUTAJ - kliknij](11.cpp)

12. Napisz w języku C++ prostą grę, w której dwóch uytkowników podaje po jednej liczbie 6-cyfrowej. Wygrywa ten, kto wskazał liczbę, która ma więcej dzielników właściwych.

[ROZWIĄZANIE TUTAJ - kliknij](12.cpp)

13. Znajdź pary dwucyfrowych i trzycyfrowych liczb bliźniaczych.

**Uwaga**: Liczby bliźniacze to dwie liczby pierwsze, ktorych różnica wynosi 2.

[ROZWIĄZANIE TUTAJ - kliknij](13.cpp)

14. Liczba 362 881 ma tę własność, że przy dzieleniu przez 2, 3, 4, 5, 6, 7 ,8 , 9 daje resztę 1. Znajdź najmniejszą liczbę o tej własności.

[ROZWIĄZANIE TUTAJ - kliknij](14.cpp)

15. Napisz program, który wyznaczy wszystkie trzycyfrowe liczby doskonałe. Liczba doskonala to liczba równa sumie swych dzielników różnych od niej samej, np. 28 = 1+2+4+7+14.

[ROZWIĄZANIE TUTAJ - kliknij](15.cpp)

16. Wśród poniższych liczb są iloczyny dwóch liczb pierwszych nieparzystych. Napisz program zawierający funkcję `sprawdz`, która pozwoli znależć te liczby.

- 1 838 947 883
- 1 004 098 109
- 851 260 967
- 809 509 261

**Wskazówka**: Funkcja `sprawdz` powinna zwracać wartość znalezionego dzielnika liczby, o ile liczba nie jest pierwsza. Wartość tę można zapamiętać. Wówczas pozostale sprawdzić jedną liczbę. Jaką? 

[ROZWIĄZANIE TUTAJ - kliknij](16.cpp)

17. Znajdź jak największą liczbę, która jest iloczynem dwóch liczb pierwszych.

**Uwaga**: Największa liczba, którą możesz uzyskać, używając typu int, to prawdopodobnie 2 147 483 647. Zależy to od używanego kompilatora.

[ROZWIĄZANIE TUTAJ - kliknij](17.cpp)

18. Napisz program, który wypisze wszystkie pary liczby bliźniaczych z przedziału `[2; 3000]`.

**Uwaga**: Liczby bliźniacze to dwie liczby pierwsze, których różnica wynosi 2.

[ROZWIĄZANIE TUTAJ - kliknij](18.cpp)

19. Napisz program, który wyświetli listę wszystkich par liczb zaprzyjaźnionych mniejszych niż milion.

**Uwaga**: Dwie liczby uważa się za zaprzyjaźnione, jeśli sumy dzielników właściwych tych liczb są równe.

[ROZWIĄZANIE TUTAJ - kliknij](19.cpp)

---

## Jak uruchomić

Skompiluj i uruchom wybrane zadanie (terminal w folderze projektu):

```bash
g++ -std=c++17 -Wall 1.cpp -o zad1 && ./zad1
```

Zamień `1.cpp` i `zad1` na numer zadania (np. `19.cpp`). Zadanie 9 to instrukcja arkusza — plik [9.md](9.md).  
Składnię i pojęcia z kodu wyjaśnia [PORADNIK.md](PORADNIK.md).
