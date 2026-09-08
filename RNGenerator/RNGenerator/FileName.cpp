#include <iostream>
#include <chrono>

using namespace std;

int Random(int seed = 0)
{
	long long wynik = 0;
	if (seed == 0)
	{
		int ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
		wynik = (ms * 1234567 + 7654321) % 9182736454;
	}
	else
	{
		wynik = (seed * 1234567 + 7654321) % 9182736454;
	}
	return wynik;
}

int main()
{
	int seed, wybor;
	cout << "\tMenu\n\n1. Podaj seed\n2. Bez seeda\nWybierz: ";
	cin >> wybor;
	switch (wybor)
	{
		case 1:
		{
			cout << "Podaj seed: ";
			cin >> seed;
			cout << "Wynik losowej liczby to: " << Random(seed);
			break;
		}
		case 2:
		{
			cout << "Wynik losowej liczby to: " << Random(0);
			break;
		}
		default:
		{
			cout << "Nie wybrales poprawnej odpowiedzi!!\n";
			break;
		}
	}
	return 0;
}