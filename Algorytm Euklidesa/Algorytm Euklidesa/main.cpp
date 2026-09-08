#include <iostream>

using namespace std;

int algorytmEuklidesaPetla(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	return a;
}

int algorytmEuklidesaModulo(int a, int b)
{
	while (b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main()
{
	int a, b;
	cout << "Podaj 1 liczbe: ";
	cin >> a;
	cout << "Podaj 2 liczbe: ";
	cin >> b;
	cout << "Najwiekrzy wspolny dzielnik z modulo to " << algorytmEuklidesaModulo(a, b);
}