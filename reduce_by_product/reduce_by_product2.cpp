#include "../header.h"

extern vector<Token *> processing;

/* Product 2 : E -> T */
void reduce_by_product2() {
    if (processing.size() < 4) {
        cerr << "Cannot apply product E -> T\n";
        exit(1);
    }

    /* Pop off 2 tokens, keeping the VART token
       for this product */
    delete processing.back();
    processing.pop_back();
    Token *T = processing.back();
    processing.pop_back();

    /* Check if this is the correct token for
       this product */
    if (T->type != VART) {
        cerr << "Could not apply product E -> T\n";
        exit(1);
    }

    Token *new_E = new Token;
    new_E->type = VARE;
    new_E->value = T->value;
    table_entry *te = get_parse_table_entry(
                    processing.back()->value,
                    VARE);
    int state = te->state;
    delete te;
    Token *new_state = new Token;
    new_state->type = STATE;
    new_state->value = state;
    processing.push_back(new_E);
    processing.push_back(new_state);

    delete T;
    return;
}
