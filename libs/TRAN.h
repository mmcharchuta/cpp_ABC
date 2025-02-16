#ifndef TRAN_H
#define TRAN_H

#include "HAMM.h"
#include "SPLC.h"

using namespace std;

namespace seq {
    class TRAN : public virtual HAMM, public virtual SPLC {
    public:
        TRAN();  

        bool validate() const override;  
        unordered_map<char, char> getCompMap() const override;  


        pair<int, int> calculateTransitionTransversion(const string& otherSequence);

        bool isTransition(char a, char b) const;
        bool isTransversion(char a, char b) const;
        void calculateRatio(const string& seq1, const string& seq2, const string& seq3, const string& seq4);
    };
}

#endif 
