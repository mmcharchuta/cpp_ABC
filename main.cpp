#include <iostream>
#include <Seq.h>

using namespace std;
using namespace seq;

int main()
{
    Seq* sequence = Seq()
        .setSequence("ACGGTA")
        ->setHeader("> ape");
    cout<< "Seq: " << sequence->getSequence() << endl;

    cout << "Or even: " << Seq()
                                .setSequence("GGCTC")
                                ->setHeader("> L'enfant terrible") << endl;
    // Seq sequence;
    // // string filepath = "/home/mmcharchuta/CLionProjects/cpp_ABC/test.fasta"; // Absolute path
    // // sequence.readFASTA(filepath);
    // cout << "Header: " << sequence.getHeader() << endl;
    // cout << "Sequence: " << sequence.getSequence() << endl;
    return 0;
}
