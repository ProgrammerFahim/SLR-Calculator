#include "header.h"

/* Main stack for processing input */
vector<Token *> processing;

/* Input token stream defined */
vector<Token *> input_token_stream;

/* Release memory before exit */
void cleanup() {
    for (Token *t : processing)
        delete t;
    for (Token *t : input_token_stream)
        delete t;
}

/*****************************************************
 *
 *  Main function
 *
 ****************************************************/

int main(void) {
    atexit(cleanup);

    /* REPL */
    while (true) {

        /* Prepare for next iteration */
        cleanup();
        processing.clear();
        input_token_stream.clear();

        /* Perform initial setup */
        Token *begin = new Token;
        begin->type = DOL;
        Token *begin_state = new Token;
        begin_state->type = STATE;
        begin_state->value = 0;
        processing.push_back(begin);
        processing.push_back(begin_state);

        /* Take an expression */
        cout << "Enter an expression: ";
        string expr;
        getline(cin, expr);
        if (expr == "")
            continue;

        /* Initialize input_token_stream */
        tokenize_input(expr);


        /* Expression evaluation loop */
        int index = 0;
        while (true) {
            table_entry *te = get_parse_table_entry(
                                processing.back()->value,
                                input_token_stream[index]->type);
            if (!te->valid) {
                cerr << "Invalid parse table entry" << endl;
                delete te;
                exit(1);
            }

            /* To shift, push the current look ahead,
               advance it, and push the shift state */
            if (te->shift) {
                Token *add = new Token;
                add->type = input_token_stream[index]->type;
                add->value = input_token_stream[index]->value;
                processing.push_back(add);
                Token *new_state = new Token;
                new_state->type = STATE;
                new_state->value = te->state;
                processing.push_back(new_state);
                index++;
            }

            else if (te->reduce) {
                reduce(te->product);
            }

            /* Success: pop last state and print value
               of the expression */
            else if (te->accepted) {
                delete processing.back();
                processing.pop_back();
                cout << "Value of expression: " 
                     << processing.back()->value << endl;

                delete te;
                break;
            }

            delete te;
        }
    }
}
