#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	map<string,Sym*> attr;
	vector<Sym*> nest; void push(Sym*);
	virtual string head(); string pad(int);
	virtual string dump(int=0);
};

struct Int:Sym { Int(string); long val; string head(); };

struct Comment:Sym { Comment(string); };
struct Program:Sym { Program(Sym*o); };
struct Tool:Sym { Tool(Sym*); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string);
#include "ypp.tab.hpp"

#endif // _H_HPP
