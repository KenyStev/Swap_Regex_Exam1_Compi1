#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
    Lexer *l = new Lexer(" ( 0 + 1 ) . 1 *");
//    Token *t = l.getNextToken();
//    while(t->type!=STMT_EOF)
//        t = l.getNextToken();

    Parser *regexs = new Parser(l);
    cout<<regexs->parse()<<endl;
    return 0;
}
