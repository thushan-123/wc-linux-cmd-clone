#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int main (int argc, char *argv[]) {

    FILE *file;

    int c;
    int lines = 0;
    int word = 0;
    int characters = 0;

    int word_in = false ;  // boolen vlue

    if(argc <2){
        file = stdin;
    }else{
        file = fopen(argv[1], 'r');
        if(file == NULL){
            fprintf(stderr,"word counter cant open : %s", argv[1]);
            return 1;
        }
    }

    while((c =get(file)) != EOF){
        characters++;
        
        if(c == '\n'){
            lines++;
        }
        if(isspace(c)){
            word_in = false ;
        }else if (! word_in){
            word_in =true ;
            word++;
        }
    }
    return 0;
}