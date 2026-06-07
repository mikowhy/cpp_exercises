/*
 * Zadanie 6:
 * Napisz program, który dla danej liczby rzeczywistej a wyświetli wartości:
 * cos(a) oraz sin(a). Skorzystaj z gotowych funkcji sin oraz cos z biblioteki cmath.
 */
#include <iostream>
#include <cmath>

int main()
{
  double liczba;
  std::cout << "Podaj liczbe ";
  std::cin >> liczba;
  std::cout << "\n";
  std::cout << "cos(" << liczba << ") = " << cos(liczba) << '\n';
  std::cout << "sin(" << liczba << ") = " << sin(liczba) << '\n';

  // cos(1) = 0.540302, sin(1) = 0.841471

  return 0;
}