#include "../header.h"

extern vector<Token *> processing;

/* Product 4 : T -> M */
void reduce_by_product4() {
    if (processing.size() < 4) {
        cerr << "Cannot apply product T -> M\n";
        exit(1);
    }

    /* Pop off 2 tokens, keeping the VARM token
       for this product */
    delete processing.back();
    processing.pop_back();
    Token *M = processing.back();
    processing.pop_back();

    /* Check if the token is of the right type
       for this product */
    if (M->type != VARM) {
        cerr << "Could not apply product T -> M\n";
        exit(1);
    }

    Token *new_T = new Token;
    new_T->type = VART;
    new_T->value = M->value;
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

    delete M;
    return;
}
