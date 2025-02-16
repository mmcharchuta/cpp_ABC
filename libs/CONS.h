//
// Created by obiektowecpp on 14.02.25.
//

#ifndef CONS_H
#define CONS_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

namespace seq {
    class Cons {
    private:
        unordered_map<char, vector<int>> matrix;
        void clearMatrixIfNeeded();
    public:
        Cons();

        unordered_map<char, vector<int>> getProfileMatrix();

        unordered_map<char, vector<int>> profileMatrix(vector<string>& samples);
        string consensusString();
        string consensusString(vector<string>& samples);

    };

}
#endif //CONS_H
