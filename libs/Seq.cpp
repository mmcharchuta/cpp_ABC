//
// Created by obiektowecpp on 29.11.24.
//

#include "Seq.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
// complementMap is created here only temporary
Seq::Seq() {
    complementMap['A'] = 'T';
    complementMap['T'] = 'A';
    complementMap['C'] = 'G';
    complementMap['G'] = 'C';
}

Seq::Seq(const string& filepath) {
    readFASTA(filepath);
};

void Seq::readFASTA(const string& filepath){
    ifstream file(filepath);
    if (!file.is_open()) {
      cerr << filepath << " cannot be opend" << endl;
      return;
    }
    string line;

    while (getline(file, line)) {
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

unordered_map<char, int> Seq::count() {
    unordered_map<char, int> charCount;

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

string Seq::get_complementary() {
    string compSeq = sequence;
    string result;
    for (int i = 0 ; i < compSeq.length(); i ++) {
        result += complementMap[compSeq[i]];
    }
    return result;
}

string Seq::get_rev_comp() {
    string Seq = get_complementary();
    reverse (Seq.begin(), Seq.end());
    return Seq;
}