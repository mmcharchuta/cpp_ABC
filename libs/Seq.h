#ifndef SEQ_H // If SEQ_H is not already defined
#define SEQU_H  // Define SEQ_H (this will prevent multiple inclusions)
#include <string>
#include <unordered_map>
using namespace std;

class Seq {
protected:
    unordered_map<char, char> complementMap;
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
    // the sequence attribute. It depends on complementMap attribute.
    unordered_map<char, int> count();

    // Method returns reversed complementary sequence
    string get_rev_comp();

    //Method returns the complementary sequence
    string get_complementary();
};

#endif //SEQ_H // End the conditional inclusion
