#include "../header.h"

extern vector<Token *> processing;

/* Product 5 : M -> ( E ) */
void reduce_by_product5() {
    if (processing.size() < 8) {
        cerr << "Cannot apply product M -> ( E )\n";
        exit(1);
    }

    /* Pop off 6 tokens, keeping the CP, VARE,
       and OP tokens for this product */
    delete processing.back();
    processing.pop_back();
    Token *cp = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *E = processing.back();
    processing.pop_back();
    delete processing.back();
    processing.pop_back();
    Token *op = processing.back();
    processing.pop_back();

    /* Check that the tokens are of the right type
       for this product */
    if (op->type != OP || E->type != VARE || 
        cp->type != CP) {
        cerr << "Could not apply product M -> ( E )\n";
        exit(1);
    }

    Token *new_M = new Token;
    new_M->type = VARM;
    new_M->value = E->value;
    table_entry *te = get_parse_table_entry(
                    processing.back()->value,
                    VARM);
    int state = te->state;
    delete te;
    Token *new_state = new Token;
    new_state->type = STATE;
    new_state->value = state;
    processing.push_back(new_M);
    processing.push_back(new_state);

    delete op; delete E; delete cp;
    return;
}
