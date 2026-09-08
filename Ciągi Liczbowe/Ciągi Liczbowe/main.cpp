#include <iostream>
#include <vector>

using namespace std;

bool czyArytmetyczny(int tab[], int n)
{
	int r = tab[1] - tab[0];
	for (int i = 2; i < n; i++)
	{
		if (tab[i] - tab[i-1] != r)
		return false;
	}
	return true;
}

int main()
{
	int n;
	cout << "Podaj ilosc liczb: ";
	cin >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; i++) cin >> tab[i];
	cout << (czyArytmetyczny(tab, n) ? "Jest arytmetyczny." : "Nie jest arytmetyczny." ) << endl;
	return 0;
}