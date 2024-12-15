#include <iostream>
#include "RNA.h"
#include "Prot.h"

using namespace std;
using namespace seq; // Use seq namespace for DNA, RNA, and Prot.

int main() {
    // Initialize RNA sequence
    RNA rnaSeq;
    rnaSeq.setSequence("AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA");

    // Translate RNA to protein
    Prot protTranslator;
    string protein = protTranslator.translate(rnaSeq.getSequence());

    // Output the result
    cout << "RNA Sequence: " << rnaSeq.getSequence() << endl;
    cout << "Protein: " << protein << endl;

    return 0;
}