#include "TRAN.h"

using namespace std;

namespace seq {

    TRAN::TRAN() : HAMM(), SPLC() {}

    // Validate (from HAMM)
    bool TRAN::validate() const {
        return HAMM::validate(); 
    }

    unordered_map<char, char> TRAN::getCompMap() const {
        return HAMM::getCompMap(); 
    }

    // transition check
    bool TRAN::isTransition(char a, char b) const {
        return (a == 'A' && b == 'G') || (a == 'G' && b == 'A') ||  // A <-> G
               (a == 'C' && b == 'T') || (a == 'T' && b == 'C');    // C <-> T
    }

    //transversion check
    bool TRAN::isTransversion(char a, char b) const {
        return !isTransition(a, b) && a != b;  // Must be different and not a transition
    }

    // get number of transitions and transversions between sequences
    pair<int, int> TRAN::calculateTransitionTransversion(const string& otherSequence) {
        int hammingDistance = calculateHammingDistance(otherSequence);  //  HAMM's method
        //The Hamming distance measures how many positions the sequences differ from each other.If the Hamming distance is -1- indicate an error ( the sequences have different lengths), the function returns {-1, -1}, indicating an error.
        if (hammingDistance == -1) {
            return {-1, -1}; // Invalid sequences
        }

        int transitions = 0;
        int transversions = 0;

        // Loop through both sequences, find mismatches
        for (int i = 0; i < sequence.length(); ++i) {
            char a = sequence[i];
            char b = otherSequence[i];

            if (a != b) {  // must be a mismatch
                if (isTransition(a, b)) {
                    ++transitions;  
                } else if (isTransversion(a, b)) {
                    ++transversions;  
                }
            }
        }

        return {transitions, transversions};
    }

} // namespace seq
