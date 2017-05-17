#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Lexer.h"

using namespace std;

class Parser
{
    public:
        Lexer *lexer;
        Token *currentToken;
        Parser(Lexer*);
        string parse();

        string E();
        string E_Prime(string);

        string T();
        string T_Prime(string);

        string F();
        string F_Prime(string);

        virtual ~Parser();
    protected:
    private:
};

#endif // PARSER_H
