
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  // why in the WORLD isn't this included by default


// Instead of Left/Right, its every three

void removeDuplicates(char* arr, size_t lenArr){
    // replaces duplicate elements with '0'
    for(int i = 0; i < lenArr; i++){
        for(int currChecking = i+1; currChecking < lenArr; currChecking++){
            if(arr[i] == arr[currChecking]){
                arr[currChecking] = '0';
            }
        }
    }
}


bool isLowercase(char c){
    return c >= 'a';
}


int main(){

    FILE *inputFile;
    inputFile = fopen("input.txt", "r");
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData = NULL;
    char *lineDataTwo = NULL;
    char *lineDataThree = NULL;

    size_t lineLength = 0;
    ssize_t numCharsRead = 0;

    ssize_t numCharsReadTwo   = 0;
    ssize_t numCharsReadThree = 0;

    int priority = 0;
    int totalPriority = 0;

    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        int  buffIndex = 0;  
        char commonItem = '\0';

        // end of file
        if(lineData[0] == '\n'){
            break;
        }

        numCharsReadTwo   = getline(&lineDataTwo, &lineLength, inputFile);
        numCharsReadThree = getline(&lineDataThree, &lineLength, inputFile);

        removeDuplicates(lineData, numCharsRead);
        removeDuplicates(lineDataTwo, numCharsReadTwo);
        removeDuplicates(lineDataThree, numCharsReadThree);

        for(int x = 0; x < numCharsRead && !commonItem; x++){
            if(lineData[x] == '0') 
                continue;

            for(int y = 0; y < numCharsReadTwo && !commonItem; y++){
                if(lineDataTwo[y] == '0') 
                    continue;

                if(lineData[x] != lineDataTwo[y]){
                    continue;
                }


                for(int z = 0; z < numCharsReadThree; z++){
                    if(lineDataThree[z] == '0') 
                        continue;

                    if(lineDataTwo[y] == lineDataThree[z]){
                        commonItem = lineDataTwo[y];
                        break;
                    }
                }


            }
        }


        printf("These Three bags had this in common: %c\n", commonItem);


        // calculate points
        // a-z: 1-26
        // A-Z: 27-52
        //
        // ASCII VALUES (decimal)
        // A: 64
        // Z: 90
        // a: 97
        // z: 122
        
        if(isLowercase(commonItem)){
           priority += commonItem - 96;
        }
        else{
            priority += commonItem - 38;
        }

        printf("Priority this round: %d\n", priority);
        totalPriority += priority;
        priority = 0;

        printf("------------------\n");

    }


    printf("Final priority sum: %d\n", totalPriority);
    printf("Done!\n");
    fclose(inputFile);
}

