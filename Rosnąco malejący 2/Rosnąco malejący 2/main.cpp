#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

const int max_Lines = 10000;

bool czyRosnacy(int tab[], int koniec)
{
	for (int i = 1; i < koniec; i++)
		if (tab[i - 1] >= tab[i]) return false;
	return true;
}

bool czyMalejacy(int tab[], int start, int koniec)
{
	for (int i = start + 1; i < koniec; i++)
		if (tab[i - 1] <= tab[i]) return false;
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
	int dl = 6, idx = 0;
	bool found = true;
	while (found)
	{
		found = false;
		for (int i = 0; i <= n - dl; i++)
		{
			int tab[100];
			for (int k = 0; k < dl; k++)
			{
				tab[k] = liczby[i + k];
			}
			for (int j = 2; j < dl - 1; j++)
			{
				if (czyRosnacy(tab, j) && czyMalejacy(tab, j, dl))
				{
					idx = i;
					found = true;
					break;
				}
			}
		}
		dl++;
	}
	cout << idx + 1 << endl;

	for (int i = idx; i < idx + dl - 2; i++)
	{
		cout << liczby[i];
	}
	return 0;
}