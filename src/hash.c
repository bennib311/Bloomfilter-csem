// Create hashes for different words
#include <stdlib.h>
#include <stdio.h>

#include "../include/hash.h"

#define FNV_OFFSET 14695981039346656037u
#define FNV_PRIME 1099511628211u


unsigned int hash_func(int i, const char *word) {
    unsigned int *item = (unsigned int*)(&word);

    switch (i)
    {
    case 0:     //hash_function 0 Division method
        hash = *item % 10u;
        return hash;
        
        break;

    case 1:     //hash_function 1 FNV-1a hash_function
        // https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
        hash = FNV_OFFSET;
        for (const char *p = word; *p; p++) {
            hash ^= (unsigned char)(*p);
            hash *= FNV_PRIME;
        }
        return hash;
        break;

    default:
        break;
    }
}