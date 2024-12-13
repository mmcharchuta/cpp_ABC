//
// Created by obiektowecpp on 29.11.24.
//

#include "Seq.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

// complementMap is created here only temporary
Seq::Seq() {
    complementMap['A'] = 'T';
    complementMap['T'] = 'A';
    complementMap['C'] = 'G';
    complementMap['G'] = 'C';
}

Seq::Seq(const std::string& filepath) {
    readFASTA(filepath);
};

void Seq::readFASTA(const std::string& filepath){
    std::ifstream file(filepath);
    if (!file.is_open()) {
      std::cerr << filepath << " cannot be opend" << std::endl;
      return;
    }
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        if ( line[0] == '>') {
            header = line.substr(1);
        } else {
            sequence += line;
        }
    }

    file.close();
}

std::unordered_map<char, int> Seq::count() {
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

std::string Seq::get_complementary() {
    std::string compSeq = sequence;
    std::string result;
    for (int i = 0 ; i < compSeq.length(); i ++) {
        result += complementMap[compSeq[i]];
    }
    return result;
}

std::string Seq::get_rev_comp() {
    std::string Seq = get_complementary();
    std::reverse (Seq.begin(), Seq.end());
    return Seq;
}