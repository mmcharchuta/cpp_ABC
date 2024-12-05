//
// Created by obiektowecpp on 29.11.24.
//

#ifndef SEQUENCECLASS_H
#define SEQUENCECLASS_H
#include <string>
#include <unordered_map>

class Sequence {
protected:
    std::unordered_map<char, char> complementMap;
public:
    std::string header;
    std::string sequence;

    Sequence();
    Sequence(const std::string& filepath);

    // Method reads single sequence and its header from FASTA file
    void readFASTA(const std::string& filepath);

    // Method returns an unordered map, where the key is the character, and the value is the count of its occurrences in
    // the sequence attribute. It depends on complementMap attribute.
    std::unordered_map<char, int> count();

    // Method returns reversed sequence
    std::string get_reverse();

    //Method returns the complementary sequence
    std::string complementary();

    //Method replaces the current sequence with a new one (after getting_reverse/complementary)
    void change_to(const std::string& new_sequence);

};

#endif //SEQUENCECLASS_H

//