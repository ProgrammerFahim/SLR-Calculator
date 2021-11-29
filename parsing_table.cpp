#include "header.h"

/*****************************************************
 *
 *  SLR(1) Parsing Table and helper functions
 *
 ****************************************************/

/* Initialize SLR(1) parsing table */
string parse_table[12][9] = {
    {"", "", "S4", "", "S5", "", "1", "2", "3"},
    {"S6", "", "", "", "", "ACCEPT", "", "", ""},
    {"R2", "S10", "", "R2", "", "R2", "", "", ""},
    {"R4", "R4", "", "R4", "", "R4", "", "", ""},
    {"", "", "S4", "", "S5", "", "7", "2", "3"},
    {"R6", "R6", "", "R6", "", "R6", "", "", ""},
    {"", "", "S4", "", "S5", "", "", "8", "3"},
    {"S6", "", "", "S9", "", "", "", "", ""},
    {"R1", "S10", "", "R1", "", "R1", "", "", ""},
    {"R5", "R5", "", "R5", "", "R5", "", "", ""},
    {"", "", "S4", "", "S5", "", "", "", "11"},
    {"R3", "R3", "", "R3", "", "R3", "", "", ""}
};

/* Parse-table entry getter function */
table_entry *get_parse_table_entry(int state, int op) {
    string entry = parse_table[state][op];

    table_entry *result = new table_entry;
    if (entry == "") {
        result->valid = false;
        return result;
    }

    result->valid = true;
    if (entry[0] == 'S') { result->shift = true;
        result->reduce = false;
        result->state = stoi(entry.substr(1, entry.length() - 1));
        return result;
    }

    if (entry[0] == 'R') {
        result->shift = false;
        result->reduce = true;
        result->product = stoi(entry.substr(1, entry.length() - 1));
        return result;
    }

    if (entry == "ACCEPT") {
        result->shift = false;
        result->reduce = false;
        result->accepted = true;
        return result;
    }

    result->shift = false;
    result->reduce = false;
    result->state = stoi(entry);
    return result;
}
