# Poradnik C++ — od zera

Ten plik tłumaczy rzeczy z zadań 1–19 **prostym językiem**.  
Nie musisz wszystkiego pamiętać na pamięć — po prostu wyszukaj, gdy w kodzie coś wygląda dziwnie.

**Jak korzystać:** trzymaj ten plik obok otwartego `.cpp`, użyj wyszukiwania (Ctrl+F / Cmd+F) po słowie kluczowym (`for`, `vector`, `cin`…). Masz pytanie przy konkretnej linii w `5.cpp` lub `12.cpp`? Wyszukaj hasło w poradniku.

---

## Spis treści

1. [Kompilacja i rodzaje plików](#1-kompilacja-i-rodzaje-plików)
   - [Dwa rodzaje plików](#dwa-rodzaje-plików--najważniejsze)
   - [Kompilacja krok po kroku](#co-to-jest-kompilacja)
   - [Komenda `g++`](#komenda-krok-po-kroku)
2. [Komentarze w kodzie](#2-komentarze-w-kodzie)
3. [`#include` — biblioteki (przegląd)](#3-include--biblioteki-przegląd)
4. [`std::` przed `cout` i `cin`](#4-dlaczego-jest-std-przed-cout-i-cin)
5. [Funkcja `main()`](#5-funkcja-main--start-programu)
   - [`return 0;`](#dlaczego-na-końcu-main-piszemy-return-0)
6. [Zmienne, typy, `const`, `long long`](#6-zmienne-typy-const-long-long)
   - [Tabela typów](#tabela-typów-te-z-ćwiczeń-i-okolice)
   - [`long long` i `LL`](#long-long-i-sufiks-ll-zad-16-17)
7. [`cout` i `cin`](#7-wypisywanie-na-ekran-i-wczytywanie-z-klawiatury)
   - [Wypisywanie (`cout`)](#wypisywanie-na-ekran-stdcout)
   - [Wczytywanie (`cin`)](#wczytywanie-z-klawiatury-stdcin)
8. [Wyrażenia i operatory](#8-wyrażenia-znaki-porównania-łączenie-warunków-=-vs-)
9. [Instrukcja `if`](#9-instrukcja-if--jeślito)
10. [Pętle `for` i `while`](#10-pętle-for-i-while)
11. [Własne funkcje i `bool`](#11-własne-funkcje-i-bool)
12. [Biblioteka `cmath`](#12-biblioteka-cmath-zad-6-7-10)
13. [`vector` (zad. 19)](#13-vector--elastyczna-tablica-zad-19)
14. [Nawiasy `( )`, `[ ]`, `{ }`, `< >`](#14-nawiasy-----)
15. [Jak czytać pliki zadań](#15-jak-czytać-pliki-zadań--kolejność-nauki)
16. [Słowniczek](#16-słowniczek-na-szybko)

---

## 1. Kompilacja i rodzaje plików

### Dwa rodzaje plików — najważniejsze

| Plik            | Przykład                                            | Kto go „czyta”                    | Co to jest                                                          |
| --------------- | --------------------------------------------------- | --------------------------------- | ------------------------------------------------------------------- |
| **Z kodem**     | `1.cpp`, `7.cpp`                                    | **Ty** w edytorze i program `g++` | Zwykły plik tekstowy — tu piszesz i zapisujesz rozwiązanie          |
| **Wykonywalny** | `zad1`, `zad7` (Mac/Linux) lub `zad1.exe` (Windows) | **Komputer** (system)             | Program gotowy do uruchomienia — **nie** edytuje się go jak notatki |

**`.cpp`** = plik z kodem C++ (litera **c** + **plus** + **plus**).  
To **przepis** — opis krok po kroku, co program ma zrobić.

**Plik wykonywalny** = **gotowe danie** — komputer już wie, co ma robić, żeby np. policzyć dzielniki i wypisać wynik na ekranie.

```
  1.cpp  ──(kompilacja)──►  zad1  ──(uruchomienie)──►  wynik na ekranie
  tekst                    program
  dla człowieka            dla komputera
```

---

### Co to jest kompilacja?

**Kompilacja** to **tłumaczenie** kodu z języka C++ (dla ludzi) na język, który rozumie komputer.

1. Piszesz / poprawiasz plik **`1.cpp`**.
2. Uruchamiasz **program `g++`** (to on „tłumaczy” kod).
3. Program sprawdza, czy w kodzie nie ma literówek i błędów — jeśli coś źle, **nie** powstanie program do uruchomienia, tylko komunikaty o błędzie.
4. Gdy wszystko OK — powstaje **plik wykonywalny**.
5. Uruchamiasz ten plik — dopiero wtedy działa `cout`, `cin`, pętle itd.

**Bez kompilacji** plik `.cpp` to tylko tekst — dwuklik na `1.cpp` **nie uruchomi** programu jak gry czy aplikacji.

---

### Komenda krok po kroku

```bash
g++ -std=c++17 -Wall 1.cpp -o zad1
./zad1
```

| Część        | Znaczenie                                                               |
| ------------ | ----------------------------------------------------------------------- |
| `g++`        | program do tłumaczenia kodu (musi być zainstalowany)                    |
| `-std=c++17` | używamy wersji języka C++17 (jak w README)                              |
| `-Wall`      | pokaż więcej ostrzeżeń — pomaga łapać błędy                             |
| `1.cpp`      | **wejście** — który plik z kodem `.cpp`, który kompilujemy              |
| `-o zad1`    | **wyjście** — jak ma nazywać się plik wykonywalny                       |
| `./zad1`     | **uruchom** program (Mac / Linux; kropka-slash = „z bieżącego folderu”) |

Na **Windows** w PowerShell często: `.\zad1.exe` (jeśli program dodał `.exe`).

---

### Jakie pliki mogą powstać na dysku?

| Plik                                 | Kiedy powstaje                      | Czy musisz go znać?                        |
| ------------------------------------ | ----------------------------------- | ------------------------------------------ |
| `1.cpp`                              | Ty zapisujesz w edytorze            | **Tak** — tu pracujesz                     |
| `zad1` (wykonywalny)                 | po udanej kompilacji                | **Tak** — to uruchamiasz                   |
| `1.o` lub `1.obj`                    | czasem pośredni „klocek” kompilacji | Na start **nie** — `g++` robi to sam w tle |
| pliki w folderze `.cursor_temp` itd. | narzędzia, nie C++                  | Można ignorować                            |

Po kompilacji w folderze masz więc zwykle:

- **`1.cpp`** — zostaje; edytujesz go przy poprawkach.
- **`zad1`** — można usunąć i zbudować ponownie; po zmianie w `.cpp` **trzeba skompilować jeszcze raz**, inaczej uruchomisz **starą** wersję programu.

---

### Co edytujesz, a czego nie

| Działanie                             | `1.cpp`            | plik wykonywalny `zad1`                   |
| ------------------------------------- | ------------------ | ----------------------------------------- |
| Otworzyć w Cursorze / Notepad++       | tak                | nie ma sensu (to nie tekst dla człowieka) |
| Zmienić kod                           | tak                | nie — zmiany robi się w `.cpp`            |
| Uruchomić program                     | nie (sam z siebie) | tak (`./zad1`)                            |
| Wysłać nauczycielowi jako rozwiązanie | **tak** — `.cpp`   | zwykle **nie** — oddajesz kod źródłowy    |

---

### Krótka ściąga: cały proces

1. Edytuj **`N.cpp`** (np. zadanie 7 → `7.cpp`).
2. Skompiluj: `g++ -std=c++17 -Wall 7.cpp -o zad7`
3. Uruchom: `./zad7`
4. Zmieniłeś kod? Powtórz kroki **2 i 3**.

Potem w programie może coś **wypisać** na ekran (`cout`) albo **wczytać** liczby z klawiatury (`cin`) — ale tylko po uruchomieniu pliku wykonywalnego.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ od zera. Właśnie przeczytałam, że plik .cpp to kod dla ludzi, a po kompilacji (g++) powstaje plik wykonywalny, który uruchamiam przez ./zad1. Wyjaśnij mi prostym językiem po polsku: (1) czym kompilator różni się od interpretera, (2) dlaczego po każdej zmianie w .cpp muszę kompilować od nowa, (3) co oznaczają typowe komunikaty błędu kompilacji na przykładzie. Podaj 2–3 krótkie przykłady komend w terminalu. Bez zaawansowanego żargonu.
```

---

## 2. Komentarze w kodzie

Program **ignoruje** (przy kompilacji) komentarze — są tylko dla człowieka.

```cpp
// To jest komentarz w jednej linii

/*
   To jest komentarz
   na wiele linii
*/
```

Na początku każdego pliku z zadaniem jest **treść zadania** w komentarzu.  
Na końcu — blok **„JAK TO DZIAŁA?”** z opisem całego algorytmu.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i wiem, że komentarze // oraz /* */ kompilator ignoruje. Wyjaśnij po polsku prostymi słowami: kiedy warto pisać komentarze w kodzie ucznia, a kiedy lepiej poprawić nazwę zmiennej zamiast komentarza; czym różni się komentarz od kodu, który się wykonuje; podaj 3 dobre i 2 złe przykłady komentarzy w małym programie z main i pętlą for.
```

---

## 3. `#include` — biblioteki (przegląd)

Na początku pliku `.cpp` często widzisz linię:

```cpp
#include <iostream>
```

To **nie jest** zwykły kod programu (nie wykonuje się w `main` jak `cout` czy pętla).  
To **polecenie dla programu `g++`**, zanim zbuduje on Twój program:

> „Dołącz do tego pliku gotowe narzędzia z wybranej biblioteki.”

Dopiero wtedy program **zna** np. `std::cout`, `sqrt` albo `std::vector` — i pozwala Ci ich używać w kodzie poniżej.

### Co to jest biblioteka? (bardzo prosto)

**Biblioteka** to gotowy „zestaw narzędzi”, który ktoś już napisał — Ty tylko z niego korzystasz.

| Porównanie                 | Co to znaczy dla programu                                                           |
| -------------------------- | ----------------------------------------------------------------------------------- |
| **Biblioteka książkowa**   | Nie piszesz encyklopedii od zera — **bierzesz gotową książkę** i szukasz odpowiedzi |
| **Pudełko z narzędziami**  | Zamiast kuć młotek sam, **bierzesz młotek z pudełka** i wbijasz gwóźdź              |
| **Aplikacja na telefonie** | Nie programujesz aparatu — **używasz gotowej funkcji „zrób zdjęcie”**               |

W C++:

- **Twoje zadanie** (`1.cpp`, `7.cpp`…) — to **Twój** przepis: co dokładnie ma się stać.
- **Biblioteka** (`iostream`, `cmath`…) — to **gotowe kawałki programu**: ktoś już napisał wypisywanie na ekran, `sin`, tablicę — Ty tylko z tego korzystasz.

```cpp
#include <iostream>   // „Weź mi proszę narzędzia od wejścia/wyjścia”
std::cout << "Cześć"; // używasz gotowego narzędzia — nie piszesz obsługi monitora sam
```

**Bez biblioteki** musiałbyś napisać setki linii kodu, żeby cokolwiek pojawiło się na ekranie.  
**Z biblioteką** wystarczą dwie linie: `#include` + `cout`.

| Biblioteka | Co jest w „pudełku” | Po co uczniowi              |
| ---------- | ------------------- | --------------------------- |
| `iostream` | ekran, klawiatura   | pytanie użytkownika i wynik |
| `cmath`    | sinus, pierwiastek… | zadania matematyczne        |
| `vector`   | duża tablica liczb  | zad. 19                     |

`#include <…>` to tylko **prośba**: „dołącz to pudełko do mojego programu”.  
Im więcej potrzebujesz, tyle razy `#include` — ale tylko te, z których naprawdę korzystasz.

### Z czego składa się taka linia?

| Część        | Znaczenie                                                                 |
| ------------ | ------------------------------------------------------------------------- |
| `#`          | Znaczy: to specjalna linia (nie jak zwykły kod w `main`)                  |
| `include`    | **Dołącz** gotowy plik z opisem narzędzi (co wolno używać w kodzie)       |
| `<iostream>` | Nazwa biblioteki w nawiasach ostrych — gotowa biblioteka dołączona do C++ |

- Nawiasy **`< >`** — plik dołączany automatycznie z C++ (nie piszesz go sam).
- Nawiasy **`" "`** — np. `#include "moj_plik.h"` — własny plik w projekcie (u nas prawie nie używamy).

**Zasada:** jeśli w kodzie wołasz coś z danej biblioteki, na górze pliku musi być odpowiedni `#include`. Inaczej program przy kompilacji wypisze błąd — np. że nie zna `cout`.

### Wszystkie `#include` z naszych zadań — jedna tabela

| Linia w kodzie        | Pełna nazwa / skrót                    | Po co to                                        | Co zyskujesz (przykłady)                        | Zadania    |
| --------------------- | -------------------------------------- | ----------------------------------------------- | ----------------------------------------------- | ---------- |
| `#include <iostream>` | ekran i klawiatura                     | pytanie i wynik na ekranie                      | `std::cout`, `std::cin`, `<<`, `>>`             | 1–8, 10–18 |
| `#include <cmath>`    | liczby: sinus, pierwiastek…            | zadania z matematyką                            | `sin`, `cos`, `sqrt`, `ceil`, `floor`           | 6, 7, 10   |
| `#include <vector>`   | tablica — wiele liczb pod rząd         | wiele liczb pod rzędu z numerem w tablicy `[ ]` | `std::vector<int> tab(1000, 0);`, `tab[i] = 5;` | 19         |
| `#include <climits>`  | informacja o największej liczbie `int` | limit wielkości liczby                          | `INT_MAX` — ok. 2 147 483 647                   | 17         |

Każda biblioteka to **osobny zestaw narzędzi**. Nie musisz dołączać wszystkich — tylko te, z których korzystasz w danym pliku.


| Biblioteka | Szczegóły w poradniku |
| ---------- | --------------------- |
| `iostream` | [§7 — `cout` i `cin`](#7-wypisywanie-na-ekran-i-wczytywanie-z-klawiatury) |
| `cmath`    | [§12 — biblioteka `cmath`](#12-biblioteka-cmath-zad-6-7-10) |
| `vector`   | [§13 — `vector`](#13-vector--elastyczna-tablica-zad-19) |
| `climits`  | `INT_MAX` — limit typu `int`; przy dużych liczbach patrz [§6](#6-zmienne-typy-const-long-long) |



### Jak to zapamiętać?

1. Patrzysz w kod — widzisz np. `std::cout` → na górze pliku musi być `#include <iostream>`.
2. Widzisz `sqrt` → potrzebujesz `#include <cmath>`.
3. Kolejność zwykle nie ma znaczenia, ale **wszystkie `#include` dajemy na początku pliku**, przed funkcjami i `main`.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i rozumiem, że #include <iostream> dołącza gotową bibliotekę. Wyjaśnij po polsku jak metaforę „pudełka z narzędziami”: czym jest plik nagłówkowy, dlaczego bez include nie znam cout, oraz czym różni się #include <...> od #include "...". Porównaj krótko iostream, cmath i vector — po co każda w typowym programie szkolnym. Na końcu podaj mini-listę: widzę w kodzie X → potrzebuję którego include.
```

---

## 4. Dlaczego jest `std::` przed `cout` i `cin`?

To **krótki dopisek**: „to narzędzie z gotowej biblioteki C++”, a nie coś, co sama wymyśliłaś.

```cpp
std::cout << "Cześć";
std::cin >> liczba;
```

- **`std::cout`** — wypisywanie na ekran  
- **`std::cin`** — wczytywanie z klawiatury  

Bez `std::` program często się nie skompiluje. Na ćwiczeniach **zawsze** pisz `std::cout` i `std::cin`.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i muszę pisać std::cout oraz std::cin. Wyjaśnij po polsku prostymi słowami: co to jest przestrzeń nazw (namespace) std, dlaczego bez std:: kompilator się skarży, oraz czym jest using namespace std i dlaczego na lekcji często każą go nie używać. Podaj krótki przykład z dwoma „pudełkami” nazw, żebym zrozumiała ideę, nie tylko regułę.
```

---

## 5. Funkcja `main()` — start programu

```cpp
int main() {
    // tutaj piszesz, co program ma zrobić
    return 0;
}
```

- Każdy program **musi** mieć dokładnie jedną funkcję `main`.
- Od niej zaczyna się wykonywanie.

Wszystko, co ma się wykonać „po uruchomieniu”, ląduje **w środku** `main`, chyba że wywołujesz **inne funkcje**, które sam napiszesz.

### Dlaczego na końcu `main` piszemy `return 0;`?

Zapis `int main()` znaczy: funkcja `main` na końcu **oddaje liczbę** (zwykle 0 = „wszystko poszło OK”).

```cpp
int main() {
    // ... cały program ...
    return 0;   // „kończę pracę i zwracam liczbę 0”
}
```

| Co się dzieje                   | Wyjaśnienie                                                       |
| ------------------------------- | ----------------------------------------------------------------- |
| Program dochodzi do `return 0;` | `main` się kończy, program **przestaje działać**                  |
| Zwracana jest liczba **0**      | W systemie (Windows, Mac, Linux) **0 = wszystko OK**, bez błędu   |
| Inna liczba (np. `return 1;`)   | Sygnał: program zakończył się z **błędem** (u nas rzadko używane) |

**Na ćwiczeniach:** na końcu każdego `main` zawsze dopisz **`return 0;`** — tak robi się w prawie każdym zadaniu.

Czy można bez tego? Czasem program i tak „dopisze” `return 0` sam, ale **lepiej napisać wprost** — wtedy wiesz, że program świadomie się kończy.

`return` w **innych** funkcjach (np. `return false;` w `czy_pierwsza`) to co innego — tam zwracamy **wynik tej jednej funkcji**, a nie całego programu. Tylko `main` kończy całe uruchomienie pliku `.cpp`.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i wiem, że program zaczyna się w int main() i kończy return 0;. Wyjaśnij po polsku: dlaczego musi być dokładnie jedna funkcja main, co oznacza int przed main, skąd system wie, że 0 to sukces, oraz co się dzieje krok po kroku od uruchomienia ./program do return 0. Porównaj return w main z return w innej funkcji na prostym przykładzie.
```

---

## 6. Zmienne, typy, `const`, `long long`

Typ zmiennej mówi komputerowi, **jakiego rodzaju** informację przechowujesz (całka, ułamek, tak/nie…).

### Tabela typów (te z ćwiczeń i okolice)

| Typ         | Co przechowuje                              | Przykład w kodzie             | Gdzie u nas                            | Uwagi                                                 |
| ----------- | ------------------------------------------- | ----------------------------- | -------------------------------------- | ----------------------------------------------------- |
| `int`       | liczba całkowita (bez ułamka)               | `int n = 80;`                 | prawie wszystkie zadania               | np. -3, 0, 999; do ok. ±2 mld                         |
| `long long` | bardzo duża liczba całkowita                | `long long n = 1838947883LL;` | zad. 16, 17 (mnożenie)                 | na końcu liczby często `LL`; większy zakres niż `int` |
| `double`    | liczba z częścią ułamkową                   | `double a = 1.57;`            | zad. 6, 7                              | dokładniejsza niż `float`; kąty w radianach, `sqrt`   |
| `float`     | liczba z ułamkiem (mniej miejsca w pamięci) | `float x = 3.14f;`            | zad. 10                                | litera `f` po liczbie; wystarczy do `ceil`/`floor`    |
| `bool`      | tylko **prawda** lub **fałsz**              | `bool ok = true;`             | zad. 4, 5, funkcje typu `czy_pierwsza` | wartości: `true`, `false`; używane w `if`             |
| `char`      | pojedynczy znak                             | `char odp = 't';`             | zad. 7 (odpowiedź t/n)                 | pojedyncze cudzysłowy: `'a'`, `'\n'`                  |
| `const int` | stała — liczba, której **nie zmieniamy**    | `const int liczba = 80;`      | zad. 1, 11, 14, 19                     | po przypisaniu nie wolno pisać `liczba = 90;`         |

### Typy „złożone” (pojawiają się rzadziej)

| Typ / konstrukcja                        | Co to jest                                | Przykład                             | Gdzie u nas                    |
| ---------------------------------------- | ----------------------------------------- | ------------------------------------ | ------------------------------ |
| `std::vector<int>`                       | tablica liczb `int` o zadanej długości    | `std::vector<int> suma(1000000, 0);` | zad. 19                        |
| `void`                                   | funkcja tylko coś robi, nie oddaje liczby | rzadko u nas                         | —                              |
| wynik funkcji `int`, `bool`, `long long` | co funkcja **zwraca** (oddaje z powrotem) | `bool czy_pierwsza(int n)`           | funkcje pomocnicze w zadaniach |

### Jak zapisać zmienną

```cpp
int liczba = 80;        // liczba całkowita
double kat = 1.57;      // liczba z częścią ułamkową (większa dokładność)
float x = 3.14f;        // liczba z ułamkiem (mniejsza dokładność — zad. 10)
bool tak = true;        // prawda (true) lub fałsz (false)
long long duza = 1838947883LL;  // bardzo duża liczba całkowita (zad. 16)
```

- **Zapisanie zmiennej** — mówisz komputerowi, *jakiego typu* jest zmienna: `int a;`
- **Przypisanie** — wkładasz wartość: `a = 5;` lub od razu: `int a = 5;`


### `long long` i sufiks `LL` (zad. 16, 17)

Zwykły `int` ma ograniczony zakres. Dla bardzo dużych liczb całkowitych używamy:

```cpp
long long n = 1838947883LL;   // LL na końcu — bardzo duża liczba
```

Przy mnożeniu dużych liczb (zad. 17) czasem liczymy na `long long`, żeby wynik się zmieścił. W zad. 17 możesz też potrzebować `#include <climits>` i stałej `INT_MAX` (ok. 2 147 483 647).

### Zmienna, stała i tablica — czym się różnią?

| Pojęcie     | Prosta metafora          | W kodzie                          | Ile wartości?        | Czy można zmieniać później?                     |
| ----------- | ------------------------ | --------------------------------- | -------------------- | ----------------------------------------------- |
| **Zmienna** | jedno pudełko z etykietą | `int n = 5;`                      | **jedna**            | **tak** — `n = 10;`                             |
| **Stała**   | pudełko z kłódką         | `const int liczba = 80;`          | **jedna**            | **nie** — wartość ustalona na stałe             |
| **Tablica** | szafa wielu szuflad      | `std::vector<int> suma(1000, 0);` | **wiele** (np. 1000) | **tak** — każda szuflada osobno: `suma[3] = 7;` |

#### Zmienna — jedna wartość, można podmieniać

```cpp
int n;
n = 100;      // OK — w pudełku n jest teraz 100
n = 999;      // OK — zmieniliśmy zawartość
```

Używasz przy: liczbie od użytkownika, liczniku w pętli, wyniku `d1`, `d2` w grze (zad. 12).

#### Stała (`const`) — jedna wartość, **bez** podmiany

```cpp
const int liczba = 80;
liczba = 90;   // BŁĄD — nie wolno zmieniać stałej
```

Po co? Żeby **nie zmienić przypadkiem** ważnej liczby z zadania (np. zawsze dzielimy 80, limit miliona w zad. 19).

`const` = **const**ant = stała.

#### Tablica — wiele wartości pod numerami 0, 1, 2, …

W naszych zadaniach tablica to najczęściej **`std::vector`** (zad. 19):

```cpp
std::vector<int> suma(1000000, 0);   // milion „szuflad”, na start 0
suma[220] = 284;                      // w szufladzie nr 220 leży 284
int b = suma[a];                      // odczyt ze szuflady nr a
```

- **`suma`** — cała tablica (cała szafa).
- **`suma[220]`** — **jedna** komórka o numerze 220 (jedna szuflada).
- Numer w `[ ]` nazywa się **numerem w tablicy**.

Tablica **nie zastępuje** zwykłej zmiennej — używasz jej, gdy potrzebujesz **wiele** liczb tego samego typu naraz (tu: suma dzielników dla każdej liczby od 2 do 999999).

#### Porównanie w jednym zdaniu

- **Zmienna** — jedno pudełko, wartość może się zmieniać.
- **Stała** — jedno pudełko z napisem „nie ruszać”.
- **Tablica** — wiele pudełek w rzędzie, każde ma swój numer `[i]`.

#### Przykład z zad. 19 — wszystkie trzy naraz

```cpp
const int limit = 1000000;              // stała — rozmiar, nie zmieniamy
std::vector<int> suma(limit, 0);          // tablica — milion wartości
int a = 2;                                // zmienna — idzie po kolei w pętli
suma[a] = suma_dzielnikow_wlasciwych(a);  // zapis do tablicy pod numerem a
```

Więcej o `vector`: [§13](#13-vector--elastyczna-tablica-zad-19).

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ (zadania szkolne: int, double, bool, const, long long, vector). Wyjaśnij po polsku prostymi słowami: kiedy wybrać int a kiedy long long, czym różni się double od float, po co const i co się stanie przy błędnej zmianie stałej. Podaj tabelę z przykładowymi liczbami, które się nie mieszczą w int, oraz 3 typowe błędy ucznia przy typach. Bez wchodzenia w wskaźniki.
```

---

## 7. Wypisywanie na ekran i wczytywanie z klawiatury

W C++ tekst i liczby **wypisujemy na ekran** przez **`std::cout`**.  
(W potocznym mówieniu można to nazwać „printem”, ale w kodzie używa się właśnie `cout`.)

Na górze pliku musi być:

```cpp
#include <iostream>
```

Bez tego program nie zna `cout` ani `cin`.

### Wypisywanie na ekran (`std::cout`)

**`cout`** = **cout** — skrót od wypisywania; wysyłanie tekstu i liczb **na ekran**.

**Jak to działa:** kolejne fragmenty **łączysz** znakiem **`<<`** („wyślij do ekranu”):

```cpp
std::cout << "Cześć";           // sam tekst
std::cout << n;                 // wartość zmiennej n (liczba)
std::cout << "Wynik: " << n;    // tekst i liczba w jednej linii poleceń
```

Każde `<<` dokleja kolejną rzecz do tego, co leci na ekran — jak sklejanie kawałków od lewej do prawej.

| Co wypisujesz        | Przykład                                | Uwaga                                |
| -------------------- | --------------------------------------- | ------------------------------------ |
| tekst                | `std::cout << "Witaj!";`                | tekst w **cudzysłowie** `" "`        |
| liczba               | `std::cout << n;`                       | bez cudzysłowów — to zmienna         |
| tekst + liczba       | `std::cout << "a=" << a << " b=" << b;` | tyle `<<`, ile fragmentów            |
| spacja               | `std::cout << ' ';`                     | jeden znak w **apostrofach** `' '`   |
| nowa linia           | `std::cout << '\n';`                    | przejście do następnej linii         |
| nowa linia (inaczej) | `std::cout << std::endl;`               | to samo co `\n` + opróżnienie bufora |

Przykłady z zadań:

```cpp
std::cout << "Dzielniki liczby 80:\n";   // komunikat + nowa linia
std::cout << i << ' ';                    // liczba i spacja (w jednej linii wiele liczb)
std::cout << "Wynik: " << n << '\n';     // podpis, liczba, koniec linii
std::cout << "(" << a << ", " << b << ")\n";   // nawiasy to zwykły tekst w cudzysłowie
```

**Kolejność ma znaczenie** — program wypisuje dokładnie w takiej kolejności, w jakiej stoją `<<`:

```cpp
std::cout << "Suma: " << a + b << '\n';   // najpierw tekst, potem wynik dodawania
```

`std::` przed `cout` — patrz [§4](#4-dlaczego-jest-std-przed-cout-i-cin) (gotowa biblioteka C++).

---

### Wczytywanie z klawiatury (`std::cin`)

**`cin`** = **c**haracter **in**put (znaki **z wejścia**, czyli z klawiatury).  
Znak **`>>`** czytamy: „wczytaj z klawiatury do zmiennej”.

**Krok po kroku:**

1. Program **wypisuje** prośbę (żeby użytkownik wiedział, co wpisać).
2. Użytkownik **pisze** wartość i naciska **Enter**.
3. Program **wczytuje** wartość do zmiennej (`cin >> zmienna`).

```cpp
int n;
std::cout << "Podaj liczbe calkowita: ";   // 1. komunikat
std::cin >> n;                              // 2. i 3. — czeka na Enter

std::cout << "Podales: " << n << '\n';      // potwierdzenie
```

### Tabela: `cout` vs `cin`

|               | `std::cout` (wypisz)            | `std::cin` (wczytaj)               |
| ------------- | ------------------------------- | ---------------------------------- |
| Kierunek      | program → **ekran**             | **klawiatura** → program           |
| Znak          | `<<`                            | `>>`                               |
| Typowe użycie | `std::cout << tekst << liczba;` | `std::cin >> liczba;`              |
| Po `cin`      | —                               | użytkownik musi nacisnąć **Enter** |

### Wczytywanie różnych typów

Zmienna musi **pasować** do tego, co użytkownik wpisze:

| Typ zmiennej | Przykład wczytania | Co użytkownik wpisuje        |
| ------------ | ------------------ | ---------------------------- |
| `int`        | `std::cin >> n;`   | np. `500`                    |
| `double`     | `std::cin >> a;`   | np. `1.57`                   |
| `float`      | `std::cin >> x;`   | np. `3.14`                   |
| `char`       | `std::cin >> odp;` | jeden znak, np. `t` (zad. 7) |

### Dwa razy z klawiatury (np. zad. 5, 12)

```cpp
int a, b;
std::cout << "Podaj dwie liczby: ";
std::cin >> a >> b;    // najpierw a, potem b (spacja lub Enter między nimi)
```

albo osobno:

```cpp
std::cout << "Pierwsza liczba: ";
std::cin >> a;
std::cout << "Druga liczba: ";
std::cin >> b;
```

### Pełny minimalny program

```cpp
#include <iostream>

int main() {
    int wiek;
    std::cout << "Ile masz lat? ";
    std::cin >> wiek;
    std::cout << "Masz " << wiek << " lat.\n";
    return 0;
}
```

### Częste pytania

| Pytanie                        | Odpowiedź                                                                     |
| ------------------------------ | ----------------------------------------------------------------------------- |
| Jak coś wypisać na ekran?      | `std::cout << …` z `#include <iostream>`                                      |
| Program „stoi” i nic nie robi? | Często **czeka na `cin`** — wpisz liczbę i Enter                              |
| `cin` nie działa               | Sprawdź `#include <iostream>` i czy zmienna ma dobry typ (`int` vs `double`)  |
| Tekst i liczba w jednej linii  | `std::cout << "Wynik: " << n << '\n';` — łączysz `<<` tyle razy, ile potrzeba |

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i używam std::cout z << oraz std::cin z >>. Wyjaśnij po polsku: dlaczego << to „do ekranu”, a >> „z klawiatury”, co robi '\n' i endl, oraz dlaczego program czasem „stoi” czekając na cin. Podaj 3 przykłady błędów (zły typ, brak spacji w tekście, podwójne wczytanie) i jak je naprawić. Na końcu krótki program: pytanie o wiek i odpowiedź jednym zdaniem.
```

---

## 8. Wyrażenia: znaki porównania, `&&`, `%`, `=` vs `==`

Znaki porównania dają **`true`** lub **`false`** — idealne do `if`.

### Tabela: `<`, `>`, `<=`, `>=`, `==`, `!=`

| Znak | Co znaczy              | Pytanie, na które odpowiada           | Przykład     | Wynik dla przykładu                   |
| ---- | ---------------------- | ------------------------------------- | ------------ | ------------------------------------- |
| `<`  | mniejsze               | Czy lewa jest **mniejsza** od prawej? | `5 < 10`     | `true`                                |
| `>`  | większe                | Czy lewa jest **większa** od prawej?  | `d1 > d2`    | zależy od liczb graczy                |
| `<=` | mniejsze lub równe     | Czy lewa ≤ prawa?                     | `n <= 999`   | `true` dla trzycyfrowych w pętli      |
| `>=` | większe lub równe      | Czy lewa ≥ prawa?                     | `p >= dolna` | zad. 7 — pierwiastek w przedziale     |
| `==` | **równe** (porównanie) | Czy lewa **równa się** prawej?        | `n % d == 0` | `true`, gdy dzieli się bez reszty     |
| `!=` | różne                  | Czy lewa **nie równa się** prawej?    | `drugi != d` | zad. 19 — unikamy podwójnego liczenia |

**Uwaga na granicę:** `5 < 10` to prawda, ale `10 < 10` to fałsz (bo nie jest *mniejsze*, tylko równe).  
Gdy chcesz „mniejsze **albo** równe”, użyj `<=`, np. `n <= 80`.

### Tabela: `=` vs `==` — najczęstsza pomyłka

| Zapis | Rodzaj          | Co robi                                                              | Gdzie używać                          |
| ----- | --------------- | -------------------------------------------------------------------- | ------------------------------------- |
| `=`   | **przypisanie** | Wkłada wartość z prawej **do** lewej zmiennej                        | `n = 5;`, `max_pierwsza = n;`         |
| `==`  | **porównanie**  | Sprawdza, czy lewa i prawa strona są **równe**; wynik `true`/`false` | `if (n == 0)`, `if (liczba % i == 0)` |

```cpp
int a = 10;        // =  — ustawiamy a na 10
if (a == 10) { }   // == — pytamy: czy a równa się 10? (tak → wejdź w if)

if (n % d = 0)     // BŁĄD — tu potrzebne ==, nie =
if (n % d == 0)    // OK
```

| Sytuacja                             | Poprawny zapis    |
| ------------------------------------ | ----------------- |
| „Niech `n` będzie równe 100”         | `n = 100;`        |
| „Jeśli `n` jest równe 100”           | `if (n == 100)`   |
| „Jeśli reszta z dzielenia jest zero” | `if (n % d == 0)` |

### Łączenie dwóch warunków naraz

| Znak | Znaczenie | Przykład |
| ---- | --------- | -------- |
| `&&` | **i** — oba warunki muszą być prawdziwe | `n % 3 == 0 && n % 17 == 0` |
| `\|\|` | **lub** — wystarczy jeden prawdziwy | rzadziej w naszych zadaniach |

Przypomnienie: w `if` używamy **`==`** do porównania, **`=`** tylko do przypisania wartości.

### Reszta z dzielenia `%`

```cpp
80 % 5 == 0    // prawda — 80 dzieli się przez 5 bez reszty
7 % 3 == 1     // reszta z dzielenia 7 przez 3 to 1
```

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i mylę czasem = z == oraz używam <, >, <=, >=, !=, && i %. Wyjaśnij po polsku z przykładami liczbowymi: różnica przypisania i porównania, jak działa reszta % przy sprawdzaniu dzielników (np. 80 i 5), oraz kiedy użyć && a kiedy ||. Daj 5 mini-zadań „prawda czy fałsz?” z rozwiązaniami, żebym przećwiczyła przed if.
```

---

## 9. Instrukcja `if` — „jeśli… to…”

`if` pozwala **wykonać fragment kodu tylko wtedy**, gdy coś jest spełnione — jak w życiu: *jeśli pada deszcz, weź parasol*.

### Najprostszy schemat

```cpp
if (warunek) {
    // kod A — wykona się TYLKO gdy warunek jest prawdziwy (true)
}
// kod B — wykona się ZAWSZE (po sprawdzeniu if)
```

**Jak to przebiega krok po kroku:**

1. Komputer **oblicza warunek** w nawiasie po `if`.
2. Jeśli wynik to **prawda** (`true`) → wchodzi do `{ }` i robi **kod A**.
3. Jeśli wynik to **fałsz** (`false`) → **pomija** kod A.
4. Potem i tak idzie dalej — wykonuje **kod B**.

```
        warunek?
       /        \
     TAK         NIE
|     |
| --- |
|     |
   kod A      (pomiń A)
      \         /
       ----+----
|     |
| --- |
|     |
         kod B
```

### `if` z `else` — „w przeciwnym razie”

```cpp
if (warunek) {
    // gdy prawda
} else {
    // gdy fałsz — dokładnie jedna z tych dwóch gałęzi
}
```

Wykonuje się **albo** pierwszy blok, **albo** drugi — nigdy oba naraz.

### Przykład z zadania 1 (dzielniki)

```cpp
if (liczba % i == 0) {
    std::cout << i << ' ';
}
```

| Co sprawdzamy | Znaczenie                                            |
| ------------- | ---------------------------------------------------- |
| `liczba % i`  | reszta z dzielenia `liczba` przez `i`                |
| `== 0`        | czy reszta jest równa zero (= dzieli się bez reszty) |

Gdy `80 % 5 == 0` → prawda → wypisujemy `5`.  
Gdy `80 % 6 != 0` → fałsz → nic nie wypisujemy i idziemy dalej w pętli.

Warunek musi być **prawdą lub fałszem**. Znaki porównania: [§8](#8-wyrażenia-znaki-porównania-łączenie-warunków-=-vs-).

### Jedna linia bez `{ }`

Gdy pod `if` jest **tylko jedna** instrukcja, nawiasy klamrowe można pominąć:

```cpp
if (n < 2)
    return false;   // tylko ta linia zależy od if

if (liczba % i == 0)
    std::cout << i << ' ';
```

Jeśli pod `if` ma być **więcej linii**, **muszą** być `{ }`:

```cpp
if (czy_pierwsza(n)) {
    min_pierwsza = n;
    max_pierwsza = n;
}
```

### `else if` — wiele możliwości (zad. 12)

Sprawdzamy kolejno **pierwszy pasujący** warunek:

```cpp
if (d1 > d2)
    std::cout << "Wygrywa gracz 1!\n";
else if (d2 > d1)
    std::cout << "Wygrywa gracz 2!\n";
else
    std::cout << "Remis!\n";
```

| Sytuacja                          | Co się wykona        |
| --------------------------------- | -------------------- |
| `d1 > d2`                         | komunikat o graczu 1 |
| w przeciwnym razie, gdy `d2 > d1` | komunikat o graczu 2 |
| gdy żadne z powyższych (remis)    | `else` na końcu      |

### `if` z funkcją zwracającą `bool` (zad. 4, 5)

```cpp
if (podzielna_przez_3_i_17(liczba))
    std::cout << "Dzieli sie przez 3 i 17.\n";
else
    std::cout << "Nie dzieli sie.\n";
```

Funkcja `podzielna_przez_3_i_17` zwraca `true` lub `false` — `if` używa tego wyniku jak zwykłego warunku.

### Zagnieżdżone `if` (if w środku if)

```cpp
if (czy_pierwsza(n)) {
    if (min_pierwsza == -1)
        min_pierwsza = n;
}
```

Najpierw sprawdzamy pierwszość; dopiero gdy liczba pierwsza, wchodzimy w drugi `if`.

### Częsty błąd: `=` zamiast `==`

| Zapis    | Co robi             | W `if`?                                |
| -------- | ------------------- | -------------------------------------- |
| `a == b` | czy **równa się**?  | tak — porównanie                       |
| `a = b`  | **przypisz** b do a | źle w warunku (nie pytamy „czy równe”) |

Poprawnie: `if (n % d == 0)`  
Źle: `if (n % d = 0)` — program nie skompiluje się.

### Skrót: kiedy używać czego

| Potrzebujesz                                     | Jak zapisać w kodzie      |
| ------------------------------------------------ | ------------------------- |
| zrób coś tylko gdy…                              | `if (warunek) { }`        |
| zrób A albo B                                    | `if (…) { A } else { B }` |
| kilka przypadków                                 | `if` … `else if` … `else` |
| warunek z dwoma częściami (np. przez 3 **i** 17) | `if (a && b)` — [§8](#8-wyrażenia-znaki-porównania-łączenie-warunków-=-vs-)        |

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i używam if, else, else if oraz zagnieżdżonych warunków (np. dzielniki, porównanie kostek). Wyjaśnij po polsku krok po kroku: jak komputer wykonuje if z diagramem w słowach, kiedy potrzebne są nawiasy { }, oraz dlaczego if (n % d = 0) to błąd. Podaj jeden przykład z dzielnikami i jeden z else if (remis) z tabelą: warunek → co się wypisze.
```

---

## 10. Pętle: `for` i `while`

```cpp
for (int i = 1; i <= 80; ++i) {
    // ten blok wykona się dla i = 1, 2, 3, …, 80
}
```

Trzy części w nawiasie (oddzielone średnikami):

```cpp
for (start; warunek; krok) {
    // tu powtarzany kod
}
```

- **start** — np. `int i = 1` (zmienna tylko w pętli).
- **warunek** — dopóki prawdziwy, pętla działa (`i <= 80`).
- **krok** — co się dzieje po każdym obrocie (`++i` = zwiększ i o 1).

Inne przykłady z zadań:

```cpp
for (int n = 100; n <= 999; ++n)     // wszystkie liczby 3-cyfrowe
for (int d = 2; d < n; ++d)          // dzielniki od 2 do n-1
for (int k = 1; ; ++k)               // nieskończona — wyjdziemy przez break
```

### Co znaczy `++n` (i `++i`, `++ile`, `++k`)?

**`++n`** to skrót od: **„zwiększ n o 1”**.

| Zapis | To samo co      | Przykład: n było 5, potem…  |
| ----- | --------------- | --------------------------- |
| `++n` | `n = n + 1`     | n jest **6**                |
| `n++` | też `n = n + 1` | n jest **6** (u nas rzadko) |

Litera po `++` to po prostu **nazwa zmiennej** — może być `i`, `n`, `d`, `k`, `ile`:

```cpp
for (int n = 100; n <= 999; ++n)   // po każdym obrocie n rośnie o 1: 100, 101, 102…
++ile;                             // licznik dzielników — dodaj 1 do ile
++k;                               // w zad. 14 — następny kandydat k=2, 3, …
```

**Gdzie to widać w pętli `for`:**

```cpp
for (int n = 100; n <= 999; ++n) {
//                        ^^^^
//                        krok pętli — wykonuje się PO każdym obrocie ciała
}
```

1. Sprawdź warunek (`n <= 999`).
2. Wykonaj ciało pętli.
3. Wykonaj `++n` — n zwiększa się o 1.
4. Wróć do punktu 1.

**`++n` (przed zmienną)** vs **`n++` (po zmiennej):**  
W pętlach `for` i w naszych zadaniach używamy **`++n`** — efekt końcowy jest taki sam jak `n = n + 1`.  
Różnica `++n` / `n++` ma znaczenie głównie w złożonych wyrażeniach — na start wystarczy pamiętać: **`++` = plus jeden**.

Powiązane: `n--` lub `--n` to **zmniejszenie o 1** (w naszych plikach rzadko).

---

### Pętla `while` — „dopóki warunek”

W zad. 14 używamy `while (true)` i w środku `break`, gdy znajdziemy wynik:

```cpp
while (true) {
    // ...
    if (ok) {
        break;    // wyjście z pętli
    }
}
```

`while (warunek)` — powtarzaj, dopóki warunek prawdziwy.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i używam pętli for (start; warunek; krok) oraz czasem while z break. Wyjaśnij po polsku: co dokładnie robią trzy części w nawiasie for na przykładzie i od 1 do 5, czym jest ++i, kiedy pętla się nie wykona ani razu, oraz różnica for vs while na prostym przykładzie. Narysuj w tekście tabelę wartości i dla i=1..4. Bez zaawansowanych trików.
```

---

## 11. Własne funkcje i `bool`

Zamiast pisać ten sam kod wiele razy, **nazywamy go** i wołamy:

```cpp
bool czy_pierwsza(int n) {
    if (n < 2)
        return false;
  // ...
    return true;
}

int main() {
    if (czy_pierwsza(101))
        std::cout << "101 jest pierwsza\n";
}
```

| Część           | Znaczenie                                    |
| --------------- | -------------------------------------------- |
| `bool`          | funkcja oddaje prawdę lub fałsz              |
| `czy_pierwsza`  | nazwa funkcji                                |
| `(int n)`       | liczba, którą podajesz do funkcji w nawiasie |
| `return false;` | kończy funkcję i oddaje wynik (tu: fałsz)    |

Inne typy zwracane w zadaniach:

- `int` — np. `liczba_dzielnikow_wlasciwych`, `suma_dzielnikow_wlasciwych`
- `long long` — bardzo duże liczby (zad. 16, `sprawdz`)
- `void` — funkcja nic nie zwraca (u nas rzadko; np. `wypisz_blizniacze` może być `void`)

**Wywołanie:** `czy_pierwsza(17)` — wykonuje kod funkcji dla liczby 17.

---

### Typ `bool` — prawda i fałsz

Typ `bool` ma tylko dwie wartości: `true` lub `false`.

```cpp
bool podzielna_przez_3_i_17(int liczba) {
    return liczba % 3 == 0 && liczba % 17 == 0;
}
```

Funkcja z zad. 5:

```cpp
bool suma_jest_pierwsza(int a, int b) {
    return czy_pierwsza(a + b);
}
```

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i piszę własne funkcje, np. bool czy_pierwsza(int n) z return true/false. Wyjaśnij po polsku prostymi słowami: czym jest parametr, czym jest return, jak wywołanie czy_pierwsza(17) „wchodzi” do funkcji i wraca wynikiem do if. Porównaj funkcję zwracającą int, bool i void na jednym mini-programie. Podaj 2 błędy ucznia (brak return, zła kolejność definicji).
```

---

## 12. Biblioteka `cmath` (zad. 6, 7, 10)

Po `#include <cmath>` możesz używać:

| Funkcja    | Co robi                                         |
| ---------- | ----------------------------------------------- |
| `sin(a)`   | sinus kąta `a` (**w radianach**, nie stopniach) |
| `cos(a)`   | cosinus                                         |
| `sqrt(n)`  | pierwiastek kwadratowy                          |
| `ceil(x)`  | zaokrąglenie w górę (sufit)                     |
| `floor(x)` | zaokrąglenie w dół (podłoga)                    |

Stopnie na radiany: `radiany = stopnie * 3.14159265 / 180`

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i używam #include <cmath>: sin, cos, sqrt, ceil, floor. Wyjaśnij po polsku: dlaczego sin i cos biorą radiany (nie stopnie), jak przeliczyć 90° na radiany krok po kroku, oraz czym różni się ceil od floor na przykładach 3.2 i -3.2. Podaj krótki przykład: wczytaj kąt w stopniach, policz sinus i wypisz wynik — z komentarzem do każdej linii.
```

---

## 13. `vector` — „elastyczna tablica” (zad. 19)

```cpp
#include <vector>

std::vector<int> suma(1000000, 0);   // milion elementów, na start 0
suma[n] = 42;                         // zapis pod numerem n
int b = suma[a];                      // odczyt
```

Myśl o tym jak o szeregu pudełek numerowanych od 0: `suma[0]`, `suma[1]`, …  
W zad. 19 pod numerem `n` trzymamy sumę dzielników właściwych liczby `n`.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i w zadaniu 19 używam std::vector<int> suma(1000000, 0) oraz suma[n]. Wyjaśnij po polsku metaforą „szuflad”: czym vector różni się od jednej zmiennej int, co znaczy drugi argument 0 przy tworzeniu, dlaczego numeracja od 0, oraz co się stanie przy suma[1000000]. Porównaj krótko tablicę C++ vector z „wieloma pudełkami” bez wskaźników.
```

---

## 14. Nawiasy `( )`, `[ ]`, `{ }`, `< >`

### Nawiasy okrągłe `( )` a kwadratowe `[ ]`

W C++ **to nie to samo** — mylą się na początku, bo wyglądają podobnie.

| Nawias | Nazwa      | Do czego w naszych zadaniach                 | Przykład                                    |
| ------ | ---------- | -------------------------------------------- | ------------------------------------------- |
| `( )`  | okrągłe    | **wywołanie funkcji**, liczenie w grupie     | `sqrt(n)`, `czy_pierwsza(17)`, `if (n < 2)` |
| `[ ]`  | kwadratowe | **element tablicy / vectora** (który numer?) | `suma[n]`, `suma[a]` w zad. 19              |

#### `( )` — okrągłe

1. **Wywołanie funkcji** — „zrób to dla tej wartości”:

```cpp
czy_pierwsza(n)      // wywołaj funkcję z argumentem n
sqrt(n)              // pierwiastek z n
suma_dzielnikow_wlasciwych(28)
```

2. **Grupowanie w warunkach** (kolejność liczenia):

```cpp
if ((a > b) && (b < limit))   // nawiasy pomagają czytać warunek
```

3. **Para liczb na ekranie** — tylko tekst do wypisania, nie tablica:

```cpp
std::cout << "(" << a << ", " << b << ")\n";   // wypisze np. (220, 284)
```

Tu `(` i `)` to **zwykłe znaki** w cudzysłowie — jak nawiasy w matematyce na wydruku.

#### `[ ]` — kwadratowe

**Numer w tablicy** — „weź element o tym numerze” (numeracja od 0 w `vector`):

```cpp
std::vector<int> suma(1000000, 0);
suma[n] = 42;        // zapis do pola nr n
int b = suma[a];     // odczyt pola nr a
```

- `suma` — cała tablica (szafa z szufladami).
- `suma[5]` — **piąta szuflada** (dokładniej: element pod numerem 5).

**Nie** używamy `[ ]` do wywoływania funkcji — do tego są `( )`.

#### Uwaga: `[5; 6)` w treści zadania 7

W README jest zapis **`[5; 6)`** — to **matematyczny przedział** (od 5 włącznie do 6 bez 6), **nie kod C++**.

W programie piszesz np. `dolna`, `gorna` i `if` — a nie dosłownie `[5;6)` w pliku `.cpp`.

#### Inne nawiasy (na marginesie)

| Zapis | Gdzie                    | Znaczenie                          |
| ----- | ------------------------ | ---------------------------------- |
| `{ }` | przy `if`, `for`, `main` | blok kodu — kilka instrukcji razem |
| `< >` | `#include <iostream>`    | nazwa gotowej biblioteki C++       |

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ i mylę nawiasy ( ) [ ] { } < >. Wyjaśnij po polsku z przykładami z dzielników i vectora: kiedy ( ) to wywołanie funkcji, kiedy [ ] to element tablicy, kiedy { } to blok kodu, a kiedy < > w #include. Podaj 5 linii kodu i poproś mnie mentalnie „co tu oznacza każdy nawias” — z odpowiedziami. Wyjaśnij też, że [5;6) w treści zadania to matematyka, nie C++.
```

---

## 15. Jak czytać pliki zadań — kolejność nauki

1. Przeczytaj **treść zadania** w komentarzu u góry pliku.
2. Zobacz `#include` — jakie biblioteki są potrzebne.
3. Przeczytaj **funkcje pomocnicze** (np. `czy_pierwsza`) — często to serce programu.
4. Przejdź **`main()`** linia po linii.
5. Na końcu pliku przeczytaj blok **„JAK TO DZIAŁA?”**.

Propozycja trudności:

| Poziom       | Zadania          | Nowe pojęcia                                |
| ------------ | ---------------- | ------------------------------------------- |
| Start        | 1, 6, 10         | `main`, `for`, `if`, `cout`, `cin`, `cmath` |
| Średni       | 2, 3, 5, 8, 11   | własne funkcje, `bool`                      |
| Dalej        | 4, 7, 12, 14, 15 | `&&`, przedziały, `else if`                 |
| Zaawansowane | 16–19            | `long long`, `vector`, większe pętle        |

Zadanie **9** to arkusz kalkulacyjny — instrukcja w [9.md](9.md), nie w C++.

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ z plików zadań 1–19 (komentarz u góry, #include, funkcje pomocnicze, main, blok „JAK TO DZIAŁA?” na końcu). Wyjaśnij po polsku strategię czytania cudzego kodu linia po linii: od czego zacząć, jak notować pytania, jak sprawdzić zrozumienie bez kopiowania. Zaproponuj plan nauki na 2 tygodnie dla poziomu start (zad. 1,6,10) → średni → zaawansowany. Krótko, konkretnie.
```

---

## 16. Słowniczek na szybko

| Słowo                          | Krótko                                                |
| ------------------------------ | ----------------------------------------------------- |
| kompilacja                     | zamiana `.cpp` na program do uruchomienia             |
| `main`                         | funkcja startowa                                      |
| `return`                       | zwróć wynik z funkcji / zakończ `main`                |
| liczba w nawiasie przy funkcji | np. w `czy_pierwsza(17)` — podajesz 17 do sprawdzenia |
| pętla                          | powtarzanie kodu (`for`, `while`)                     |
| dzielnik                       | liczba, przez którą dzielimy bez reszty               |
| liczba pierwsza                | dzieli się tylko przez 1 i przez siebie               |
| liczba złożona                 | ma więcej dzielników niż 1 i ona sama                 |

### CHCESZ WIEDZIEĆ WIĘCEJ?

Skopiuj poniższy prompt do darmowego ChatGPT (chat.openai.com), żeby pogłębić zrozumienie tego rozdziału:

```
Uczę się C++ od zera i znam już słowniczek: kompilacja, main, return, pętla, dzielnik, liczba pierwsza/złożona. Wyjaśnij po polsku każde z tych pojęć jednym zdaniem i jednym przykładem liczbowym lub linią kodu. Na końcu zadaj mi 5 pytań sprawdzających (jak quiz) i podaj odpowiedzi — żebym wiedziała, czego jeszcze nie rozumiem.
```

