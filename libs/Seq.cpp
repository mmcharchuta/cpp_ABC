#include "Seq.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace seq {

    Seq::Seq() : header(""), sequence("") {}

    Seq::Seq(const string& filepath) {
        readFASTA(filepath);
    }

    string Seq::getHeader() const {
        return header;
    }

    Seq* Seq::setHeader(string newHeader) {
        header = newHeader;
        return this;
   }

    string Seq::getSequence() const {
        return sequence;
    }

    Seq* Seq::setSequence(string newSequence) {
        sequence = newSequence;
        return this;
    }

    void Seq::readFASTA(const string& filepath) {
        ifstream file(filepath);
        if (!file.is_open()) {
            cerr << filepath << " cannot be opened" << endl;
            return;
        }
        string line;

        while (getline(file, line)) {
            if (line.empty()) continue;

            if (line[0] == '>') {
                header = line.substr(1);
            } else {
                sequence += line;
            }
        }

        file.close();
    }

    unordered_map<char, int> Seq::count() {
        unordered_map<char, int> charCount;
        for (char base : sequence) {
            charCount[base]++;
        }
        for (const auto& pair : compMap) {
            if (charCount.find(pair.first) == charCount.end()) {
                charCount[pair.first] = 0;
            }
        }
        return charCount;
    }

    string Seq::get_comp() {
        unordered_map<char, char> compMap = getCompMap();
        string result;
        for (char base : sequence) {
            result += compMap[base];
        }
        return result;
    }

    string Seq::get_rev_comp() {
        string compSeq = get_comp();
        reverse(compSeq.begin(), compSeq.end());
        return compSeq;
    }

} // namespace seq
