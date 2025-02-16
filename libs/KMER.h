#ifndef KMER_H
#define KMER_H

#include "SPLC.h"
#include <vector>
#include <map>

using namespace std;

namespace seq {
    class KMER : public SPLC {
    public:
        KMER();
        vector<int> countKMers(int k) const;  
    };
}

#endif
