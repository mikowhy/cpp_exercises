/*
 * Zadanie 11:
 * Napisz program wyznaczający wszystkie dzielniki pierwsze liczby 80.
 */

#include <iostream>
bool czy_liczba_jest_pierwsza(int liczba_do_sprawdzenia)
{

  // jezeli liczba do sprawdzenia <2 to niech funkcja powie ze nie jest liczba pierwsza
  if (liczba_do_sprawdzenia < 2)
    return false;

  // sprawdzamy czy dzieli sie przez 1 i sama siebie
  for (int n = 2; n < liczba_do_sprawdzenia; ++n)
  {
    if (liczba_do_sprawdzenia % n == 0)
      return false;
  }

  return true;
}

int main()
{
  const int liczba = 80;
  // Dzielniki pierwsze liczby 80: 2 oraz 5
  std::cout << "Pierwsze dzielniki 80 to: ";
  for (int potencjalny_dzielnik = 1; potencjalny_dzielnik <= 80; ++potencjalny_dzielnik)
  {
    if (liczba % potencjalny_dzielnik == 0 && czy_liczba_jest_pierwsza(potencjalny_dzielnik))
      std::cout << potencjalny_dzielnik << ",";
  }
  std::cout << "\n";
  return 0;
}