#include <iostream>
#include <ostream>
#include <cassert>
#include "mainHeader.h"
#include "node.h"

using namespace std;

int main(){

    Dictionary <int, int> D;
    Dictionary <int, int> H;

    int val;
    D.add(6, 18);   
    assert(D.srchKey(6, val));   //cautare dupa cheie

    H = D;                  //operatorul =
    assert(!H.isEmpty());
     
    D.add(2, 15);
    int x = D[2];           //operatorul de []
    //cout << x << " ";
    
    D.add(3, 12);
    D.add(4, 3);

    cout << D;
    
    D.deleteAllElements();
    assert(D.isEmpty());    //stergere toate elementele

    D.add(5, 7);
    D.deleteAfKey(5);
    assert(D.srchKey(5, val));  //stergere dupa cheie

    return 0;
}