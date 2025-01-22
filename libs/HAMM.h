#ifndef HAMM_H
#define HAMM_H

#include "DNA.h"

namespace seq {
    class HAMM : public DNA {
    public:
        HAMM();
        int calculateHammingDistance(const string& otherSequence);
    };
}

#endif 

