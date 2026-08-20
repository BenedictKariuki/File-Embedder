/* embed.c */

#include "embed.h"


void usage(char* arg){
    fprintf(stderr, "Usage: %s [-h | --help | -a] <identifier>\n", $c arg);
    exit(-1);
}

void printheader(char* identifier, language lang){
    switch(lang){
        case ASM:
            printf("%s:\n", identifier);
            break;
        case C:
            printf("unsigned char %s[] = \n", identifier);
            break;
    }
}

int main(int argc, char* argv[]){
    language lang = C;
    char* identifier = NULL;
    if(argc == 2){
        identifier = $c argv[1];
    }
    else if(argc > 2){
        if(!strcmp($c argv[1], "--help")
                || (!strcmp($c argv[1], "-h")))
            usage($c argv[0]);
        else if(argc == 3){
                if(!strcmp($c argv[1], $c "-a")){
                    lang = ASM;
                    identifier = $c argv[2];
            }
        }
        else
            usage($c argv[0]);

    }
    else
        usage($c argv[0]);

    printheader(identifier, lang);

    return 0;
}
