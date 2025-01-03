#include <iostream>
#include "RNA.h"
#include "Prot.h"
#include "SUBS.h"
#include "SPLC.h"
#include "HAMM.h"

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

    // SUBS test
    SUBS subsSeq;
    subsSeq.setSequence("GATATATGCATATACTT"); 

    string motif = "ATAT"; 
    vector<int> positions = subsSeq.findMotif(motif);

    
    cout << "Motif positions: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;


    //HAMM test
    string s = "GAGCCTACTAACGGGAT";
    string t = "CATCGTAATGACGGCCT";

    HAMM hamm;
    hamm.setSequence(s);
    int result = hamm.calculateHammingDistance(t);

    if (result == -1) {
        cout << "Error: Invalid DNA sequence or sequences of different lengths.\n";
    } else {
        cout << "Hamming Distance: " << result << endl;
    }

    // SPLC test
    SPLC splc;
    splc.setSequence("ATGGTCTACATAGCTGACAAACAGCACGTAGCAATCGGTCGAATCTCGAGAGGCATATGGTCACATGATCGGTCGAGCGTGTTTCAAAGTTTGCGCCTAG");

    vector<string> introns = {
        "ATCGGTCGAA",
        "ATCGGTCGAGCGTGT"
    };

    string protein = splc.spliceAndTranslate(introns);
    cout << "Protein: " << protein << endl;

    return 0;
}


  






