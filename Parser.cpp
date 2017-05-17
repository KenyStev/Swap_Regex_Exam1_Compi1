#include "Parser.h"
Parser::~Parser(){}

Parser::Parser(Lexer * l)
{
    this->lexer=l;
    this->currentToken = l->getNextToken();
}

string Parser::parse()
{
    string returnVal = E();
    if(this->currentToken->type!=STMT_EOF)
    {
            cout<<"End of file expected."<<endl;
            exit(-1);
    }
    return returnVal;
}

string Parser::E()
{
    cout<<"E"<<endl;
    string reversed = this->E_Prime(this->T());
    return reversed;
}

string Parser::T()
{
    string tValue = T_Prime(F());
    return tValue;
}

string Parser::E_Prime(string param)
{
    if(currentToken->type==OP_PIPE)
    {
        currentToken = lexer->getNextToken();
        string epVal = param + "+";
        return epVal + E_Prime(T());
    }else{
        return param;
    }
}


string Parser::F()
{
    if(this->currentToken->type==PUNT_OPEN_PAREN)
    {
        currentToken = lexer->getNextToken();
        string fVal = "(" + E();

        if(this->currentToken->type!=PUNT_CLOSE_PAREN)
        {
            cout<<") expected."<<endl;
            exit(-1);
        }
        currentToken = lexer->getNextToken();
        fVal = fVal + ")";
        return F_Prime(fVal);
    }else if(this->currentToken->type==LITERAL_CHAR
    || this->currentToken->type==LITERAL_NUMBER)
    {
        string lex = currentToken->lexeme;
        cout<<"LEXEME"<<endl;
        currentToken = lexer->getNextToken();
        return F_Prime(lex);
    }else{
        cout<<"( or Litera expected."<<endl;
        exit(-1);
    }
}

string Parser::F_Prime(string param)
{
    if(currentToken->type==OP_KLEEN)
    {
        currentToken = lexer->getNextToken();
        string fPVal = param + "*";
        return F_Prime(fPVal);
    }else{
        return param;
    }
}

string Parser::T_Prime(string param)
{
    if(currentToken->type==OP_DOT)
    {
        currentToken = lexer->getNextToken();
        string tPval = T_Prime(F()) + "." + param;
        return tPval;
    }else{
        return param;
    }
}
