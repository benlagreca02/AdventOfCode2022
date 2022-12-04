#define _GNU_SOURCE  // for getline function
#include <stdio.h>
#include <stdlib.h>

// Given a list of grouped numbers, find the group with the largest sum

int main(){


    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    // I'm a good noodle!
    if(inputFile == NULL)
    {
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData;
    size_t lineLength = 0;
    ssize_t numCharsRead;


    int currentGroupSum = 0;
    int currentGroupNumber = 0;
    int largestGroupSize = 0;
    int largestGroupIndex = 0;

    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        // We hit a new group! Groups are sep. by a blank line
        if(lineData[0] == '\n'){
            printf("Found a new group!\n");
            if(currentGroupSum > largestGroupSize){
                largestGroupSize  = currentGroupSum;
                largestGroupIndex = currentGroupNumber;
            }

            currentGroupSum = 0;
            currentGroupNumber++;
            continue;
        }
        currentGroupSum += atoi(lineData); 
    }

    fclose(inputFile);

    printf("Biggest group: %d\n", largestGroupSize);
    printf("Group Number: %d\n", largestGroupIndex);

}
