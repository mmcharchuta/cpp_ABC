#include "Seq.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

string Seq::getHeader() const {
    return header;
}

string Seq::getSequence() const {
    return sequence;
}

// compMap is created here only temporary
Seq::Seq() {
    compMap['A'] = 'T';
    compMap['T'] = 'A';
    compMap['C'] = 'G';
    compMap['G'] = 'C';
}

Seq::Seq(const string& filepath) {
    readFASTA(filepath);
};

void Seq::readFASTA(const string& filepath){
    ifstream file(filepath);
    if (!file.is_open()) {
      cerr << filepath << " cannot be opened" << endl;
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

    for (const auto& pair : compMap) {
        charCount[pair.first] = 0;
    }

    for (const char& base : sequence) {
        if (compMap.find(base) != compMap.end()) {
            charCount[base]++;
        }
    }
    return charCount;
}

string Seq::get_comp() {
    string compSeq = sequence;
    string result;
    for (int i = 0 ; i < compSeq.length(); i ++) {
        result += compMap[compSeq[i]];
    }
    return result;
}

string Seq::get_rev_comp() {
    string Seq = get_comp();
    reverse (Seq.begin(), Seq.end());
    return Seq;
}