#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }
Sym::Sym(string V):Sym("sym",V){}
void Sym::push(Sym*o) { nest.push_back(o); }

string Sym::head() { return "<"+tag+":"+val+">"; }
string Sym::pad(int n) { string S; for (int i=0;i<n;i++) S += '\t'; return S; }
string Sym::dump(int depth) { string S = "\n"+pad(depth)+head();
	for (auto it=attr.begin(),e=attr.end();it!=e;it++)
		S += "\n"+pad(depth+1)+ it->first + " = " + it->second->head();
	for (auto it=nest.begin(),e=nest.end();it!=e;it++)
		S += (*it)->dump(depth+1);
	return S; }

Int::Int(string V):Sym("int",V) { val = atoi(V.c_str()); }
string Int::head() { ostringstream os; os<<val; return os.str(); }

Comment::Comment(string V):Sym("comment",V){}

Program::Program(Sym*o):Sym("program","O") { attr["index"] = o; }

Tool::Tool(Sym*o):Sym("tool","T") { attr["index"] = o; }

