//
// Created by obiektowecpp on 14.02.25.
//

#ifndef PDST_H
#define PDST_H

#include "HAMM.h"
#include "DNA.h"
#include <vector>
#include <string>

using namespace std;

namespace seq {
    class PDST {
    private:
        vector<std::vector<float>> distanceMatrix;
    public:
        PDST();
        vector<std::vector<float>> createDistanceMatrix (vector<string>& samples);

    };
}

#endif //PDST_H
