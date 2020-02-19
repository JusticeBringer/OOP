#include "hunter.h"

Hunter::Hunter() : rowsss(0), columnsss(0), movePas(0){
}   //constructor fara parametri

Hunter::Hunter(unsigned linii, unsigned coloane)
              : rowsss(linii), columnsss(coloane), movePas(0){
}   //constructor cu parametri

Hunter::Hunter (const Hunter &ob) : poz(ob.poz), movePas(ob.movePas),
                                    rowsss(ob.rowsss),columnsss(ob.columnsss){

}       //copiere date

Hunter::~Hunter(){
    rowsss     = 0; //destructor
    columnsss  = 0; //initializare cu 0
    movePas    = 0;
    poz.first  = 0;
    poz.second = 0;
} 

std::pair <unsigned, unsigned> Hunter::movePoz(){
    //metoda virtuala de mutare a pozitiilor cautatorilor
}

std::pair <unsigned, unsigned> Hunter::scadPoz(){
    //metoda virtuala de mutare a pozitiilor cautatorilor (revenire)
}

unsigned Hunter::getMovePas(){
    // intoarce movePas
}

unsigned Hunter::moveOrNot(){
    
}