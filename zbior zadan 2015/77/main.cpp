#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
vector<string> tekst;
vector<string> tekst2;

struct szyfr
{
    int licznik;
    string tekst;
};

szyfr szyfrowanie(vector<string> wiersz, string kod, bool x)
{
    string s;
    string wynik = "";
    int licznik1 = 0, licznik2 = 0, powtorzenia = 0;
    for (int i = 0; i < wiersz.size(); i++) {
        for (int j = 0; j < wiersz[i].length(); j++) {
            licznik1++;
            if ((licznik1 % kod.length()) == 1) powtorzenia++;
            char c = wiersz[i][j];
            if (c >= 'A' && c <= 'Z') {
                s = "";
                if (licznik2 == kod.length()) licznik2 = 0;
                int cVal = int(c) - 'A';
                int kVal = int(kod[licznik2]) - 'A';
                licznik2++;
                if (x == false) s += char((cVal + kVal) % 25 + 'A');
                else {
                    if (cVal - kVal >= 0) {
                        s += char((cVal - kVal) + 'A');
                    } else {
                        s += char('Z' - (cVal - kVal) * (-1) + 1);
                    }
                }
                wynik += s;
            } else wynik += c;
        }
        wynik += " ";
    }
    szyfr szyfrval;
    szyfrval.licznik = powtorzenia;
    szyfrval.tekst = wynik;
    return szyfrval;
}

int main()
{
    ifstream in1("dokad.txt");
    ifstream in2("szyfr.txt");
    int licznik1 = 0, licznik2 = 0, powtorzenia = 0;
    string szyfr = "LUBIMYCZYTAC", tekst1 = "", s = "";
    while (!in1.eof()) {
        in1 >> s;
        tekst.push_back(s);
    }
    cout << "--------------\nZadanie 1\n";
    cout << "Liczba powtorzen: " << szyfrowanie(tekst, szyfr, false).licznik - 1 << endl;
    cout << szyfrowanie(tekst, szyfr, false).tekst << endl;

    while (!in2.eof()) {
        in2 >> s;
        tekst2.push_back(s);
    }
    szyfr = tekst2.back();
    tekst2.erase(tekst2.end() - 2, tekst2.end());
    cout << "--------------\nZadanie 2\n";
    cout << szyfrowanie(tekst2, szyfr, true).tekst << endl;

    string x = "";
    for (int i = 0; i < tekst2.size(); i++) {
        x += tekst2[i];
        if (i != tekst2.size() - 1)
            x += " ";
    }
    int L[26];
    for (int j = 0; j < 26; j++) L[j] = 0;
    int n = 0;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] >= 'A' && x[i] <= 'Z') {
            int j = x[i] - 'A';
            L[j]++;
            n++;
        }
    }
    cout << "--------------\nZadanie 3\n";
    cout << "Ilosc wystapien liter:\n";
    for (int i = 0; i < 26; i++)
        cout << char(i + 'A') << " - " << L[i] << endl;
    int suma = 0;
    for (int j = 0; j < 26; j++) suma += L[j] * (L[j] - 1);
    double ko = double(suma) / (n * (n - 1));
    double d = 0.0285 / (ko - 0.0385);
    cout << "Szacunkowa dlugosc klucza - " << fixed << setprecision(2) << d << endl;
    cout << "Dokladna dlugosc klucza - " << szyfr.length() << "\n--------------\n";

    return 0;
}
