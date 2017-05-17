#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
//#include <string.h>

#include "Token.h"

using namespace std;

class Lexer
{
    public:
        int currentChar = 0;
        string inputString;
        Lexer(string);
        Token* getNextToken();
        virtual ~Lexer();
    protected:
    private:
};

#endif // LEXER_H
