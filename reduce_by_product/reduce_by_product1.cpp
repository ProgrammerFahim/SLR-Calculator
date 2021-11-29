#include "../header.h"

extern vector<Token *> processing;

/* Product 1 : E -> E + T */
void reduce_by_product1() {
    if (processing.size() < 8) {
        cerr << "Cannot apply product E -> E + T\n";
        exit(1);
    }

    /* Pop off 6 tokens, keeping the VART, PLUS,
       and VARE tokens for this product */
    delete processing.back();
    processing.pop_back();
    Token *T = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *plus = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *E = processing.back();
    processing.pop_back();

    /* check if these are the valid tokens for
       this product */
    if (T->type != VART || plus->type != PLUS || 
        E->type != VARE) {
        cerr << "Could not apply product E -> E + T\n";
        exit(1);
    }

    Token *new_E = new Token;
    new_E->type = VARE;
    new_E->value = E->value + T->value;
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

    delete T; delete plus; delete E;
    return;
}
