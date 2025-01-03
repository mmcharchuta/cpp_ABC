#include "Prot.h"

using namespace std; // Allow direct use of standard library components (e.g., string, unordered_map, cout).

namespace seq {

    // Initialize the codon table
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

    // Constructor
    Prot::Prot() : Seq() { // Call the base class constructor
        initializeCodonTable();
    }

    // Translate RNA to protein
    string Prot::translate(const string& rna) {
        string protein = "";
        for (size_t i = 0; i < rna.size(); i += 3) {
            string codon = rna.substr(i, 3);
            if (codonTable[codon] == '\0') // Stop codon
                break;
            protein += codonTable[codon];
        }
        return protein;
    }

    // Validate the protein sequence (ensure all characters are valid amino acids)
    bool Prot::validate() const {
        for (char c : sequence) {
            bool found = false;
            for (auto& pair : codonTable) {
                if (pair.second == c) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }

    // Override getCompMap (Proteins have no complementary mapping)
    unordered_map<char, char> Prot::getCompMap() const {
        return {}; // Return an empty map since proteins lack complementarity
    }
}
