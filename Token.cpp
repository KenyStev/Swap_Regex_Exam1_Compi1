#include "Token.h"

Token::Token(string lex, TokenType t)
{
    this->lexeme = lex;
    this->type = t;
}

Token::~Token()
{
    //dtor
}
