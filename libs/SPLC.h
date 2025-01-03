#ifndef SPLC_H
#define SPLC_H

#include "DNA.h"
#include "Prot.h"
#include "SUBS.h"

using namespace std;

namespace seq {

    class SPLC : public virtual DNA, public virtual Prot, public virtual SUBS {
    public:
        SPLC();  

        void setSequence(const string& sequence);  
        bool validate() const override;          
        unordered_map<char, char> getCompMap() const override;  

        
        string spliceAndTranslate(const vector<string>& introns);
    };
}

#endif 
