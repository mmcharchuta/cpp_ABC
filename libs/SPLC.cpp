#include "SPLC.h"

using namespace std;

namespace seq {

    SPLC::SPLC() : Prot(), SUBS() {}


    bool SPLC::validate() const {
        return DNA::validate(); //DNA's validation logic
    }

    unordered_map<char, char> SPLC::getCompMap() const {
    return {};  
    }//Not used
    

    //to splice introns and translate exons into a protein string
    string SPLC::spliceAndTranslate(const vector<string>& introns) {
        string exonSequence = getSequence();  

      
        for (const string& intron : introns) {
            vector<int> positions = findMotif(intron);  // Locate all intron positions (from SUBS)
            for (int pos : positions) {
                
                size_t index = exonSequence.find(intron);
                while (index != string::npos) {
                    exonSequence.erase(index, intron.length()); // Remove the intron
                    index = exonSequence.find(intron);
                }
            }
        }

        
        setSequence(exonSequence);  //cleaned exon sequence
        string rnaSequence = toRNA();  // DNA to RNA conversion (from DNA)

        
        return translate(rnaSequence); //RNA to Protein translation (from Prot)
    }
}
