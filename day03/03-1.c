
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>



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
    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        // end of file
        if(lineData[0] == '\n'){
            break;
        }

        itemsPerCompartment = numCharsRead/2;
        printf("lineLength: %zu\n", numCharsRead);
        printf("Items per compartment: %zu\n", itemsPerCompartment);
        printf("Line data: %s\n", lineData);

        left  = (char*) malloc(itemsPerCompartment);
        right = (char*) malloc(itemsPerCompartment);

        for(int i = 0; i < itemsPerCompartment; i++){
            left[i] = lineData[i];
            right[i] = lineData[i + itemsPerCompartment];
        }
        printf("left:  %s\n", left);
        printf("right: %s\n", right);
        printf("---------------------------------\n");

        free(lineData);
        free(left);
        free(right);
        lineData = NULL;
    }


    printf("Done!\n");
}
