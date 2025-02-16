//
// Created by obiektowecpp on 14.02.25.
//

#include "CONS_PDST.h"


#include "DNA.h"
#include "HAMM.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

namespace seq {
    MSA::MSA() {
        profileM['A'] = std::vector<int>();
        profileM['T'] = std::vector<int>();
        profileM['G'] = std::vector<int>();
        profileM['C'] = std::vector<int>();

        vector<std::vector<float> > distanceMatrix;
    }

    vector<string> MSA::getSequences() const {
        return sequences;
    }

    MSA *MSA::setSequences(vector<string> newSequences) {
        sequences = newSequences;
        distanceMatrix.clear();
        profileM.clear();
        return this;
    }

    unordered_map<char, vector<int> > MSA::getProfileMatrix() const {
        return profileM;
    }

    vector<std::vector<float> > MSA::getDistanceMatrix() const {
        return distanceMatrix;
    }

    unordered_map<char, vector<int> > MSA::createProfileMatrix() {
        for (int i = 0; i < sequences[0].length(); i++) {
            DNA seqObj;
            for (int j = 0; j < sequences.size(); j++) {
                seqObj.setSequence(seqObj.getSequence() + sequences[j][i]);
            }
            for (const auto &pair: seqObj.count()) {
                profileM[pair.first].push_back(pair.second);
            }
        }
        return profileM;
    }

    string MSA::consensusString() {
        string consensus;
        for (const auto &pair: profileM) {
            if (pair.second.empty()) {
                return consensus;
            }
        }
        int vectorLength = profileM.begin()->second.size();
        for (int i = 0; i < vectorLength; i++) {
            int maxCount = -1;
            char consensusChar = ' ';
            for (const auto &pair: profileM) {
                if (pair.second[i] > maxCount) {
                    maxCount = pair.second[i];
                    consensusChar = pair.first;
                }
            }
            consensus += consensusChar;
        }
        return consensus;
    }

    vector<std::vector<float> > MSA::createDistanceMatrix() {
        int seqlen = sequences[0].length();
        int samplen = sequences.size();
        distanceMatrix.resize(samplen, std::vector<float>(samplen, 0));
        for (int i = 0; i < samplen; i++) {
            HAMM seq1;
            seq1.setSequence(sequences[i]);
            for (int j = i; j < samplen; j++) {
                if (i == j) {
                    distanceMatrix[i][j] = 0;
                } else {
                    int result = seq1.calculateHammingDistance(sequences[j]);
                    float x = static_cast<float>(result) / seqlen;
                    distanceMatrix[i][j] = x;
                    distanceMatrix[j][i] = x;
                }
            }
        }
        return distanceMatrix;
    }
}
