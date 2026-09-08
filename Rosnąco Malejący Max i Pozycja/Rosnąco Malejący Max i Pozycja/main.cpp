#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int maxLines = 10000;

bool rosnacoMalejacy(int tab[], int p, int d)
{
	for (int i = 1; i < p; i++)
	{
		if (tab[i - 1] >= tab[i]) return false;
	}
	for (int i = p + 1; i < d; i++)
	{
		if (tab[i - 1] <= tab[i]) return false;
	}
	return true;
}

int main()
{
	ifstream file("E:\\pi.txt");
	int numbers[maxLines], n = 0;
	string line;
	while (getline(file, line) && n < maxLines)
	{
		istringstream(line) >> numbers[n++];
	}
	int d = 6, maxI = 0, counter = 1;
	while (counter > 0)
	{
		counter = 0;
		for (int i = 0; i <= n - d; i++)
		{
			int tab[100];
			for (int k = 0; k < d; k++)
			{
				tab[k] = numbers[i + k];
			}
			for (int j = 2; j < d - 1; j++)
			{
				if (rosnacoMalejacy(tab, j, d))
				{
					counter++;
					maxI = i;
					break;
				}
			}
		}
		d++;
	}
	cout << maxI + 1 << endl;
	for (int i = maxI; i < maxI + d - 2; i++)
	{
		cout << numbers[i];
	}
}