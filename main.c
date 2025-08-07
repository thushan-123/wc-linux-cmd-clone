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

    bool show_word = false;
    bool show_line = false;
    bool show_char = false;

    if (argc > 2) {
        if (argv[2][0] == '-') {
            for (int i = 1; argv[2][i] != '\0'; i++) {
                switch(argv[2][i]) {
                    case 'w': show_word = true; break;
                    case 'l': show_line = true; break;
                    case 'c': show_char = true; break;
                    default:
                        fprintf(stderr, "Unknown option: -%c\n", argv[2][i]);
                        return 1;
                }
            }
        }
    } else {
        // If no flag is provided, show all
        show_word = show_line = show_char = true;
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