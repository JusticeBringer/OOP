#include <iostream>
#include "hunter.h"
#include "hunterOne.h"

HunterOne::HunterOne(unsigned rows, unsigned columns){
    poz.first  = 1; //pozitionare in coltul matricei
    poz.second = 1;
}

HunterOne::HunterOne(){
    poz.first = poz.second = 1; //pozitionare in coltul matricei
}

HunterOne::HunterOne(const HunterOne &ob){
    poz = ob.poz;
}

HunterOne::~HunterOne(){
    poz.first = poz.second = 0;
}

std::pair <unsigned, unsigned> HunterOne::movePoz(){
    poz.first += 1; //in jos

    return poz;
}
 
std::pair <unsigned, unsigned> HunterOne::scadPoz(){
    poz.first -= 1; //revenire
    
    return poz;
}

unsigned HunterOne::getMovePas(){
    return movePas;
}

unsigned HunterOne::moveOrNot(){
    
}