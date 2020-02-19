#pragma once
#include <algorithm>

class Hunter{
    public:
        std::pair <unsigned, unsigned> poz; //indici
        unsigned movePas;       //pas curent
        unsigned rowsss;
        unsigned columnsss;

        Hunter();
        Hunter(unsigned, unsigned);        
        Hunter (const Hunter&);
        ~Hunter();

        virtual std::pair <unsigned, unsigned> movePoz() = 0;
            //metoda virtuala de mutat cautatori
        virtual std::pair <unsigned, unsigned> scadPoz() = 0;
            //metoda virtuala de mutat cautatori (revenire)
        virtual unsigned getMovePas() = 0;
            //hunter 1 face 2 mutari odata la 4 runde
            //hunter 4 face 2 mutari odata la 2 runde
        virtual unsigned moveOrNot() = 0;
            //hunter 2 are o sansa de 15%
              //sa faca ceilalti jucatori sa nu mute
            //hunter 3 are o sansa de 30%
              //sa faca ceilalti jucatori sa nu mute
};