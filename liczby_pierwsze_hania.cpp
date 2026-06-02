#include <iostream>
// Napisz program znajdujący najmniejszą i największą trzycyfrową liczbę pierwszą.

// tu zrobimy funkcje ktora bedzie sprawdzala czy liczba jest pierwsza
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
  int min_pierwsza = -1;
  int max_pierwsza = -1;

  for (int n = 100; n <= 999; ++n)
  {

    // Sprawdzamy czy dzieli się przez 1 i samą siebie
    if (czy_liczba_jest_pierwsza(n))
    {
      if (min_pierwsza == -1)
        min_pierwsza = n;
      max_pierwsza = n;
    }
  }

  std::cout << "najmniejsza liczba pierwsza:" << min_pierwsza << "\n";
  std::cout << "najwieksza liczba pierwsza:" << max_pierwsza << "\n";

  return 0;
}