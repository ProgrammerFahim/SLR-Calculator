#include "../header.h"

extern vector<Token *> processing;

/* Product 6 : M -> num */
void reduce_by_product6() {
    if (processing.size() < 4) {
        cerr << "Cannot apply product M -> num\n";
        exit(1);
    }

    /* Pop off 2 tokens, keeping the NUM token
       for this product */
    delete processing.back();
    processing.pop_back();
    Token *num = processing.back();
    processing.pop_back();

    /* Check the token is of the right type */
    if (num->type != NUM) {
        cerr << "Could not apply product M -> num\n";
        exit(1);
    }

    Token *new_M = new Token;
    new_M->type = VARM;
    new_M->value = num->value;
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

    delete num;
    return;
}
