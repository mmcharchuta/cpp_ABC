#include "HAMM.h"

using namespace seq;

HAMM::HAMM() : DNA() {}

// Calculate Hamming Distance
int HAMM::calculateHammingDistance(const string& otherSequence) {
    // Use validate() from DNA to ensure the first and second sequence is valid
    if (!validate()) {
        return -1; //Invalid sequences
    }

    DNA otherDNA;
    otherDNA.setSequence(otherSequence);
    if (!otherDNA.validate()) {
        return -1; // Invalid sequences
    }

    if (sequence.length() != otherSequence.length()) {
        return -1; // Sequences must be of equal length
    }

    int hammingDistance = 0;
    for (size_t i = 0; i < sequence.length(); ++i) {
        if (sequence[i] != otherSequence[i]) {
            ++hammingDistance;
        }
    }
    return hammingDistance;
}
