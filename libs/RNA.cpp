#include "RNA.h"

namespace seq {

    RNA::RNA() {
        // Initialize compMap for RNA (A ↔ U, C ↔ G)
        compMap['A'] = 'U';  // RNA uses U instead of T
        compMap['U'] = 'A';
        compMap['C'] = 'G';
        compMap['G'] = 'C';
    }

    bool RNA::validate() const {
        for (char base : sequence) {
            if (base != 'A' && base != 'C' && base != 'U' && base != 'G') {
                return false; // Invalid character for RNA
            }
        }
        return true; // All characters are valid for RNA
    }

    unordered_map<char, char> RNA::getCompMap() const {
        return compMap;
    }

} // namespace seq
