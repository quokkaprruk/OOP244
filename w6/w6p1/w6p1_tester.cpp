/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6
// Version 1.0
// Description
// tester program
//
// Revision History
// -----------------------------------------------------------
// Name  Siripa Purinruk          Date 5/July/2023           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
using namespace sdds;
using namespace std;

void FirstTen(TextFile T);
void Copy(const string& dest, const string& source);
void Dump(const string& filename);
int main() {
    TextFile Empty;
    TextFile BadFilename("badFilename");
    Copy("echoes.txt", "echoesOriginal.txt");
    Copy("seamus.txt", "seamusOriginal.txt");
    TextFile E;
    TextFile S("seamus.txt");
    cout << "Type echoes.txt and hit <ENTER>" << endl;
    cout << "Enter the text file name: ";
    cin >> E;
    cout << E << endl;
    cout << S << endl;
    FirstTen(E);
    FirstTen(S);
    E = S;
    cout << E << endl;
    cout << "============================================================" << endl;
    Dump("echoes.txt");
    Dump("seamus.txt");
    Dump("C_echoes.txt");
    Dump("C_seamus.txt");
    cout << "*" << Empty << BadFilename << "*" << endl;
    return 0;
}
void FirstTen(TextFile T) {
    if (T) {
        cout << ">>> First ten lines of : " << T.name() << endl;
        for (unsigned i = 0; i < 10; i++) {
            cout << (i + 1) << ": " << T[i] << endl;
        }
    }
    else {
        cout << "Nothing to print!" << endl;
    }
    cout << endl << "-------------------------------------------------------------" << endl;
}
void Dump(const string& filename) {
    cout << "DUMP---------------------------------------------------------" << endl;
    cout << ">>>" << filename << "<<<" << endl;
    ifstream fin(filename.c_str());
    char ch;
    while (fin.get(ch)) cout << ch;
    cout << endl << "-------------------------------------------------------------" << endl;
}
void Copy(const string& dest, const string& source) {
    ifstream fin(source.c_str());
    ofstream fout(dest.c_str());
    char ch;
    while (fin.get(ch)) fout << ch;
}