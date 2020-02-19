#include <time.h>
#include "hunter.h"
#include "hunterTwo.h"

HunterTwo::HunterTwo(unsigned rows, unsigned columns){
    poz.first  = 1;         //pozitionare in colt
    poz.second = columns;
}

HunterTwo::HunterTwo(){
    poz.first  = 1;
    poz.second = columnsss; //pozitionare in coltul matricei
}

HunterTwo::HunterTwo(const HunterTwo &ob){
    poz = ob.poz;
}

HunterTwo::~HunterTwo(){
    poz.first = poz.second = 0;
}

std::pair <unsigned, unsigned> HunterTwo::movePoz(){
    poz.second -= 1;    //spre stanga

   return poz;
}

std::pair <unsigned, unsigned> HunterTwo::scadPoz(){
    poz.second += 1;    //revenire
    
    return poz;
}

unsigned HunterTwo::getMovePas(){
    return movePas;
}

unsigned HunterTwo::moveOrNot(){
    srand (time(NULL));    //generare aleatorie
    return rand() % 100;
}