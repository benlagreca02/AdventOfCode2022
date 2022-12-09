
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>  // why in the WORLD isn't this included by default


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
    inputFile = fopen("inputSimple.txt", "r");
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData = NULL;
    size_t lineLength = 0;
    ssize_t numCharsRead = 0;

    int itemsPerCompartment;
    char *left;
    char *right;

    int priority = 0;
    int totalPriority = 0;

    char duplicateBuff[32];  // ambig. number thats just big
    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        int  buffIndex = 0; 
    
        // end of file
        if(lineData[0] == '\n'){
            break;
        }

        itemsPerCompartment = numCharsRead/2;

        left  = (char*) malloc(itemsPerCompartment);
        right = (char*) malloc(itemsPerCompartment);

        // fill left and right arrays
        for(int i = 0; i < itemsPerCompartment; i++){
            left[i] = lineData[i];
            right[i] = lineData[i + itemsPerCompartment];
        }

        removeDuplicates(left,  itemsPerCompartment);
        removeDuplicates(right, itemsPerCompartment);

        // Do L/R comparison, if left and right contain identical values, add to buffer
        for(int i = 0; i < itemsPerCompartment; i++){
            if(left[i] == '0') 
                continue;

            for(int j = 0; j < itemsPerCompartment; j++){
                if(right[j] == '0') 
                    continue;
                if(left[i] == right[j]){
                    duplicateBuff[buffIndex] = left[i];
                    buffIndex++;
                }
            }
        }

        free(left);
        free(right);


        printf("This bag had these in common: \n");
        for(int i = 0; i < buffIndex; i++){
            printf("%c", duplicateBuff[i]);
        }
        printf("\n");


        // calculate points
        // a-z: 1-26
        // A-Z: 27-52
        //
        // ASCII VALUES (decimal)
        // A: 64
        // Z: 90
        // a: 97
        // z: 122

        for(int i = 0; i < buffIndex; i++){
            char currChar = duplicateBuff[i];
            if(isLowercase(currChar)){
               priority += currChar - 96;
            }
            else{
                priority += currChar - 38;
            }
        }

        totalPriority += priority;
        printf("Priority this round: %d\n", priority);
        priority = 0;

        printf("------------------\n");

    }


    printf("Final priority sum: %d\n", totalPriority);
    printf("Done!\n");
}

