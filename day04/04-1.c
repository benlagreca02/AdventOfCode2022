#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){


    FILE *inputFile;
    // inputFile = fopen("inputSimple.txt", "r");
    inputFile = fopen("input.txt", "r");
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData = NULL;
    size_t lineLength = 0;
    ssize_t numCharsRead = 0;

    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        if(lineData[0] == '\n'){
            break;
        }

        // Data always in format 
        // [NUMBER]-[NUMBER],[NUMBER]-[NUMBER]

        int range1Min, range1Max, range2Min, range2Max;
        char *firstDash  = strchr(lineData, '-') + 1;  // point to the digit after the - 
        char *comma = strchr(lineData, ',') + 1;
        char *secondDash = strchr(comma, '-') + 1; 
 
        // the finding includes the sepration characters, this negates that
        size_t range1MinLength = firstDash - lineData - 1;
        size_t range1MaxLength = comma - firstDash - 1;
        size_t range2MinLength = secondDash - comma - 1;
        size_t range2MaxLength = strlen(secondDash) - 1;


        // Cases:
        // No overlap
        // Perfec overlap L&R are the same
        // First hangs over left and Second hangs over right
        // opposite
        // First completely overlapps second
        // second overlaps first


    }


    fclose(inputFile);

}
