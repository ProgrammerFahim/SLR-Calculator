#include "header.h"

/*****************************************************
 *
 *  Tokenizing input stream
 *
 ****************************************************/


/* Input token stream */
extern vector<Token *> input_token_stream;

/* Tokenizer */
void tokenize_input(string input) {
    input.erase(remove(input.begin(), input.end(), ' '), 
                input.end());

    for (int i = 0; i < input.length(); i++) {
        switch(input[i]) {
            case '+':
               { 
                   Token *plus = new Token;
                   plus->type = PLUS;
                   input_token_stream.push_back(plus);
                   break;
                }
            case '*':
                {
                    Token *prod = new Token;
                    prod->type = PROD;
                    input_token_stream.push_back(prod); 
                    break;
                }
            case '(':
                {
                    Token *op = new Token;
                    op->type = OP;
                    input_token_stream.push_back(op);
                    break;
                }
            case ')':
                {
                    Token *cp = new Token;
                    cp->type = CP;
                    input_token_stream.push_back(cp);
                    break;
                }
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
            case '8': case '9':
                {
                    Token *num = new Token;
                    num->type = NUM;

                    /* If type is NUM, extract full number */
                    int value = input[i] - '0';
                    while(isdigit(input[i + 1]))
                        value = 10*value + (input[++i] - '0');

                    num->value = value;
                    input_token_stream.push_back(num);
                    break;
                }
            default:
                cerr << "Sorry, unrecognized token " << input[i] << endl;
                exit(1); 
        } 
    }

    /* Add a DOL (dollar) token at the end */
    Token *end = new Token;
    end->type = DOL;
    input_token_stream.push_back(end);
    return;
}
