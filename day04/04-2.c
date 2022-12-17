#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool between(int left, int center, int right){
    return left <= center && center <= right;
}


int doesOneContainOther(int min1, int max1, int min2, int max2){
    
    // No Overlap
    if( max1 < min2 || max2 < min1){
        return 0;
    }
    // Perfect Overlap
    else if( max1 == max2 && min1 == min2){
        return 1;
    }
    // One contains two completely
    else if(between(min1, min2, max1) && between(min1, max2, max1)){
        return 1;
    }
    // two contains one completely
    else if(between(min2, min1, max2) && between(min2, max1, max2)){
        return 1;
    }
    else{
        return 1;
    }
}



int main(){


    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData = NULL;
    size_t lineLength = 0;
    ssize_t numCharsRead = 0;

    int numContains = 0;
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

        // atoi() stops trying to cast when it hits a character it can't cast
        // in our case, this makes life very easy
        range1Min = atoi(lineData);
        range1Max = atoi(firstDash);
        range2Min = atoi(comma);
        range2Max = atoi(secondDash);



        numContains += doesOneContainOther(range1Min, range1Max, range2Min, range2Max);
    }

    printf("Answer: %d\n", numContains);

    fclose(inputFile);

}
