#include "Lexer.h"

Lexer::Lexer(string input)
{
    this->inputString = input;
}

Token* Lexer::getNextToken()
{
    if(this->currentChar < this->inputString.size())
    {
        while((inputString.c_str())[this->currentChar]==' '
        || (inputString.c_str())[this->currentChar]=='\t'
        || (inputString.c_str())[this->currentChar]=='\r'
        || (inputString.c_str())[this->currentChar]=='\n')
            this->currentChar++;

        Token *returnToken = NULL;


        if(((inputString.c_str())[this->currentChar]>='a' && (inputString.c_str())[this->currentChar]<='z')
            || ((inputString.c_str())[this->currentChar]>='A' && (inputString.c_str())[this->currentChar]<='Z'))
        {
            cout<<"Literal char"<<endl;
            string lex = inputString.substr(currentChar,1);
            returnToken = new Token(lex,LITERAL_CHAR);
        }
        else if(((inputString.c_str())[this->currentChar]>='0' && (inputString.c_str())[this->currentChar]<='9'))
        {
            cout<<"Literal number"<<endl;
            string lex = inputString.substr(currentChar,1);
            returnToken = new Token(lex,LITERAL_NUMBER);
        }else if((inputString.c_str())[this->currentChar]=='(')
        {
            cout<<"Paren Open"<<endl;
            returnToken = new Token("(",PUNT_OPEN_PAREN);
        }
        else if((inputString.c_str())[this->currentChar]==')')
        {
            cout<<"Paren Close"<<endl;
            returnToken = new Token(")",PUNT_CLOSE_PAREN);
        }
        else if((inputString.c_str())[this->currentChar]=='*')
        {
            cout<<"KLEEN"<<endl;
            returnToken = new Token("*",OP_KLEEN);
        }
        else if((inputString.c_str())[this->currentChar]=='.')
        {
            cout<<"DOT"<<endl;
            returnToken = new Token(".",OP_DOT);
        }
        else if((inputString.c_str())[this->currentChar]=='+')
        {
            cout<<"PIPE"<<endl;
            returnToken = new Token("*",OP_PIPE);
        }
        else{
            cout<<"Symbol not suported!"<<endl;
            exit(-1);
        }

        this->currentChar++;
        return returnToken;
    }
    return new Token("\0",STMT_EOF);
}

Lexer::~Lexer()
{
    //dtor
}
