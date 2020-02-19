#pragma once
#include <utility>
#include <algorithm>
#include "hunter.h"

class HunterTwo: public Hunter{
    private:
    public:
        virtual std::pair <unsigned, unsigned> movePoz();
        virtual std::pair <unsigned, unsigned> scadPoz();
        virtual unsigned getMovePas();
        virtual unsigned moveOrNot();
        
        HunterTwo(unsigned, unsigned);
        HunterTwo();
        HunterTwo(const HunterTwo&);
        ~HunterTwo();
};
