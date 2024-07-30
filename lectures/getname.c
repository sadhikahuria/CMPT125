// memory allocation and free memory

#include <stdio.h>


/*
int main(){

    const unsigned int ARRAYSIZE = 2;
    int grades[ARRAYSIZE];

    //automatic variables - memory is automatically allocated
    
    return 0;
}*/

char *getname (int maxlen){

    char *line = malloc(maxlen * sizeof(char));

    if (line == NULL){
        perror("failed allocation");
        exit(1);
    }

    printf("Please enter your name: ");

    if ( fgets( line, maxlen, stdin) == NULL) {
        perror(" failed to read a name");
        exit(1);
    }
    
    return line;
}

int main(){

    const unsigned int SIZE = 1024;
    char *name = getname(SIZE);

    printf("Your name is %s\n", name);
    
    free(name);

    name = NULL;

    return 0;
}

// valgrind ./excutable