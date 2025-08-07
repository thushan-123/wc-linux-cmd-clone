#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


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
        file = fopen(argv[1], "r");
        if(file == NULL){
            fprintf(stderr,"word counter cant open : %s", argv[1]);
            return 1;
        }
    }

    while((c =getc(file)) != EOF){
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

    if (argc >2){
        if (strcmp(argv[2], "-w") == 0) {
            printf("%7d", word);
            
        } else if (strcmp(argv[2], "-l") == 0) {
            printf("%7d", lines);
        } else if (strcmp(argv[2], "-c") == 0) {
            printf("%7d", characters);
        }
        
    }else{
        printf("%7d/lines  %7d/words  %7d/chars" , lines, word , characters);
    }

    // show the ouput
    //printf("%7d  %7d  %7d" , lines, word , characters);
    if(argc >1){
        printf(" %s",argv[1]);
    }
    printf("\n");

    if(file != stdin){
        fclose(file);
    }
    return 0;
}