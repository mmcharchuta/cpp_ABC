//
// Created by obiektowecpp on 14.02.25.
//

#include "CONS.h"

#include <iostream>
#include "DNA.h"
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

namespace seq {
    Cons::Cons() {
        matrix['A'] = std::vector<int>();
        matrix['T'] = std::vector<int>();
        matrix['G'] = std::vector<int>();
        matrix['C'] = std::vector<int>();
    }
    void Cons::clearMatrixIfNeeded() {
        for (const auto& pair : matrix) {
            if (!pair.second.empty()) {
                for (auto& pairClear : matrix) {
                    pairClear.second.clear();
                }
                break;
            }
        }
    }

    unordered_map<char, vector<int>> Cons::getProfileMatrix() {
        return matrix;
    }

    unordered_map<char, vector<int>> Cons::profileMatrix(vector<string>& samples){
        clearMatrixIfNeeded();
        for (int i = 0; i < samples[0].length(); i++) {
            DNA seqObj;
            for (int j = 0; j < samples.size(); j++) {
                seqObj.setSequence(seqObj.getSequence() + samples[j][i]);
            }
            for (const auto& pair : seqObj.count()) {
                matrix[pair.first].push_back(pair.second);
            }
        }
        return matrix;
    }
    string Cons::consensusString() {
        string consensus;
        for (const auto& pair : matrix) {
            if (pair.second.empty()) {
                return consensus;
            }
        }
        int vectorLength = matrix.begin()->second.size();
        for (int i = 0; i < vectorLength; i++) {
            int maxCount = -1;
            char consensusChar = ' ';
            for (const auto& pair : matrix) {
                if (pair.second[i] > maxCount) {
                    maxCount = pair.second[i];
                    consensusChar = pair.first;
                }
            }
            consensus += consensusChar;
        }
        return consensus;
    }

    string Cons::consensusString(vector<string>& samples) {
        profileMatrix(samples);
        return consensusString();
    }
}