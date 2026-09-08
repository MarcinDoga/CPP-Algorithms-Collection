#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const int n = 1000;
	int a[n]{};
	ifstream plik("E:\\dane1_3.txt");
	for (int i = 0; i < n; i++)
	{
		plik >> a[i];
	}
	int maxSuma = a[0];
	int suma = a[0];
	for (int i = 1; i < n; i++)
	{
		if (suma < 0)
		{
			suma = a[i];
		}
		else
		{
			suma += a[i];
		}
		if (suma > maxSuma)
		{
			maxSuma = suma;
		}
	}
	cout << "Najwiekrza liczba segmentow to: " << maxSuma;
}