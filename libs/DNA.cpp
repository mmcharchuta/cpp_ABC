#include "DNA.h"

namespace seq {

    DNA::DNA() {
        // Initialize compMap for DNA (A ↔ T, C ↔ G)
        compMap['A'] = 'T';
        compMap['T'] = 'A';
        compMap['C'] = 'G';
        compMap['G'] = 'C';
    }

    bool DNA::validate() const {
        for (char base : sequence) {
            if (base != 'A' && base != 'C' && base != 'T' && base != 'G') {
                return false; // Invalid character for DNA
            }
        }
        return true; // All characters are valid for DNA
    }

    unordered_map<char, char> DNA::getCompMap() const {
        return compMap;
    }

    string DNA::toRNA() const {
        string rnaSequence = sequence;
        for (char& base : rnaSequence) {
            if (base == 'T') {
                base = 'U';  // Replace T with U (for RNA)
            }
        }
        return rnaSequence;
    }
} // namespace seq
