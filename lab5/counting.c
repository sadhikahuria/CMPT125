// CMPT 125 SUMMER 2024
// Author: Sadhika Huria
// USER ID: 301599274
// Lab 5 counting.c

#include <stdio.h>
#include <stdlib.h>

int ifchar(int character){

    int yeschar = 0;

    const int capital_letter_start = 65;
    const int capital_letter_end = 90;

    const int lowerletter_start = 97;
    const int lowerletter_end = 122;

    const int apostrope = 39;

    if ((character >= capital_letter_start)&& (character <= capital_letter_end)){
        yeschar = 1;
    }

    if((character >= lowerletter_start)&& (character <= lowerletter_end)){
        yeschar = 1;
    }

    if (character == apostrope){
        yeschar = 1;
    }

    
    return yeschar;
}


int main(){
    
    unsigned long charCount = 0;
    unsigned long wordCount = 0;
    unsigned long lineCount = 0;
    int input;
    int previous;
    int newline = 10;

    while((input = getchar()) != EOF){

        //scenorio 1 starting of a word
        if ((ifchar(previous) == 0) && (ifchar(input) == 1)){
            wordCount++;
            charCount++;
        }

        //scenorio 2 middle of reading a word
        if ((ifchar(previous) == 1) && ifchar(input) == 1){
            charCount++;
        }

        //scenorio 3 end of a word
        if ((ifchar(previous) == 1) && (ifchar(input) == 0)){
            wordCount++;
        }

        //scenorio 4 double charcters that are not a word
        // do nothing

        //counting lines
        if (input == newline){
            lineCount++;
        }
        previous = input;

    }

    wordCount = (wordCount/2); //becuase the count happens twice, when starting the word and when ending the word
    printf( "\n%lu %lu %lu\n", charCount, wordCount, lineCount );

}