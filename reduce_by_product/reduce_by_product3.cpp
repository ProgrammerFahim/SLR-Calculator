#include "../header.h"

extern vector<Token *> processing;

/* Product 3 : T -> T * M */
void reduce_by_product3() {
    if (processing.size() < 8) {
        cerr << "Cannot apply product T -> T * M\n";
        exit(1);
    }

    /* Pop off 6 tokens, keeping the VARM, PROD,
       and VART tokens for this product */
    delete processing.back();
    processing.pop_back();
    Token *M = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *prod = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *T = processing.back();
    processing.pop_back();

    /* Check if the tokens are of the right type
       for this product */
    if(M->type != VARM || prod->type != PROD || 
       T->type != VART) {
        cerr << "Could not apply product T -> T * M\n";
        exit(1);
    }

    Token *new_T = new Token;
    new_T->type = VART;
    new_T->value = T->value * M->value;
    table_entry *te = get_parse_table_entry(
                    processing.back()->value,
                    VART);
    int state = te->state;
    delete te;
    Token *new_state = new Token;
    new_state->type = STATE;
    new_state->value = state;
    processing.push_back(new_T);
    processing.push_back(new_state);

    delete M; delete prod; delete T;
    return;
}
