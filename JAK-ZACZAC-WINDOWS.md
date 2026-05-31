# Jak zacząć z C++ na Windows

Krótki przewodnik dla ucznia: **bez instalacji** (online), **programy na komputerze** albo **konfiguracja VS Code + `g++`** — tak jak w [Poradniku](PORADNIK.md).

---

<a id="online-za-darmo"></a>

## Kompiluj online za darmo (bez instalacji)

> **Kiedy to się opłaca:** nie możesz teraz nic instalować; chcesz szybko sprawdzić fragment kodu; pracujesz na cudzym komputerze.
>
> **Jak używać (3 kroki):**
> 1. Otwórz jeden z linków poniżej.
> 2. Wklej kod z pliku `.cpp` (np. `0.cpp` lub `1.cpp` z tego folderu).
> 3. Kliknij **Uruchom** / **Run** — wynik zobaczysz w panelu wyjścia. Gdy program używa `cin`, wpisz dane w polu **Wejście** (jeśli serwis je ma).
>
> **Ograniczenia:** zwykle działasz na **jednym pliku** naraz — niewygodnie dla całego folderu zadań `1.cpp`…`19.cpp`. To inne środowisko niż `g++` w szkole. Do nauki kompilacji i oddawania pracy **docelowo** lepiej program na komputerze — [sekcja poniżej](#vscode-msys2).
>
> **Wszystkie serwisy poniżej są darmowe** w podstawowym użyciu (bez płatnej subskrypcji na start).

| Serwis              | Link                                                              | Uwaga                                                           |
|---------------------|-------------------------------------------------------------------|-----------------------------------------------------------------|
| **myCompiler** (PL) | https://www.mycompiler.io/pl/new/cpp                              | Interfejs po polsku; nowy projekt C++ od razu                   |
| **OnlineGDB**       | https://www.onlinegdb.com/online_c++_compiler                     | Popularny; Run + wejście z klawiatury                           |
| **Programiz**       | https://www.programiz.com/cpp-programming/online-compiler/        | Prosty edytor, jeden plik                                       |
| **Replit**          | https://replit.com/languages/cpp                                  | Do zapisu projektu trzeba konta; dobry do dłuższej pracy online |
| **W3Schools Tryit** | https://www.w3schools.com/cpp/trycpp.asp?filename=demo_helloworld | Bardzo prosty; na krótkie przykłady                             |

**Przykład:** skopiuj treść `1.cpp` → wklej w [myCompiler](https://www.mycompiler.io/pl/new/cpp) → **Uruchom**.

---

<a id="inne-programy"></a>

## Programy na komputerze (Windows)

Na Windows **nie ma jednego „oficjalnego” programu do C++** jak czasem na Macu w sali — wybierasz narzędzie. Do ćwiczeń z tego repozytorium najlepiej coś z komendą **`g++` w terminalu** (jak w [Poradniku](PORADNIK.md), §1).

**To nie jedyny sposób** — jeśli szkoła wymaga konkretnego programu, zapytaj nauczyciela. Poniżej skrót opcji.

| Program                      | Co to jest                       | Kompilator             | Pasuje do tego repo?             | Uwagi                                                                     |
|------------------------------|----------------------------------|------------------------|----------------------------------|---------------------------------------------------------------------------|
| **VS Code + MSYS2 (MinGW)**  | Lekki edytor + osobno `g++`      | `g++` (GCC)            | **Tak — rekomendowane**          | Te same komendy co w poradniku; [instrukcja krok po kroku](#vscode-msys2) |
| **Visual Studio Community**  | Duży program od Microsoftu (IDE) | `cl` (MSVC), nie `g++` | **Raczej nie** na start          | Wygodny na Windows, ale inne komendy kompilacji                           |
| **Code::Blocks**             | Program z przyciskiem Kompiluj   | często MinGW → `g++`   | **Tak**, jeśli szkoła tego używa | Często w szkołach; możesz też wpisać `g++ …` w terminalu                  |
| **Dev-C++**                  | Starszy, prosty edytor           | `g++`                  | **Częściowo**                    | Prostszy UI, ale przestarzały — lepiej VS Code lub Code::Blocks           |
| **CLion**                    | Profesjonalne IDE (JetBrains)    | GCC/Clang/MSVC         | Tak, ale **overkill**            | Dla uczniów bywa darmowy z licencją; ciężka instalacja                    |
| **WSL2 (Linux w Windowsie)** | Ubuntu w terminalu               | `g++` przez `apt`      | **Tak** (jak Linux)              | `./zad1` jak w poradniku; instalacja trudniejsza                          |
| **Kompilator online**        | Przeglądarka                     | serwis w chmurze       | **Na próbę**                     | → [online za darmo](#online-za-darmo)                                     |

**Linki do pobrania (programy na PC):**

- Visual Studio Community: https://visualstudio.microsoft.com/vs/community/
- Code::Blocks: https://www.codeblocks.org/downloads/
- Dev-C++ (starsze narzędzie): https://sourceforge.net/projects/orwelldevcpp/
- CLion: https://www.jetbrains.com/clion/
- WSL (Windows Subsystem for Linux): https://learn.microsoft.com/pl-pl/windows/wsl/install

Jeśli masz **Code::Blocks** z MinGW, w folderze zadań możesz też otworzyć terminal i wpisać `g++ -std=c++17 -Wall 1.cpp -o zad1.exe` — tak jak w poradniku.

---

<a id="vscode-msys2"></a>

## Opcja rekomendowana: VS Code + g++

To **jedna z opcji** z tabeli powyżej. Wybraliśmy ją, bo pasuje do komend z [Poradnika](PORADNIK.md): `g++ -std=c++17 -Wall` i plików `.cpp` z tego folderu.

Poniżej **uproszczone tłumaczenie** oficjalnej instrukcji Microsoftu:

**Źródło (po angielsku, bardzo szczegółowe):** [Using GCC with MinGW — Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-mingw)

**Film ze strony Microsoftu** (instalacja MinGW pod Windows):

[![Installing MinGW to build C++ code on Windows](https://img.youtube.com/vi/oC69vlWofJQ/0.jpg)](https://www.youtube.com/watch?v=oC69vlWofJQ)

Bezpośredni link: https://www.youtube.com/watch?v=oC69vlWofJQ

---

### Krok 1 — Zainstaluj Visual Studio Code

1. Wejdź na https://code.visualstudio.com/
2. Pobierz wersję na **Windows** i zainstaluj (dalej: **Dalej** / **Next**).
3. Uruchom **Visual Studio Code**.

---

### Krok 2 — Rozszerzenie C/C++

1. W VS Code naciśnij `Ctrl+Shift+X` (widok **Rozszerzenia**).
2. Wyszukaj: `C++`.
3. Zainstaluj **C/C++** (wydawca: Microsoft).

---

### Krok 3 — Zainstaluj MSYS2 i kompilator `g++`

MSYS2 to sposób, żeby mieć na Windowsie program **`g++`** (tak jak w szkole na Mac/Linux).

1. Pobierz instalator MSYS2 ze strony https://www.msys2.org/  
   (na stronie VS Code z linku powyżej może być **nowszy** bezpośredni link do instalatora — możesz użyć tego z dokumentacji).
2. Uruchom instalator. Zazwyczaj zostaw folder: `C:\msys64`.
3. Na końcu instalacji zaznacz **Run MSYS2 now** i kliknij **Finish** — otworzy się czarne okno (terminal MSYS2).
4. W tym oknie **wpisz dokładnie** (potem Enter):

```text
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

5. Gdy pyta o liczbę pakietów — naciśnij **Enter** (domyślna opcja).
6. Gdy pyta, czy kontynuować — wpisz **`Y`** i Enter.
7. Poczekaj, aż instalacja się skończy. Możesz zamknąć okno MSYS2.

**Wymagania:** Windows 64-bit (zwykle Windows 10 lub 11).

---

### Krok 4 — Dodaj `g++` do PATH (żeby Windows go „widział”)

1. W pasku wyszukiwania Windows wpisz: **Ustawienia**.
2. Wyszukaj: **Edytuj zmienne środowiskowe dla swojego konta** (lub podobna nazwa).
3. W **Zmiennych użytkownika** wybierz **`Path`** → **Edytuj**.
4. **Nowy** → wpisz ścieżkę (jeśli MSYS2 jest w domyślnym folderze):

```text
C:\msys64\ucrt64\bin
```

5. **OK** → **OK** → zamknij okna ustawień.
6. **Ważne:** zamknij VS Code i otwórz ponownie. Stary terminal może nie widzieć `g++`.

---

### Krok 5 — Sprawdź, czy `g++` działa

1. Otwórz **nowy** terminal: w VS Code `Ctrl+`` ` albo **Wiersz polecenia** z menu Start.
2. Wpisz:

```text
g++ --version
```

3. **Powinno** pokazać wersję kompilatora (kilka linii tekstu).  
   Jeśli widzisz: *„g++” nie jest rozpoznawane…* — wróć do **Kroku 4** (PATH) i upewnij się, że ścieżka to `C:\msys64\ucrt64\bin`.

Opcjonalnie możesz też sprawdzić: `gcc --version` i `gdb --version`.

---

### Krok 6 — Otwórz folder z ćwiczeniami w VS Code

1. Pobierz / sklonuj folder **`cpp_exercises`** (ten z plikami `1.cpp`, `2.cpp`…).
2. W VS Code: **Plik → Otwórz folder…** → wybierz `cpp_exercises`.
3. Jeśli VS Code pyta o **zaufanie do folderu** — możesz wybrać **Tak, ufam autorom** (to Twój folder z zadaniami).

---

### Krok 7 — Pierwsza kompilacja (jak w poradniku)

1. Otwórz plik `1.cpp` w VS Code.
2. Otwórz terminal w VS Code: `` Ctrl+` `` (tylda).
3. Upewnij się, że jesteś w folderze z plikami `.cpp` (ścieżka na górze terminala).
4. Wpisz **dokładnie**:

```powershell
g++ -std=c++17 -Wall 1.cpp -o zad1.exe
.\zad1.exe
```

| Co wpisałeś   | Znaczenie                               |
|---------------|-----------------------------------------|
| `g++`         | program, który tłumaczy kod na program  |
| `-std=c++17`  | wersja C++17 (jak w README i poradniku) |
| `-Wall`       | więcej ostrzeżeń — pomaga łapać błędy   |
| `1.cpp`       | plik z kodem                            |
| `-o zad1.exe` | nazwa programu wykonywalnego na Windows |
| `.\zad1.exe`  | uruchom program z bieżącego folderu     |

To ta sama idea co w [Poradniku](PORADNIK.md) — tylko zamiast `./zad1` na Windows używasz `.\zad1.exe`.

Po zmianie kodu w `1.cpp` **skompiluj ponownie** — inaczej uruchomisz starą wersję programu.

---

### Krok 8 (opcjonalny) — Przycisk Run w VS Code

Zamiast wpisywać komendy możesz kliknąć **▶ Run** w prawym górnym rogu edytora (gdy otwarty jest `.cpp`).

- Przy **pierwszym** uruchomieniu wybierz z listy coś w stylu: **C/C++: g++.exe build and debug active file**.
- Program zbuduje się i uruchomi w terminalu VS Code.

Na start **wystarczy terminal** z Kroku 7 — przycisk Run to dodatek.

---

### Coś nie działa? (krótko)

| Problem                        | Co zrobić                                                                                                  |
|--------------------------------|------------------------------------------------------------------------------------------------------------|
| `g++` nie jest rozpoznawane    | Sprawdź PATH: `C:\msys64\ucrt64\bin`; zamknij i otwórz VS Code                                             |
| Kompilacja OK, ale stary wynik | Po zmianie `.cpp` uruchom `g++ …` jeszcze raz                                                              |
| Błąd debuggera / GDB           | Na start wystarczy kompilacja w terminalu; debugger możesz dodać później (szczegóły na stronie Microsoftu) |
| Inne błędy                     | Pełna instrukcja: https://code.visualstudio.com/docs/cpp/config-mingw                                      |

---

## Co dalej?

- **[Poradnik C++](PORADNIK.md)** — `cout`, `cin`, pętle, funkcje, zadania 1–19.
- **[README](README.md)** — lista zadań i linki do plików `.cpp`.

Jeśli nie możesz nic instalować — wróć do sekcji **[online za darmo](#online-za-darmo)**.
