#include "hunter.h"
#include "hunterFour.h"

HunterFour::HunterFour(unsigned rows, unsigned columns){
    poz.first  = rows;
    poz.second = columns;   //pozitionare in coltul matricei
}

HunterFour::HunterFour(){
    poz.first  = rowsss;
    poz.second = columnsss; //pozitionare in coltul matricei
}

HunterFour::HunterFour(const HunterFour &ob){
    poz = ob.poz;
}

HunterFour::~HunterFour(){
    poz.first = poz.second = 0;
}

std::pair <unsigned, unsigned> HunterFour::movePoz(){
   poz.first  -= 1;  //in sus

   return poz;
}

std::pair <unsigned, unsigned> HunterFour::scadPoz(){
    poz.first += 1; //revenire

    return poz;
}

unsigned HunterFour::getMovePas(){
    return movePas;
}

unsigned HunterFour::moveOrNot(){
    
}