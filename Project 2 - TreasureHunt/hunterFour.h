#pragma once
#include <utility>
#include <algorithm>
#include "hunter.h"

class HunterFour: public Hunter{
    private:
    public:
        virtual std::pair <unsigned, unsigned> movePoz();
        virtual std::pair <unsigned, unsigned> scadPoz();
        virtual unsigned getMovePas();
        virtual unsigned moveOrNot();
        
        HunterFour(unsigned, unsigned);
        HunterFour();
        HunterFour(const HunterFour&);
        ~HunterFour();
};
