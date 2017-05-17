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
            returnToken = new Token(string((inputString.c_str())[this->currentChar],1),LITERAL_CHAR);
        }
        else if(((inputString.c_str())[this->currentChar]>='0' && (inputString.c_str())[this->currentChar]<='9'))
        {
            cout<<"Literal number"<<endl;
            returnToken = new Token(string((inputString.c_str())[this->currentChar],1),LITERAL_NUMBER);
        }else if((inputString.c_str())[this->currentChar]=='(')
        {
            cout<<"PAr OPen"<<endl;
            returnToken = new Token("*",PUNT_OPEN_PAREN);
        }
        else if((inputString.c_str())[this->currentChar]==')')
        {
            returnToken = new Token("*",PUNT_CLOSE_PAREN);
        }
        else if((inputString.c_str())[this->currentChar]=='*')
        {
            cout<<"KLEEN"<<endl;
            returnToken = new Token("*",OP_KLEEN);
        }
        else if((inputString.c_str())[this->currentChar]=='.')
        {
            returnToken = new Token("*",PUNT_CLOSE_PAREN);
        }
        else if((inputString.c_str())[this->currentChar]=='+')
        {
            returnToken = new Token("*",PUNT_CLOSE_PAREN);
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
