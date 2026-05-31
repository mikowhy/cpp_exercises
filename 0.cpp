/*
 * Zadanie 0:
 * Napisz program wypisujący na ekran tekst "Hello, World!".
 */

// iostream — wejście/wyjście (cout do wypisywania na ekran)
#include <iostream>

// main() — tu zaczyna się program (PORADNIK.md §5)
int main() {
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 * =============================================================================
 * JAK TO DZIAŁA?
 * =============================================================================
 * 1. #include <iostream> — dołącza bibliotekę do wypisywania na ekran.
 * 2. int main() — punkt startowy programu; każdy program C++ musi mieć main().
 * 3. std::cout << "Hello, World!\n" — wypisuje tekst i przechodzi do nowej linii.
 * 4. return 0 — kończy program; 0 oznacza sukces.
 * =============================================================================
 */
