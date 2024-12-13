#include <iostream>
#include "DNA.h"
#include "RNA.h"

using namespace std;
using namespace seq;

int main() {
    // Test DNA class
    DNA dnaSeq;
    dnaSeq.setSequence("AAAACCCGGT");
    cout << "DNA Sequence: " << dnaSeq.getSequence() << endl;
    cout << "Valid DNA: " << (dnaSeq.validate() ? "Yes" : "No") << endl;
    cout << "Complementary DNA: " << dnaSeq.get_comp() << endl;
    cout << "Reverse complementary DNA: " << dnaSeq.get_rev_comp() << endl;
    // Test RNA class
    RNA rnaSeq;
    rnaSeq.setSequence("AUGCAUG");
    cout << "RNA Sequence: " << rnaSeq.getSequence() << endl;
    cout << "Valid RNA: " << (rnaSeq.validate() ? "Yes" : "No") << endl;
    cout << "Complementary RNA: " << rnaSeq.get_comp() << endl;
    cout << "Reverse complementary RNA: " << rnaSeq.get_rev_comp() << endl;

    return 0;
}
