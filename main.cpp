#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
    Lexer *l = new Lexer("(0+1).1*.(a+b).((c+d)*.f.(r+e))");
    Parser *regexs = new Parser(l);
    cout<<regexs->parse()<<endl;
    return 0;
}
