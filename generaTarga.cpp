#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

const string p = "ATTRAVERSO";

string CarattereMaiuscolo(string s) {
    for (char &c : s)
        c = toupper(c);
    return s;
}

char generaLetteraMaiuscola() {
    return 'A' + (rand() % 26);
}

string generaNumero3Cifre() {
    int n = 1 + (rand() % 999);
    if (n < 10)       return "00" + to_string(n);
    else if (n < 100) return "0"  + to_string(n);
    else              return to_string(n);
}

char generaLetteraMaiuscolaPari() {
    int codice;
    do {
        codice = 'A' + (rand() % 26);
    } while (codice % 2 != 0); // solo lettere con codice ASCII pari
    return char(codice);
}

string generatarga() {
    if (p.size() > 4 && p.size() < 11) {
        string PAR = CarattereMaiuscolo(p);

        char t1 = PAR[4];
        char t2;

        do {
            t2 = generaLetteraMaiuscola();
        } while (t1 == t2 && (t1=='A' || t1=='E' || t1=='I' || t1=='O' || t1=='U'));

        string t345 = generaNumero3Cifre();
        char t6 = generaLetteraMaiuscolaPari();
        char t7 = generaLetteraMaiuscolaPari();

        string targa;
        targa.push_back(t1);
        targa.push_back(t2);
        targa += t345;
        targa.push_back(t6);
        targa.push_back(t7);

        return targa;
    } else {
        exit(1);
    }
}

int main() {
    srand(time(0));
    string targa = generatarga();
    cout<<targa;

    return 0;
}