#include <iostream>

using namespace std;

bool czyRosnacoMalejacy(int tab[], int n)
{
	if (n < 4) return false;
	int k = 1;
	while (k < n && tab[k] > tab[k - 1]) k++;
	if (k == 1 || k == n) return false;
	while (k < n && tab[k] < tab[k - 1]) k++;
	return k == n;
}

int main()
{
	int n;
	cout << "Podaj liczbe elementow: ";
	cin >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; i++) cin >> tab[i];
	cout << (czyRosnacoMalejacy(tab, n) ? "Jest rosnaco malejacy." : "Nie jest rosnaco malejacy.") << endl;
	return 0;
}