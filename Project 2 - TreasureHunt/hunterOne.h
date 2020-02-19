#pragma once
#include <utility>
#include <algorithm>
#include "hunter.h"

class HunterOne: public Hunter{
    private:
    public:
        virtual std::pair <unsigned, unsigned> movePoz();
        virtual std::pair <unsigned, unsigned> scadPoz();
        virtual unsigned getMovePas();
        virtual unsigned moveOrNot();

        HunterOne(unsigned, unsigned);
        HunterOne();
        HunterOne(const HunterOne&);
        ~HunterOne();
};
