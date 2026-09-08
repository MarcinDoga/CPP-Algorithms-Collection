#include <iostream>

using namespace std;

const int dniTygodnia = 7;

const string tablica[dniTygodnia] = { "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela" };

int main()
{
	int liczba;
	cout << "Podaj dzien tygodnia: ";
	cin >> liczba;
	if (liczba < 1 || liczba > dniTygodnia)
	{
		cerr << "Podales zla liczbe!\n";
		return 1;
	}
	cout << "Wybrany dzien tygodnia: " << tablica[liczba - 1] << endl;
	return 0;
}