#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class LargeNumber {
private:
    string number;

public:
    LargeNumber() : number("0") {}
    LargeNumber(const string& num) : number(num) {}
    LargeNumber(int num) : number(to_string(num)) {}

    // Operator dodawania
    LargeNumber operator+(const LargeNumber& other) const {
        string result;
        int carry = 0;
        int maxLength = max(number.length(), other.number.length());
        for (int i = 0; i < maxLength || carry; ++i) {
            int digit1 = i < number.length() ? number[number.length() - 1 - i] - '0' : 0;
            int digit2 = i < other.number.length() ? other.number[other.number.length() - 1 - i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return LargeNumber(result);
    }

    // Operator mno¿enia przez int bez u¿ycia long long
    LargeNumber operator*(int x) const {
        LargeNumber result("0");
        LargeNumber multiplier("1");

        // Liczymy tak jak na papierze: ka¿d¹ cyfrê mno¿ymy i dodajemy do wyniku
        for (int i = number.size() - 1; i >= 0; i--) {
            int digit = number[i] - '0';
            LargeNumber temp = multiplier * digit; // mno¿enie przez cyfrê
            result = result + temp;                // dodajemy do wyniku
            multiplier = multiplier * 10;         // przesuniêcie dziesiêtne
        }

        // Pomocniczy operator mno¿enia przez jedn¹ cyfrê (0-9)
        return result * x; // finalnie pomno¿one przez x
    }

    friend ostream& operator<<(ostream& out, const LargeNumber& num) {
        out << num.number;
        return out;
    }
};

// Funkcja obliczaj¹ca silniê
LargeNumber factorial(int n) {
    LargeNumber result("1");
    for (int i = 2; i <= n; ++i) {
        result = result * i;
    }
    return result;
}

int main() {
    int n;
    cout << "Podaj liczbe odpowiadajaca silnii: ";
    cin >> n;

    LargeNumber wynik = factorial(n);
    cout << "Silnia z " << n << " wynosi: " << wynik << endl;
}
