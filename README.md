
# **cpp_ABC**
Joint repository for the C++ Object-Oriented Programming class at AMU.

The **cpp_ABC** project is a comprehensive collection of tools designed to solve problems from [Rosalind](https://rosalind.info/problems/) using the principles of **object-oriented programming** (OOP) in C++.

The goal of this repository is to not only solve bioinformatics problems efficiently but also to emphasize effective **software design and abstraction** using C++.

---

## **Overview**

The repository implements functionalities based on biological sequences such as **DNA**, **RNA**, and **Proteins**. It is structured around a clear class hierarchy (`Seq` as the base class), ensuring code reusability, flexibility, and maintainability. The project embraces modern C++ features (C++20) and incorporates a modular design for handling sequences effectively.

---

## **Features**

- **Class Hierarchy for Biological Sequences (Abstraction)**:
  - Base class (`Seq`) and derived classes (`DNA`, `RNA`, and `Prot`) implement core functionalities essential for handling biological sequences.
  - Ensure validation of sequences using biologically relevant rules (e.g., DNA sequences can only contain `A`, `C`, `T`, `G`).
  - Support complementary base mapping (useful for DNA and RNA).
  - Enable conversion between DNA and RNA sequences.
  - Protein functionality includes translating RNA sequences into proteins using the codon table.

- **General Capabilities**:
  - Read and validate sequences from FASTA-format files using the `readFASTA` functionality.
  - Count bases in sequences (e.g., frequency of `A`, `C`, `T`, `G` in DNA).
  - Generate complementary and reverse-complementary sequences for both DNA and RNA.
  - Translate RNA into protein using the universal genetic codon table.

---

## **Class Hierarchy**

### 1. **`seq::Seq` (Base Class)**

- The **abstract base class** for all sequence types. It defines common members and functionality for DNA, RNA, and any other biological sequence types.
- **Purpose**:
  - Provide shared properties and operations for handling sequences.
  - Enforce implementation of specific methods (`validate()` and `getCompMap()`) in derived classes.

#### **Key Features:**

- **Core Properties**:
  - `header` (protected): A title or description for the sequence, often used when reading a FASTA file.
  - `sequence` (protected): The actual biological sequence (e.g., "ACGT" for DNA).
  - `compMap` (protected): A mapping of complementary bases for DNA and RNA.

- **Main Methods**:
  - Getters and setters for `header` and `sequence`.
  - `readFASTA`: Reads a sequence and header from a FASTA file into the object.
  - `count`: Returns the frequency of each base in the sequence as a map.
  - **Pure virtual methods** (to be implemented in derived classes):
    - `validate()`: Ensures the sequence contains only valid characters for its type.
    - `getCompMap()`: Returns the complement base mapping specific to the derived class.

- **Complementary Operations**:
  - Automatically generate a **complementary sequence** or a **reverse-complementary sequence** through helper functions.
