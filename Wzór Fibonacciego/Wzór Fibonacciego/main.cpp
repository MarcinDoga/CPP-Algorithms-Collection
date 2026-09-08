#include <iostream>

using namespace std;

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	int n;
	cout << "Podaj n-ty wyraz ciagu: ";
	cin >> n;
	cout << n << " wyraz ciagu fibonacciego to: " << fibonacci(n);
	return 0;
}