//
// Created by obiektowecpp on 29.11.24.
//

#include "SequenceClass.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
// complementMap is created here only temporary
Sequence::Sequence() {
    complementMap['A'] = 'T';
    complementMap['T'] = 'A';
    complementMap['C'] = 'G';
    complementMap['G'] = 'C';
}

Sequence::Sequence(const std::string& filepath) {
    readFASTA(filepath);
};

void Sequence::readFASTA(const std::string& filepath){
    std::ifstream file(filepath);
    if (!file.is_open()) {
      std::cerr << filepath << " cannot be opend" << std::endl;
      return;
    }
    std::string line;
    bool isHeader = true;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        if (isHeader && line[0] == '>') {
            header = line.substr(1);
            isHeader = false;
        } else {
            sequence += line;
        }
    }

    file.close();
}

std::string Sequence::get_reverse() {
    std::string reverseSeq = sequence;
    std::reverse (reverseSeq.begin(), reverseSeq.end());
    return reverseSeq;
    }


std::unordered_map<char, int> Sequence::count() {
    std::unordered_map<char, int> charCount;

    for (const auto& pair : complementMap) {
        charCount[pair.first] = 0;
    }

    for (const char& base : sequence) {
        if (complementMap.find(base) != complementMap.end()) {
            charCount[base]++;
        }
    }
    return charCount;
}

std::string Sequence::complementary() {
    std::string compSeq = sequence;
    for (char& base : compSeq) {
        base = complementMap[base];
    }
    return compSeq;
}

