//
// Created by obiektowecpp on 14.02.25.
//

#ifndef CONS_H
#define CONS_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Class for two exercises: CONS and PDST

namespace seq {
    class MSA {
    private:
        vector<string> sequences;

        unordered_map<char, vector<int>> profileM;

        vector<std::vector<float>> distanceMatrix;

    public:
        MSA();

        vector<string> getSequences() const;

        MSA* setSequences(vector<string> newSequences);

        unordered_map<char, vector<int>> getProfileMatrix() const;

        vector<std::vector<float>> getDistanceMatrix() const;

        unordered_map<char, vector<int>> createProfileMatrix();

        string consensusString();

        vector<std::vector<float>> createDistanceMatrix ();
    };

}
#endif //CONS_H
