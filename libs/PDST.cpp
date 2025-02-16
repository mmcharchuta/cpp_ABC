//
// Created by obiektowecpp on 14.02.25.
//

#include "PDST.h"
#include "HAMM.h"
#include <iostream>

using namespace std;

namespace seq {
    PDST::PDST() {
        vector<std::vector<float>> distanceMatrix;
    }

    vector<std::vector<float>> PDST::createDistanceMatrix (vector<string>& samples) {
        int seqlen = samples[0].length();
        int samplen = samples.size();
        distanceMatrix.resize(samplen, std::vector<float>(samplen, 0));
        for (int i = 0; i < samplen; i++) {
            HAMM seq1;
            seq1.setSequence(samples[i]);
            for (int j = i ; j < samplen; j++) {
                if (i == j )  {
                    distanceMatrix[i][j] = 0;
                }
                else {
                    int result = seq1.calculateHammingDistance(samples[j]);
                    float x = static_cast<float>(result) / seqlen;
                    distanceMatrix[i][j] = x;
                    distanceMatrix[j][i] = x;
                }
            }
        }
        return distanceMatrix;
    }
}