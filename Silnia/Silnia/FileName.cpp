#include <iostream>

using namespace std;

long long silnia(int n)
{
	if (n == 0)
		return 1;
	else
		return long long(n * silnia(n - 1));
}

int main()
{
	int n;
	cout << "Podaj liczbe odpowiadajaca silnii: ";
	cin >> n;
	cout << "Silnia z " << n << " wynosi: " << silnia(n) << endl;
}