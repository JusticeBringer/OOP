#include <time.h>
#include "hunter.h"
#include "hunterThree.h"

HunterThree::HunterThree(unsigned rows, unsigned columns){
    poz.first  = rows;  //pozitionare in coltul matricei
    poz.second = 1;
}

HunterThree::HunterThree(){
    poz.first  = rowsss;
    poz.second = 1; //pozitionare in coltul matricei
}

HunterThree::HunterThree(const HunterThree &ob){
    poz = ob.poz;
}

HunterThree::~HunterThree(){
    poz.first = poz.second = 0;
}

std::pair <unsigned, unsigned> HunterThree::movePoz(){
    poz.second += 2;    //spre dreapta din 2 in doi

    return poz;
}

std::pair <unsigned, unsigned> HunterThree::scadPoz(){
    poz.second -= 2;    //revenire
    
    return poz;
}

unsigned HunterThree::getMovePas(){
    return movePas;
}

unsigned HunterThree::moveOrNot(){
    srand (time(NULL));    //generare aleatorie
    return rand() % 100;
}