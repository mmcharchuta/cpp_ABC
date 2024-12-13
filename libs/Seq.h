#ifndef SEQ_H // If SEQ_H is not already defined
#define SEQU_H  // Define SEQ_H (this will prevent multiple inclusions)
#include <string>
#include <unordered_map>
using namespace std;

namespace seq {
    class Seq {
    protected:
        unordered_map<char, char> compMap;
        string header;
        string sequence;
    public:
        string getHeader() const;
        string getSequence() const;

        Seq();
        Seq(const string& filepath);

        // Method reads single sequence and its header from FASTA file
        void readFASTA(const string& filepath);

        // Method returns an unordered map, where the key is the character, and the value is the count of its occurrences in
        // the sequence attribute. It depends on compMap attribute.
        unordered_map<char, int> count();
        string get_rev_comp();
        string get_comp();
    };
}



#endif //SEQ_H // End the conditional inclusion
