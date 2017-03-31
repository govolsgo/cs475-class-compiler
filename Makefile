all:
	flex++ lexer.l
	g++ main.cpp -o classTokenizer
clean:
	rm lex.yy.cc
	rm classTokenizer
