#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool czyRosnacoMalejacy(int tab[], int n)
{
    if (n < 4)
    {
        std::cout << " 1 False"; 
        return false;
    }
    int k = 1;
    while (k < n && tab[k] > tab[k - 1]) k++;

    if (k == 1 || k == n)
    {
       std::cout << " 2 False"; 
        return false;
    }
    while (k > n && tab[k] < tab[k - 1]) k++;
    cout << (k == n ? " 3 True" : " 3 False");
    return (k == n ? true : false);
}

int main()
{
    ifstream file("E:/pi_przyklad.txt");
    if (!file)
    {
        cerr << "Blad, nie mozna otworzyc pliku txt!\n";
        return 1;
    }
    string ciag;
    char znak;
    while (file >> znak)
    {
         ciag += znak;
    }
    cout << ciag << endl << endl;
    file.close();

    int liczbaCiagow = 0;
    int n = ciag.length();
    for (int i = 0; i <= n - 6; i++)
    {
        int tab[6];
        for (int j = 0; j < 6; j++)
        {
            tab[j] = ((ciag[j + i]) - '0');
            cout << to_string(tab[j]);
        }
        if (czyRosnacoMalejacy(tab, 6))
        {
            liczbaCiagow++;
        }
        cout << endl;
    }
    cout << "Liczba rosnaco malejacych ciagow to: " << liczbaCiagow << endl;
    return 0;
}
