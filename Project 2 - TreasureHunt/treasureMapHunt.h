#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

#include "hunter.h"
#include "hunterOne.h"

using namespace std;

class TreasureMap{
    friend class Hunter;
    private:
        int **matrix;   //harta
        int **matrixViz;
        unsigned rows;
        unsigned columns;
        unsigned nrHunters;
        unsigned pas;
        std::vector <Hunter*> ArrHunter; 
        std::vector <unsigned> Comori; 
        std::pair <unsigned, unsigned> poz;

    public:
        TreasureMap ();
        TreasureMap (unsigned, unsigned, unsigned);
        TreasureMap (const TreasureMap &);
        ~TreasureMap ();   

        unsigned randomRow (unsigned);
        unsigned randomCol (unsigned);

        void showMatrix ();  //afisare matrice
        void desfasurare (); //initiere joc
        void detalii ();     //afisare detalii
        void changeMatrix(); //deplasare pe harta
        void moveHunters(Hunter*, unsigned, unsigned&);
        void generateTreasures(); //generare pozitie comori
        void stopPoz(unsigned, unsigned); //oprire mutare cautator

        bool test(); //testare matrice >= 15x15
        bool inLimitsRows(unsigned); //iesire din limite
        bool inLimitsColumns(unsigned);

        std::pair <unsigned, unsigned> getNextPoz(std::pair <unsigned, unsigned> );
                //obtinere urmatoarea pozitie a cautatorului
        std::pair <unsigned, unsigned> findTreasure();
                //gaseste prima comoara pe harta disponibila
};



