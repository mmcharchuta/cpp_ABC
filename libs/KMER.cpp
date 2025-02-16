#include "KMER.h"
#include <iostream>

using namespace std;

namespace seq {

    KMER::KMER() : SPLC() {} 

    vector<int> KMER::countKMers(int k) const {
        vector<string> lexOrder;
        map<string, int> kmerCount;
        string bases = "ACGT";

        // All k-mer possibilties,lexicographically
        for (char a : bases) {
            for (char b : bases) {
                for (char c : bases) {
                    for (char d : bases) {
                        string kmer = {a, b, c, d};
                        lexOrder.push_back(kmer);
                        kmerCount[kmer] = 0;  
                    }
                }
            }
        }

        string dnaSequence = getSequence();  //original DNA seq

        // findMotif()- k-mer count
        for (const string& kmer : lexOrder) {
            vector<int> positions = findMotif(kmer);  
            kmerCount[kmer] = positions.size();  //k-mer count
        }

        // lexicographically
        vector<int> result;
        for (const string& kmer : lexOrder) {
            result.push_back(kmerCount[kmer]);
        }
        return result;
    }
}
