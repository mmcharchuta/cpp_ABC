#ifndef RNA_H
#define RNA_H

#include "Seq.h"

namespace seq {
    class RNA : public Seq {
    public:
        RNA();
        bool validate() const override;
        unordered_map<char, char> getCompMap() const override;
    };
}

#endif // RNA_H
