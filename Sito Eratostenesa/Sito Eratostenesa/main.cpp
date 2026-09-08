#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Podaj gorna granice: ";
	cin >> n;
	if (n < 2)
	{
		cout << "Brak liczb pierwszych.";
		return 0;
	}
	bool* sito = new bool[n + 1];
	for (int i = 2; i <= n; i++)
	{
		sito[i] = true;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (sito[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				sito[j] = false;
			}
		}
	}
	cout << "Liczby pierwsze do " << n << " to:\n";
	for (int i = 2; i <= n; i++)
	{
		if (sito[i])
		{
			cout << i << endl;
		}
	}
	delete[] sito;
	return 0;
}