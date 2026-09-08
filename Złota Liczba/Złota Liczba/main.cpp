#include <iostream>

using namespace std;

long long fibonacci(int n)
{
	if (n > 123) {
		cerr << n << " to zbyt duzy wyraz ciagu!!\n\n";
		return 0;
	}
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
	int n;
	cout << "Podaj n-ty wyraz ciagu: ";
	cin >> n;
	cout << n << " wyraz ciagu to: " << fibonacci(n) << endl << "Zlota liczba to: " << (((long double)fibonacci(n)/ (long double)fibonacci(n-1)));
	return 0;
}