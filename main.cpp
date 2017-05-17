#include <iostream>
#include "Lexer.h"

using namespace std;

int main()
{
    Lexer l(" ( 0 + 1 ) . 1 *");
    Token *t = l.getNextToken();
    while(t->type!=STMT_EOF)
        t = l.getNextToken();
    return 0;
}
