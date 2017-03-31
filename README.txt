Class Compiler Tokenizer Assignment
Carter Crews

Running the tokenizer:
1. Navigate to the directory containing the lexer.
2. bash$ make
3. bash$ ./classTokenizer
4. Provide input file. A sample file, testCode.ccl, is included.

Most of this code is the same from programming assignment 2. I was able to split the file into a lexer file and driver file. I also added code to the lexer to parse ! as the end of a statement, like ; is in C++.
