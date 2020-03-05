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
    
    cout << "\t \t \t \t Insert board game dimensions, at least 15x15 \n";
    cout << "\t \t Number of lines: ";
    cin >> rows;
    cout << "\t \t Number of columns: ";
    cin >> columns;    

    TreasureMap t(rows, columns, nrAgenti);
    t.desfasurare();    //initiere joc

    return 0;
}