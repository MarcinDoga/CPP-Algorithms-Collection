#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj ilosc nastepnych liczb z ciagu: ";
	cin >> n;

	long long a = 0, b = 1, c = 1;
	if (n >= 0)
	{
		cout << a << " ";
	}
	if (n >= 1)
	{
		cout << b << " ";
	}
	if (n >= 2)
	{
		cout << c << " ";
	}
	for (long long i = 3; i < n; i++)
	{
		long long d = a + b + c;
		cout << d << " ";
		a = b;
		b = c;
		c = d;
	}
}