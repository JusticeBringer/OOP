#pragma once
#include <utility>
#include <algorithm>
#include "hunter.h"

class HunterThree: public Hunter{
    private:
    public:
        virtual std::pair <unsigned, unsigned> movePoz();
        virtual std::pair <unsigned, unsigned> scadPoz();
        virtual unsigned getMovePas();
        virtual unsigned moveOrNot();
   
        HunterThree(unsigned, unsigned);
        HunterThree();
        HunterThree(const HunterThree&);
        ~HunterThree();
};
