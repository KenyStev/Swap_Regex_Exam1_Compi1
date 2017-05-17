#include "Token.h"

Token::Token(string lex, TokenType t)
{
    this->lexeme = lex;
    this->type = t;
//    cout<<"lxe:   -> "<<lexeme<<end;
}

Token::~Token()
{
    //dtor
}
