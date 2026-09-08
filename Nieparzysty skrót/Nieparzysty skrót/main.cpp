#include <iostream>
#include <string>

using namespace std;

int sumaCyfr(int n)
{
	int suma = 0;
	while (n > 0)
	{
		suma += n % 10;
		n /= 10;
	}
	return suma;
}

int nieparzystySkrot(int n)
{
	while (n >= 10)
	{
		n = sumaCyfr(n);
	}
	if (n%2 == 1)
	{
		return n;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int n;
	cout << "Podaj liczbe: ";
	cin >> n;
	int wynik = nieparzystySkrot(n);
	if (wynik == -1)
	{
		cout << "Nie istnieje nieparzysty wynik liczby.";
	}
	else
	{
		cout << "Nieparzysty skrot to: " << wynik;
	}
	return 0;
}