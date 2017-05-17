#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "TokenType.h"

using namespace std;

class Token
{
    public:
        string lexeme;
        TokenType type;
        Token(string,TokenType);
        virtual ~Token();
    protected:
    private:
};

#endif // TOKEN_H
