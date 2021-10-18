// Add words to the Filter and check if a certain word is inside the list
#include <stdlib.h>
#include <stdio.h>

#include "../include/bloomfilter.h"
#include "../include/hash.h"

// Nach: https://www.heise.de/ix/artikel/Planten-un-Bloomen-506867.html
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

int main(){
    int i;
    int mode = 0;
    int array_size = 12;
    
    char word_list[][16] = {  "Test", "Tag", "Haus", "Morgen", "Sonne", "Samstag",
                              "Blume", "Filter", "gelb", "grün", "schwarz", "rot" };


    //add_word_list to filter
    for (i = 0; i < array_size; i++) {
        add_word(word_list[i]);
    }

    while (mode < 5) {
        
        if (mode == 0){
            char *test_word;
            printf("Geben Sie ein Wort zum überpfüfen ein:\n");
            test_word = "";
            scanf("%16s", test_word);
            
            if (check_word(test_word) == 1) {
                printf("Vielleicht enthalten!\n");
            } else {
                printf("Nicht enthalten!\n");
            } 
        } 
    }

    return 0;
}
