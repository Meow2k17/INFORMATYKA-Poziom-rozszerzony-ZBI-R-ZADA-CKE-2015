#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int n = 50;
const int n1 = 6;
const int n2 = 15;
vector<string> t1;
vector<int> P;

string szyfr(string s, int n)
{
    for (int i = 0; i < s.size(); i++) swap(s[i], s[P[i % n] - 1]);
    return s;
}

string deszyfr(string s, int n)
{
    for (int i = s.size() - 1; i >= 0; i--) swap(s[i], s[P[i % n] - 1]);
    return s;
}

void zadanie1()
{
    cout << "--------------\nZadanie 1\n";
    for (int i = 0; i < n1; i++) cout << szyfr(t1[i], n) << endl;
}

void zadanie2()
{
    cout << "--------------\nZadanie 2\n";
    cout << szyfr(t1[0], n2) << endl;
}

void zadanie3()
{
    cout << "--------------\nZadanie 3\n";
    cout << deszyfr(t1[0], n1) << endl;
}

int main()
{
    ifstream in1("szyfr1.txt");
    ifstream in2("szyfr2.txt");
    ifstream in3("szyfr3.txt");
    t1.resize(n1);
    P.resize(n);
    for (int i = 0; i < n1; i++) in1 >> t1[i];
    for (int i = 0; i < n; i++) in1 >> P[i];
    zadanie1();

    t1.resize(1);
    P.resize(n2);
    in2 >> t1[0];
    for (int i = 0; i < n2; i++) in2 >> P[i];
    zadanie2();

    t1.resize(n1);
    P.resize(n1);
    int V[6] = {6, 2, 4, 1, 5, 3};
    in3 >> t1[0];
    for (int i = 0; i < n1; i++) P[i] = V[i];
    zadanie3();

    return 0;
}