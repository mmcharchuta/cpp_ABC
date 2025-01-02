#ifndef SUBS_H
#define SUBS_H

#include "DNA.h"
#include <vector>
#include <string>

using namespace std;

namespace seq {
    class SUBS : public DNA {
    public:
        SUBS(); 

        vector<int> findMotif(const string& motif);

        bool validate() const override;
    };
}

#endif 
