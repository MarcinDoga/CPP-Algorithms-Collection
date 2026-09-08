#include <iostream>

using namespace std;

int main()
{
	int n;

	cout << "Podaj liczbe wyrazow ciagu fibonacciego: ";
	cin >> n;
	if (n <= 0)
	{
		cerr << "Podales niepoprawna liczbe!!\n";
		return 1;
	}

	long long a = 1, b = 1;
	if (n >= 1)
	{
		cout << a << " ";
	}
	if (n >= 2)
	{
		cout << b << " ";
	}

	for (long long i = 2; i < n; i++)
	{
		long long c = a + b;
		cout << c << " ";
		a = b;
		b = c;
	}
}