#ifndef PROT_H
#define PROT_H

#include "Seq.h" // Inherit from Seq for a consistent hierarchy.
#include <unordered_map>
#include <string>

namespace seq {
    class Prot : public virtual Seq { // Inherit from Seq
    private:
        std::unordered_map<std::string, char> codonTable; // Codon-to-amino acid mapping


        void initializeCodonTable(); // Initialize the codon table


    public:
        Prot();// Constructor to initialize the codon table

        string translate(const string& rna);// Translate RNA into a protein sequence
        bool validate() const override; // Override to validate protein sequences
        unordered_map<char, char> getCompMap() const override; // Not applicable, return empty
    };
}

#endif // PROT_H
