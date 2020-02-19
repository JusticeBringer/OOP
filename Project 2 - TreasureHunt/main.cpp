#include <iostream>
#include <cstring>
#include <cmath>
#include <time.h>
#include "treasureMapHunt.h"

using namespace std;

int main()
{
    unsigned nrAgenti = 4;
    unsigned rows, columns;
    
    cout << "\t \t \t \t Introduceti dimensiunea matricei, cel putin 15x15 \n";
    cout << "\t \t Numar de linii: ";
    cin >> rows;
    cout << "\t \t Numar de coloane: ";
    cin >> columns;    

    TreasureMap t(rows, columns, nrAgenti);
    t.desfasurare();    //initiere joc

    return 0;
}