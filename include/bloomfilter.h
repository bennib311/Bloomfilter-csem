#ifndef _BLOOMFILTER_H_
#define _BLOOMFILTER_H_

#define MAX_HASH_FUNCTIONS      2
#define NUMBER_OF_BYTES         65536u
#define NUMBER_OF_BITS          (NUMBER_OF_BYTES / 8u)


unsigned char bitfield[NUMBER_OF_BYTES];

void set_bit(unsigned b);
int test_bit(unsigned b);
void add_word(const char *word);
int check_word(const char * word);

#endif