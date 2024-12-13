#include <iostream>
#include <Seq.h>
using namespace std;
int main()
{
    Seq sequence;
    string filepath = "/home/mmcharchuta/CLionProjects/cpp_ABC/test.fasta"; // Absolute path
    sequence.readFASTA(filepath);
    cout << "Header: " << sequence.getHeader() << endl;
    cout << "Sequence: " << sequence.getSequence() << endl;
    return 0;
}
