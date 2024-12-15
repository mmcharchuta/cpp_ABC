# cpp_ABC
Joint repository for the cpp object programming class at AMU

cpp_ABC is a comprehensive toolset for solving the entire set at  https://rosalind.info/problems
efficiently with object programming philosophy in mind;)

### **Class Hierarchy and Relationships**
1. **`seq::Seq` (Base Class)**
    - This is the **abstract base class** (since it contains pure virtual methods like `validate()` and `getCompMap()`).
    - It defines common functionality for all biological sequences, such as:
        - Storing a `header` and `sequence`.
        - Managing complementary base mappings via `compMap`.
        - Methods for reading a FASTA file, counting base occurrences, and generating complementary/reverse-complementary sequences.

#### Key Properties:
    - Protected Members:
        - `string header`: Represents the title/description of the sequence (used when reading FASTA files).
        - `string sequence`: Represents the sequence itself (e.g., "ACGT").
        - `unordered_map<char, char> compMap`: Stores mappings for complementary bases (e.g., A ↔ T in DNA, A ↔ U in RNA).

    - Public Methods:
        - Getters and setters for `header` and `sequence`.
        - `readFASTA`: Reads sequence data from a FASTA-formatted file.
        - `count`: Counts occurrences of each base in the sequence (returns a map of character counts).
        - Pure Virtual Methods (to be implemented by derived classes):
            - `validate`: Ensures the sequence contains only valid characters for its type (DNA or RNA).
            - `getCompMap`: Returns the base complement map specific to the derived sequence type.

    - Additional Utilities:
        - Generate **complementary** and **reverse-complementary** sequences using `get_comp` and `get_rev_comp`.

2. **`seq::DNA` (Derived Class from `Seq`)**
    - Inherits all properties and methods from `Seq` and implements DNA-specific functionality.
    - Complement Map:
        - In `DNA`, the complementary bases are defined as `A ↔ T` and `C ↔ G`.

    - Implements the following methods:
        - `validate`: Ensures that the sequence contains valid DNA characters (A, C, T, G).
        - `getCompMap`: Provides the complementary base pairing map for DNA.
        - `toRNA`: Converts a DNA sequence to an RNA sequence by replacing `T` with `U`.

    - Example Use:
        - You could validate a DNA sequence, convert it to RNA, and generate complementary/reverse-complementary sequences.

3. **`seq::RNA` (Derived Class from `Seq`)**
    - Similar to `DNA`, but supports RNA-specific attributes:
        - Complement Map for RNA:
            - In RNA, the complementary bases are defined as `A ↔ U` and `C ↔ G`.

    - Implements the following methods:
        - `validate`: Ensures the sequence contains valid RNA characters (A, U, C, G).
        - `getCompMap`: Provides the complementary base pairing map for RNA.

    - Example Use:
        - Validate an RNA sequence, generate its complementary sequence, or even translate it into a protein using `Prot`.

4. **`seq::Prot`**
    - **Note**: `Prot` is not directly related to `Seq` or its derived classes via inheritance but is conceptually tied to `RNA`.
    - This is a standalone class that resides in the same namespace (`seq`) for consistency.
    - Its sole responsibility is to **translate an RNA sequence** into a protein sequence using the genetic codon table.
    - Properties:
        - `codonTable`: Stores the mapping from RNA codons (3-character strings like `AUG`) to amino acids or stop codons.

    - Key Methods:
        - `translate`: Converts an RNA sequence into a protein string by processing codons one at a time.
        - `initializeCodonTable`: Initializes the codon-to-amino-acid map.
