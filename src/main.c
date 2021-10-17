#include <stdlib.h>
#include <stdio.h>

#include "../include/bloomfilter.h"
#include "../include/hash.h"


int main(){
    add_word("Test");

    if (check_word("Test") == 1) {
        printf("Vielleicht enthalten!\n");
    } else {
        printf("Nicht enthalten!\n");
    }



    return 0;
}

