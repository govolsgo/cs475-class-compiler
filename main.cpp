// Class Tokenizer (Driver)
// main.cpp
// Carter Crews
// 2017
// For CS475 Sp2017 at UTM.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include "lex.yy.cc"

using namespace std;

int symbolTableLoc(string key, string value);
void printSymbolTable();

vector<string> symbolTable;

extern int yylex();

int main()
{
  ifstream input;
  string file;

  // Get the file to parse and open it.
  cout << "Enter file to parse: ";
  cin >> file;
  input.open(file);

  cout << "*** Tokenized Results ***" << endl;

  // Create a lexer, pass the file to it and output the results to the screen.
  FlexLexer* lexer = new yyFlexLexer(&input,&cout);
  lexer->yylex();

  // After we've printed the tokens, print the symbol table.
  printSymbolTable();
  
  return 0;
}

int symbolTableLoc(string key, string value)
{
  vector<string>::iterator itKey;
  vector<string>::iterator itVal;

  // Find the first matching key in the vector.
  itKey = find(symbolTable.begin(), symbolTable.end(), key);

  // Assuming we found something...
  while(itKey != symbolTable.end())
    {
      itVal = itKey + 1;

      // Check that the following value matches as well.
      if(*itVal == value)
	{
	  // Return location in symbol table.
	  return (distance(symbolTable.begin(), itKey) / 2) + 1;
	}
      // Otherwise try again.
      else
	{
	  itKey++;
	  itKey = find(itKey, symbolTable.end(), key);
	}
    }

  // If it's not found, add it.
  symbolTable.push_back(key);
  symbolTable.push_back(value);

  return (symbolTable.size() / 2);
}

void printSymbolTable()
{
  cout << "\n";
  cout << "*** Symbol Table ***" << endl;
  
  for(int i=0; i < symbolTable.size(); i+=2)
      cout << i/2+1 << ',' << symbolTable[i] << ',' << symbolTable[i+1] << endl;
  
  return;
}
