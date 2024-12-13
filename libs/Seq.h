//
// Created by obiektowecpp on 29.11.24.
//

#ifndef SEQ_H
#define SEQU_H
#include <string>
#include <unordered_map>

class Seq {
protected:
    std::unordered_map<char, char> complementMap;
public:
    std::string header;
    std::string sequence;
    //std::validate();
    //indexOf(Seq, s); Seq("AGG")
    //indexOf(string s); "ACCCG";
    //toDNA();
    //toRNA();

    Seq();
    Seq(const std::string& filepath);

    // Method reads single sequence and its header from FASTA file
    void readFASTA(const std::string& filepath);

    // Method returns an unordered map, where the key is the character, and the value is the count of its occurrences in
    // the sequence attribute. It depends on complementMap attribute.
    std::unordered_map<char, int> count();

    // Method returns reversed complementary sequence
    std::string get_rev_comp();

    //Method returns the complementary sequence
    std::string get_complementary();
};

#endif //SEQ_H
