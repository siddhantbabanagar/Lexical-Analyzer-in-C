# Lexical-Analyzer-in-C
Lexical Analyzer in C to identify tokens like keywords, identifiers, operators, and constants

## 📌 Overview
This project is a **Lexical Analyzer (Tokenizer)** implemented in C that processes a C source file and breaks it into meaningful tokens such as **keywords, identifiers, operators, and constants**.

It demonstrates the **first phase of a compiler design**, providing insight into how programming languages are interpreted internally.

---

## 🎯 Key Features
- ✅ Identifies **C Keywords** (32 predefined keywords)
- ✅ Detects **Identifiers**
- ✅ Recognizes **Operators** (`+`, `-`, `*`, `/`, etc.)
- ✅ Classifies **Integer & Floating Constants**
- ✅ Handles **Separators & Special Characters**
- ✅ Simple and efficient implementation using core C concepts

---

## ⚙️ How It Works
1. Reads a C source file (`code.c`) character by character  
2. Group characters into tokens using a buffer  
3. Classifies tokens using custom functions:
   - `isKeyword()`
   - `isOperator()`
   - `isSeparator()`
   - `isDigit()`
   - `isFloat()`  
4. Displays the token type in a structured format  

---

## 🧠 Technical Concepts Used
- Lexical Analysis (Compiler Design Basics)
- Tokenization
- File Handling in C (`fopen`, `fgetc`)
- String Manipulation (`strcmp`)
- Character Handling (`ctype.h`)
- Modular Programming

---

## 🛠️ Tech Stack
- **Language:** C  
- **Libraries Used:**  
  - `stdio.h`  
  - `ctype.h`  
  - `string.h`  
  - `stdlib.h`  

---

## ▶️ How to Run

### Step 1: Compile the Code
```bash
gcc main.c
