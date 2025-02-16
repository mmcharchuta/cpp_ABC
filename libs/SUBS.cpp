#include "SUBS.h"

using namespace std;

namespace seq {

    SUBS::SUBS() : DNA() {}

    // Finding Motifs
    vector<int> SUBS::findMotif(const string& motif) const {
        vector<int> positions;
        size_t pos = sequence.find(motif, 0); //find is a built-in function to return the position of the first match
        while (pos != string::npos) {
            positions.push_back(pos + 1); // Index 1-based
            pos = sequence.find(motif, pos + 1);
        }
        return positions;
    }

    // Validate, DNA inherited
    bool SUBS::validate() const {
        return DNA::validate();
    }

    
}

//Validation is simplified by inheritance from the DNA class. We avoid redundancy-the entire validation logic is located in the base DNA class