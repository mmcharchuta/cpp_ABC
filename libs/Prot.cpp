#include "Prot.h"

namespace seq {
    // Initialize the codon table.
    void Prot::initializeCodonTable() {
        codonTable = {
            {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
            {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
            {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
            {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
            {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
            {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
            {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
            {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
            {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", '\0'}, {"UAG", '\0'},
            {"UGA", '\0'}, {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'},
            {"CAG", 'Q'}, {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'},
            {"AAG", 'K'}, {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'},
            {"GAG", 'E'}, {"UGU", 'C'}, {"UGC", 'C'}, {"UGG", 'W'},
            {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
            {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
            {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
        };
    }

    // Constructor that initializes the codon table.
    Prot::Prot() {
        initializeCodonTable();
    }

    // Translate RNA into a protein string.
    std::string Prot::translate(const std::string& rna) {
        std::string protein = "";
        for (size_t i = 0; i < rna.size(); i += 3) {
            std::string codon = rna.substr(i, 3);
            if (codonTable[codon] == '\0') // Stop codon
                break;
            protein += codonTable[codon];
        }
        return protein;
    }
}