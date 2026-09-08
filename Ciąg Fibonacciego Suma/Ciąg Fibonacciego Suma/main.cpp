#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj ilosc kolejnych wyrazow ciagu: ";
	cin >> n;
	long long a = 1, b = 1, suma = 0;
	if (n >= 1)
	{
		cout << a << " ";
		suma += a;
	}
	if (n >= 2)
	{
		cout << b << " ";
		suma += b;
	}
	for (int i = 2; i < n; i++)
	{
		long long c = a + b;
		suma += c;
		cout << c << " ";
		a = b;
		b = c;
	}
	cout << endl << "Suma " << n << " wyrazow ciagu fibonacciego jest rowna: " << suma << endl;
	return 0;
}