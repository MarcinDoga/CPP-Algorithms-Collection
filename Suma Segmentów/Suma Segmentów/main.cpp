#include <iostream>
#include <fstream>

using namespace std;

/*int sumaSegmentow()
{

}*/

int main()
{
	const int n = 1000;
	int a[n];
	ifstream plik("E:\\dane1_3.txt");
	if (!plik)
	{
		cerr << "Nie mozna otworzyc pliku!\n";
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		plik >> a[i];
	}
	plik.close();
	int maxSuma = a[0];
	for (int i = 0; i < n; i++)
	{
		int suma = 0;
		for (int j = i; j < n; j++)
		{
			suma = suma + a[j];
			if (suma > maxSuma)
			{
				maxSuma = suma;
			}
		}
	}
	cout << "Najwiekrza suma segmentow to: " << maxSuma;
}