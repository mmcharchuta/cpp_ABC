#ifndef SUBS_H
#define SUBS_H

#include "DNA.h"
#include <vector>
#include <string>

using namespace std;

namespace seq {
    class SUBS : public virtual DNA {
    public:
        SUBS();
        vector<int> findMotif(const string& motif);
        bool validate() const override;
        std::unordered_map<char, char> getCompMap() const override;
    };
}

#endif // SUBS_H
