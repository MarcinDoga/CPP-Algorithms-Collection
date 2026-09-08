#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int max_Lines = 10000;

bool czyRosnacy(int tab[], int koniec)
{
	for (int i = 1; i < koniec; i++)
		if (tab[i - 1] >= tab[i])
		{
			cout << " False" << endl;
			return false;
		}
	cout << " True" << endl;
	return true;
}

bool czyMalejacy(int tab[], int start, int koniec)
{
	for (int i = start + 1; i < koniec; i++)
		if (tab[i - 1] <= tab[i])
		{
			cout << " False" << endl;
			return false;
		}
	cout << " True" << endl;
	return true;
}


int main()
{
	ifstream plik("E:\\pi_przyklad.txt");
	int n = 0;
	int liczby[max_Lines];
	string linia;
	while (getline(plik, linia) && n < max_Lines)
	{
		istringstream(linia) >> liczby[n++];
	}
	int licznik = 0;
	for (int i = 0; i <= n - 6; i++)
	{
		int tab[6];
		for (int k = 0; k < 6; k++)
		{
			tab[k] = liczby[i + k];
		}
		for (int j = 2; j < 5; j++)
		{
			if (czyRosnacy(tab, j) && czyMalejacy(tab, j, 6))
			{
				licznik++;
				break;
			}
		}
	}
	cout << licznik << endl;
	return 0;
}