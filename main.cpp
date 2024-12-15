#include <iostream>
#include "RNA.h"
#include "Prot.h"

using namespace std; // Use standard library components directly
using namespace seq;

int main() {
    // Initialize RNA sequence
    RNA rnaSeq;
    rnaSeq.setSequence("AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA");

    // Translate RNA to protein
    Prot protSeq;
    // string protein = protSeq.translate(rnaSeq.getSequence());
    protSeq.setSequence("MAMAPRTEINSTRING"); // Store the resulting sequence in protSeq

    // Output the result
    cout << "RNA Sequence: " << rnaSeq.getSequence() << endl;
    cout << "Protein: " << protSeq.getSequence() << endl; // Retrieve from Prot
    cout << "Valid: " << protSeq.validate() << endl;

    return 0;
}