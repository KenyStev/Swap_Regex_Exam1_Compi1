#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser
{
    public:
        Lexer *lexer;
        Parser(Lexer*);
        string parse();
        virtual ~Parser();
    protected:
    private:
};

#endif // PARSER_H
