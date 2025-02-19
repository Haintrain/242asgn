#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include "htable.h"


int main(int argc, char* argv[]) {
    char *filename;
    hashing_t hashing_method = LINEAR_P;
    int table_size = 113;

    bool e_flag = false;
    bool p_flag = false;
    bool s_flag = false;
    bool h_flag = false;

    char option;
    char* optstring = "c:deps:t:h";
    while((option = getopt(argc, argv, optstring)) != EOF) {
        switch(option) {
            case 'c':
                filename = optarg;
            case 'd':
                hashing_method = DOUBLE_H;
            case 'e':
                /*Display hash table on stderr*/
                e_flag = true;
            case 'p': 
                /*Print stats instead of printing freqs & words*/
                p_flag = true;
            case 's':
                /*Display up to the given value of stats snapshots*/
                s_flag = true;
            case 't':
                table_size = atoi(optarg);
            default: 
                printf("Unknown input: -%c %s", option, optarg);
                return 1;
        }
    }

    htable h = htable_new(table_size, hashing_method);
    char word[256];
    while(getword(word, sizeof(word), stdin) != EOF) {
        htable_insert(h, word);
    }


}