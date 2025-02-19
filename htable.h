#ifndef HTABLE_H_
#define HTABLE_H_

#include <stdio.h>
typedef enum hashing_e { LINEAR_P, DOUBLE_H } hashing_t; //Use Linear Probing or Double Hashing
typedef struct htablerec *htable;
extern void htable_free(htable h);
extern int htable_insert(htable h, char *str);
extern htable htable_new(int capacity, hashing_t h_type);
extern void htable_print(htable h, FILE *stream);
extern int htable_search(htable h, char *str);
static unsigned int htable_word_to_int(char* str);
static unsigned int htable_step(htable h, unsigned int i_key);
#endif