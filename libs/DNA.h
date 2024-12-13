#ifndef DNA_H
#define DNA_H

#include "Seq.h"

namespace seq {
    class DNA : public Seq {
    public:
        DNA();
        bool validate() const override;
        unordered_map<char, char> getCompMap() const override;
    };
}

#endif // DNA_H
