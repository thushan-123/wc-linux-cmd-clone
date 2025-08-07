#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main (int argc, char *argv[]) {

    FILE *file;

    int c;
    int lines = 0;
    int word = 0;
    int characters = 0;

    int word_in = 0 ;  // boolen vlue

    if(argc <2){
        file = stdin;
    }else{
        file = fopen(argv[1], 'r');
    }
    return 0;
}