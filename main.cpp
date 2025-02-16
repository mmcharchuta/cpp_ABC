#include <iostream>
#include "RNA.h"
#include "Prot.h"
#include "SUBS.h"
#include "SPLC.h"
#include "HAMM.h"
#include "TRAN.h"
#include "DNA.h"
#include "CONS_PDST.h"


using namespace std; // Use standard library components directly
using namespace seq;

int main() {
    // Count nucleotides
    DNA dnaseq;
    dnaseq.setSequence("TTGCGTCGTGCT");
    cout << "Sequence: " << dnaseq.getSequence() << endl;
    for (const auto &pair: dnaseq.count()) {
        cout << "Nucleotide: " << pair.first << ", Count: " << pair.second << endl;
    }
    // Get RNA sequence
    cout << "RNA sequence: " << dnaseq.toRNA() << endl;
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
    for (int pos: positions) {
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
    splc.setSequence(
        "ATGGTCTACATAGCTGACAAACAGCACGTAGCAATCGGTCGAATCTCGAGAGGCATATGGTCACATGATCGGTCGAGCGTGTTTCAAAGTTTGCGCCTAG");

    vector<string> introns = {
        "ATCGGTCGAA",
        "ATCGGTCGAGCGTGT"
    };

    string protein = splc.spliceAndTranslate(introns);
    cout << "Protein: " << protein << endl;

    //TRAN test
    using namespace seq;

    TRAN tran;


    string seq1 = "GCAACGCACAACGAAAACCCTTAGGGACTGGATTATTTCGTGATCGTTGTAGTTATTGGA";
    string seq2 = "TTATCTGACAAAGAAAGCCGTCAACGGCTGGATAATTTCGCGATCGTGCTGGTTACTGGC";

    tran.setSequence(seq1);
    auto trans1 = tran.calculateTransitionTransversion(seq2);


    string seq3 = "AGTACGGGCATCAACCCAGTT";
    string seq4 = "GGTACGAGTGTTCCTTTGGGT";

    tran.setSequence(seq3);
    auto trans2 = tran.calculateTransitionTransversion(seq4);

    // Sum
    int totalTrans = trans1.first + trans2.first;
    int totalTransv = trans1.second + trans2.second;


    double ratio = static_cast<double>(totalTrans) / totalTransv;

    cout << "Transition/Transversion Ratio: " << ratio << endl;

    // Consensus profile
    vector<string> samples = {
        "ATCCAGCT", "GGGCAACT", "ATGGATCT",
        "AAGCAACC", "TTGGAACT", "ATGCCATT", "ATGGCACT"
    };
    MSA cons;
    cons.setSequences(samples);
    for (const auto &pair : cons.createProfileMatrix()) {
        std::cout << "Nucleotide: " << pair.first << ", Counts: ";
        for (int count : pair.second) {
            std::cout << count << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Consensus: " << cons.consensusString() << std::endl;

    // Distance Matrix
    samples = {"TTTCCATTTA", "GATTCATTTC", "TTTCCATTTT", "GTTCCATTTA"};
    vector<std::vector<float>> distanceM;
    cons.setSequences(samples);
    distanceM = cons.createDistanceMatrix();
    for (int i = 0; i < distanceM.size(); i++) {
        for (int j = 0; j < distanceM[i].size(); j++) {
            std::cout << distanceM[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
