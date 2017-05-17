#include "Token.h"

Token::Token(string lex, TokenType t)
{
    this->lexeme = lex;
    this->type = t;
    cout<<"lxe:   -> "<<this->lexeme<<endl;
}

Token::~Token()
{
    //dtor
}
