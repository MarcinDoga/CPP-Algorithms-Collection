#include <iostream>

using namespace std;


long long fibonacci(int n)
{
	long long a = 1;
	long long b = 1;
	for (long long i = 2; i < n; i++)
	{
		long long tmp = b;
		b = a + b;
		a = tmp;
	}
	return b;
}

int main()
{
	int n = 0;
	cout << "Podaj ilosc wyrazow do wyswietlenia: ";
	cin >> n;
	if (n == 0) return 1;
	for (int i = 2; i < n; i++)
	{
		cout << i << " wyraz ciagu to: " << fibonacci(i) << endl;
	}
	return 0;
}