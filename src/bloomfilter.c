// Add words to the Filter and check if a certain word is inside the list
#include <stdlib.h>
#include <stdio.h>

#include "../include/bloomfilter.h"
#include "../include/hash.h"

void set_bit(unsigned b) {
    bitfield[b / 8] |= 1u << b % 8;
}

int test_bit(unsigned b) {
    return bitfield[b / 8] & (1u << b % 8);
}

void add_word(const char *word) {
    unsigned int h;
    for (int i = 0; i < MAX_HASH_FUNCTIONS; i++) {
        h = hash_func(i, word) % NUMBER_OF_BITS;
        set_bit(h);
    }
}

int check_word(const char * word) {
    unsigned int h;
    for (int i = 0; i < MAX_HASH_FUNCTIONS; i++) {
        h = hash_func(i, word) % NUMBER_OF_BITS;
        if (!test_bit(h)) return 0;
    }
    return 1;
}