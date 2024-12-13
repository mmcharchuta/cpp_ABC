#ifndef SEQ_H
#define SEQ_H

#include <string>
#include <unordered_map>
using namespace std;

namespace seq {
    class Seq {
    protected:
        string header;
        string sequence;
        unordered_map<char, char> compMap;  // compMap is declared here, but not initialized

    public:
        string getHeader() const;
        Seq* setHeader(string newHeader);
        string getSequence() const;
        Seq* setSequence(string newSequence);

        Seq();
        Seq(const string& filepath);

        virtual bool validate() const = 0;
        virtual unordered_map<char, char> getCompMap() const = 0;

        void readFASTA(const string& filepath);
        unordered_map<char, int> count();
        string get_rev_comp();
        string get_comp();
    };
}

#endif // SEQ_H
