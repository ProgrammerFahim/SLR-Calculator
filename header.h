#ifndef _SLR_HEADER_
#define _SLR_HEADER_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

/* Constants denoting terminals */

#define PLUS 0      /*  '+'  */
#define PROD 1      /*  '*'  */
#define OP 2        /*  '('  */
#define CP 3        /*  ')'  */
#define NUM 4       /*  num  */
#define DOL 5       /*  '$'  */

/* Constants denoting variables. The accumulated value
   these variables are in the 'value' field of token */

#define VARE 6      /*   E   */
#define VART 7      /*   T   */
#define VARM 8      /*   M   */

/* Constant denoting state. Value from 0 to 11 */

#define STATE 9

/* Structure of a token */
struct Token {
    int type;   /* One of the constants defined above */
    int value;  /* value of 'num' or the variables */
};

/* Parsing table query result */
struct table_entry {
    bool valid;         /* Is it a valid parse table entry? */
    bool shift;         /* Is it a shift operation? */
    bool reduce;        /* Is it a reduce operation? */
    bool accepted;      /* Is it the accepted state? */
    int state;          /* State to push if not reduce */
    int product;        /* Product to reduce by */
};

using namespace std;

/* Function to retrieve parse table entry for [state][op] */
table_entry *get_parse_table_entry(int state, int op);

/* Function to tokenize input string */
void tokenize_input(string input);

/* Functions to reduce using the specified product */
void reduce(int product);
void reduce_by_product1();
void reduce_by_product2();
void reduce_by_product3();
void reduce_by_product4();
void reduce_by_product5();
void reduce_by_product6();

#endif
