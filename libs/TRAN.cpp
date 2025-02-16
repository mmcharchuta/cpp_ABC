#include "TRAN.h"
#include <iostream>
using namespace std;

namespace seq {

    TRAN::TRAN() : HAMM(), SPLC() {}

    // Validate (from HAMM)
    bool TRAN::validate() const {
        return HAMM::validate(); 
    }

    unordered_map<char, char> TRAN::getCompMap() const {
        return HAMM::getCompMap(); //not used
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
    void TRAN::calculateRatio(const string& seq1, const string& seq2, const string& seq3, const string& seq4) {
        // First pair(longer)
        setSequence(seq1);
        auto trans1 = calculateTransitionTransversion(seq2);

        // Second pair
        setSequence(seq3);
        auto trans2 = calculateTransitionTransversion(seq4);

        // Suma 
        int totalTransitions = trans1.first + trans2.first;
        int totalTransversions = trans1.second + trans2.second;

        // Ratio
        double ratio = 1.0*totalTransitions / totalTransversions;


    
        cout << "Transition/Transversion Ratio: " << ratio << endl;
    }



} // namespace seq
