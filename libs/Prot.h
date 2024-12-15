#ifndef PROT_H
#define PROT_H

#include <unordered_map>
#include <string>

namespace seq {
    class Prot {
    private:
        std::unordered_map<std::string, char> codonTable; // Store codon-to-amino acid mappings.

        void initializeCodonTable(); // Initialize the codon table.

    public:
        Prot(); // Constructor that initializes the codon table.
        std::string translate(const std::string& rna); // Translate RNA into a protein string.
    };
}

#endif // PROT_H