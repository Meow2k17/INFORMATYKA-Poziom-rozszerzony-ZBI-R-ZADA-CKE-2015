#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int N = 805;
vector<string> slowa;
vector<string> jawne;
vector<string> zakodowane;
const int wiersze = 5;

string szyfruj(string s, int x, int y)
{
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        c = c * x + y;
        c %= 26;
        s[i] = c + 'a';
    }
    return s;
}

void zadanie1()
{
    string s;
    cout << "------------\nZadanie 1\n";
    for (int i = 0; i < N; i++) {
        s = slowa[i];
        if (s[0] == 'd' && s[s.length() - 1] == 'd')
            cout << s << endl;
    }
}

void zadanie2()
{
    string s;
    cout << "------------\nZadanie 2\n";
    for (int k = 0; k < N; k++) {
        s = slowa[k];
        for (int i = 0; i < s.length(); i++) {
            s[i] -= 'a';
            s[i] = s[i] * 5 + 2;
            s[i] %= 26;
            s[i] += 'a';
        }
        if (s.length() >= 10)
            cout << s << endl;
    }
}

void zadanie3()
{
    string s1, s2;
    cout << "------------\nZadanie 3\n";
    for (int i = 0; i < wiersze; i++) {
        s1 = jawne[i];
        s2 = zakodowane[i];
        for (int j = 0; j <= 25; j++) {
            for (int k = 0; k <= 25; k++) {
                if (szyfruj(s1, j, k) == s2)
                    cout << "Klucz szyfrujacy numer " << i + 1 << ": (" << j << ", " << k << ")" << endl;
            }
        }
        for (int j = 0; j <= 25; j++) {
            for (int k = 0; k <= 25; k++) {
                if (szyfruj(s2, j, k) == s1)
                    cout << "Klucz deszyfrujacy numer " << i + 1 << ": (" << j << ", " << k << ")" << endl;
            }
        }
    }
}

int main()
{
    ifstream in("tekst.txt");
    ifstream in1("probka.txt");
    slowa.resize(N);
    for (int i = 0; i < N; i++) in >> slowa[i];
    jawne.resize(wiersze);
    zakodowane.resize(wiersze);
    for (int i = 0; i < wiersze; i++) {
        in1 >> jawne[i];
        in1 >> zakodowane[i];
    }

    zadanie1();
    zadanie2();
    zadanie3();
}
