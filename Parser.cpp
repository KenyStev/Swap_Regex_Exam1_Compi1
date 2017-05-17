#include "Parser.h"

Parser::Parser(Lexer * l)
{
    this->lexer=l;
}

string Parser::parse()
{
    this->Codigo();
}

Parser::~Parser()
{
    //dtor
}
