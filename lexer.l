%{
// Flex Tokenizer
// Carter Crews
// 2017
// For CS475 Sp2017 at UTM.

#include <iostream>
using namespace std;

int symbolTableLoc(string key, string value);
void printSymbolTable();

%}
%option noyywrap 
%%
int				{cout << "<INT>";}
float				{cout << "<FLOAT>";}
[0-9]+\.[0-9]+			{cout << "<REAL," << symbolTableLoc("REAL",yytext) << ">";}
[0-9]+				{cout << "<INTEGER," << symbolTableLoc("INTEGER",yytext) << ">";}
\[				{cout << "<LSQB>";}
\]				{cout << "<RSQB>";}
=				{cout << "<EQUAL,=>";}
\t				{cout << "<TAB>";}
\n				{cout << "<NL>\n";}
(<=|!=|>=|==|<|>)		{cout << "<COMPARISON," << yytext << ">";}
(\+=|\-=|\*=|\/=)		{cout << "<COMBO," << yytext << ">";}
[*/+-]				{cout << "<OP," << yytext << ">";}
\(				{cout << "<LPAREN>";}
\)				{cout << "<RPAREN>";}
\{				{cout << "<LCURL>";}
\}				{cout << "<RCURL>";}
if				{cout << "<IF>";}
[a-zA-Z0-9_]+			{cout << "<ID," << symbolTableLoc("ID",yytext) << ">";}
[[:blank:]]			{}
%%
