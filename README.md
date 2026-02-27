# Lexical Analyzer for C

A lexical analyzer (lexer/tokenizer) for the C programming language, built from scratch in C.

## What is a Lexical Analyzer?

A **lexical analyzer** is the first phase of a compiler or interpreter. It reads the source code as a stream of characters and converts it into meaningful sequences called **tokens**. Each token represents a logical unit such as a keyword, identifier, operator, or literal.

For example, the statement `int x = 5;` would be broken down into:
- `int` → KEYWORD
- `x` → IDENTIFIER
- `=` → OPERATOR
- `5` → CONSTANT
- `;` → PUNCTUATOR

This process is essential for parsing and compiling code, as it transforms raw text into a structured format that subsequent compiler phases can process.

## Features Implemented

### Token Types Recognized

| Token Type | Description | Examples |
|------------|-------------|----------|
| **KEYWORD** | C language reserved words | `int`, `return`, `if`, `while`, `for`, `struct` |
| **IDENTIFIER** | Variable and function names | `myVar`, `calculateSum`, `_temp` |
| **CONSTANT** | Numeric literals and character literals | `42`, `3.14`, `'a'` |
| **STRING** | String literals | `"Hello, World!"` |
| **OPERATOR** | Arithmetic, logical, and assignment operators | `+`, `==`, `&&`, `->`, `>>=` |
| **PUNCTUATOR** | Delimiters and separators | `;`, `{`, `}`, `(`, `)`, `,` |

### Supported C Keywords (31 total)
```
char    int     float   double  void    short   long    signed  unsigned
sizeof  return  goto    typedef if      else    switch  case    default
for     while   do      continue auto   register static extern  const
volatile struct union   enum
```

### Supported Operators

| Category | Operators |
|----------|-----------|
| **Arithmetic** | `+`, `-`, `*`, `/`, `%` |
| **Assignment** | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `\|=`, `^=` |
| **Comparison** | `==`, `!=`, `>`, `<`, `>=`, `<=` |
| **Logical** | `&&`, `\|\|`, `!` |
| **Bitwise** | `&`, `\|`, `^`, `~`, `>>`, `<<`, `>>=`, `<<=` |
| **Increment/Decrement** | `++`, `--` |
| **Pointer** | `->` |

### Additional Features
- ✅ Single-line comment handling (`//`)
- ✅ Multi-line comment handling (`/* */`)
- ✅ Preprocessor directive skipping (`#include`, `#define`, etc.)
- ✅ Whitespace handling (spaces, tabs, newlines)
- ✅ Directory processing (analyze all files in a folder)
- ✅ Multiple file processing via command-line arguments

## Dependencies

- **GCC** (GNU Compiler Collection)
- **Make** (Build automation tool)


## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Gasimhacker/Lexical_Analyzer.git
   cd Lexical_Analyzer
   ```

2. **Build the lexer:**
   ```bash
   make
   ```

   This compiles the source files in `src/` and creates the `lexer` executable.

3. **To rebuild from scratch:**
   ```bash
   make re
   ```

4. **To clean up (remove executable):**
   ```bash
   make clean
   ```

## Usage

### Running Directly

```bash
./lexer <file_or_directory> [more paths...]
```

**Analyze a single file:**
```bash
./lexer tests/simple_declaration
```

**Analyze multiple files:**
```bash
./lexer tests/simple_declaration tests/mini_program tests/loops
```

**Analyze all files in a directory:**
```bash
./lexer tests
```

**Interactive mode (no arguments):**
```bash
./lexer
```
When run without arguments, it displays usage information and prompts whether to process the `tests` directory.

### Using `make run`

The Makefile includes a `run` target for convenience. Use the `TARGET` variable to specify what to analyze.

**Analyze a single file:**
```bash
make run TARGET=tests/simple_declaration
```

**Analyze a directory:**
```bash
make run TARGET=tests
```

**Without TARGET (interactive mode):**
```bash
make run
```
This displays usage examples and then runs the lexer without arguments, prompting you to process the `tests` directory:
```
Usage: make run TARGET=<file_or_directory>
Example: make run TARGET=tests/simple_declaration
Example: make run TARGET=tests

Running the lexer without arguments

Usage: ./lexer <file_or_directory> [more paths...]
If a directory is provided, all files will be processed.
No file or directory specified.
Process files in the test directory? (Y/N):
```

## Example

### Input File (`tests/mini_program`)
```c
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
```

### Output
```
-------------------------------------------------------------------
Processing path: tests/mini_program
Path is a regular file. Processing the file.
'int' : KEYWORD
'max' : IDENTIFIER
'(' : PUNCTUATOR
'int' : KEYWORD
'a' : IDENTIFIER
',' : PUNCTUATOR
'int' : KEYWORD
'b' : IDENTIFIER
')' : PUNCTUATOR
'{' : PUNCTUATOR
'if' : KEYWORD
'(' : PUNCTUATOR
'a' : IDENTIFIER
'>': OPERATOR
'b' : IDENTIFIER
')' : PUNCTUATOR
'return' : KEYWORD
'a' : IDENTIFIER
';' : PUNCTUATOR
'else' : KEYWORD
'return' : KEYWORD
'b' : IDENTIFIER
';' : PUNCTUATOR
'}' : PUNCTUATOR
```

## Project Structure

```
Lexical_Analyzer/
├── Makefile                 # Build configuration
├── README.md                # This file
├── src/
│   ├── lexer.h              # Header file with declarations
│   ├── main.c               # Entry point
│   ├── lexer.c              # Main lexer function
│   ├── check_lexemes.c      # Keyword and punctuator checking
│   ├── check_operators.c    # Operator validation
│   ├── process_token.c      # Token processing logic
│   ├── process_path.c       # File/directory handling
│   ├── read_file.c          # File reading utilities
│   ├── read_lexemes.c       # Identifier, number, string reading
│   └── skip_spaces_and_comments.c  # Whitespace/comment handling
└── tests/                   # Test files with various C code patterns
    ├── simple_declaration
    ├── mini_program
    ├── loops
    ├── control_flow
    └── ... (30 test cases)
```

## Try It with Your Own C File

1. Create a C source file (e.g., `mycode.c`):
   ```c
   int main() {
       int sum = 0;
       for (int i = 0; i < 10; i++) {
           sum += i;
       }
       return sum;
   }
   ```

2. Run the lexer:
   ```bash
   ./lexer mycode.c
   ```
   Or:
   ```bash
   make run TARGET=mycode.c
   ```

3. See the tokenized output!

## License

This project is open source and available under the MIT License.

## Author

[Gasimhacker](https://github.com/Gasimhacker)
