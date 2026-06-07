// napisz funkcje, ktora bedzie badala podzielnosc liczby jednoczesnie przez 3 i 17(bez uzycia &)

#include <iostream>
bool czy_dzieli_sie_przez_3_i_17(int liczba_do_sprawdzenia)
{
  return liczba_do_sprawdzenia % 3 == 0 && liczba_do_sprawdzenia % 17 == 0;
}

int main()
{
  int liczba;
  std::cout << "Podaj liczbe calkowita";
  std::cin >> liczba;

  if (czy_dzieli_sie_przez_3_i_17(liczba))
    std::cout << "Liczba dzieli sie przez 3 i 17";

  else
    std::cout << "Liczba nie dzieli sie przez 3 i 17";

  return 0;
}
