#include "header.h"

/*****************************************************
 *
 *  Reduce Implementation
 *
 *  These are the following products:
 *      1: E -> E + T
 *      2: E -> T
 *      3: T -> T * M
 *      4: T -> M
 *      5: M -> ( E )
 *      6: M -> num
 *
 ****************************************************/

extern vector<Token *> processing;

void reduce(int product) {
    switch (product) {
        case 1:
            reduce_by_product1();
            break;
        case 2:
            reduce_by_product2();
            break;
        case 3:
            reduce_by_product3();
            break;
        case 4:
            reduce_by_product4();
            break;
        case 5:
            reduce_by_product5();
            break;
        case 6:
            reduce_by_product6();
            break;
    }
}
