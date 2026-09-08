#include <iostream>

using namespace std;

int main()
{
const int dni = 3, miasta = 4;
string nazwyMiast[miasta] = {"Warszawa", "Krawow", "Gdansk", "Wroclaw"};
string dniTygodnia[dni] = { "Poniedzialek", "Wtorek", "Sroda" };
string prognoza[dni][miasta] = 
{
	{"Slonce", "Deszcz", "Chmury", "Slonce"},
	{"Chmury", "Slonce", "Deszcz", "Deszcz"},
	{"Deszcz", "Deszcz", "Chmury", "Slonce"}
};
for (int i = 0; i < dni; i++)
{
	cout << dniTygodnia[i] << ": " << endl;
	for (int j = 0; j < miasta; j++)
	{
		 cout << nazwyMiast[j] << ": " << prognoza[i][j] << endl;
	}
}
return 0;
}