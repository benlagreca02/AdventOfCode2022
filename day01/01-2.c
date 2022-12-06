#define _GNU_SOURCE  // for getline function
#include <stdio.h>
#include <stdlib.h>

// Given a list of grouped numbers, find the top three groups

struct node{
    int value;
    struct node *next;
};

int main(){

    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    // I'm a good noodle!
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData;
    size_t lineLength = 0;
    ssize_t numCharsRead;

    int currentGroupSum = 0;
    int currentGroupNumber = 0;

    struct node *headLinkedList = (struct node*) malloc(sizeof(struct node));
    int linkedListLength = 0;

    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        // We hit a new group! Groups are sep. by a blank line
        if(lineData[0] == '\n'){            
            
            struct node *newNode = (struct node*) malloc(sizeof(struct node));
            newNode->value = currentGroupSum;

            newNode->next = headLinkedList;
            headLinkedList = newNode;

            currentGroupSum = 0;
            currentGroupNumber++;
            continue;
        }
        currentGroupSum += atoi(lineData); 
    }

    // this assumes the linked list has a length of at least 3

    int biggest = headLinkedList->value;
    int secondBiggest = headLinkedList->next->value;
    int thirdBiggest = headLinkedList->next->next->value;


    while(headLinkedList->next != NULL){
        printf("checking %d\n", headLinkedList->value);
        // if its a new biggest
        if(headLinkedList->value > biggest){
            thirdBiggest = secondBiggest;
            secondBiggest = biggest;
            biggest = headLinkedList->value;

        }
        else if(headLinkedList->value > secondBiggest){
            thirdBiggest = secondBiggest;
            secondBiggest = headLinkedList->value;
        }
        else if(headLinkedList->value > thirdBiggest){
            thirdBiggest = headLinkedList->value;
        }

        headLinkedList = headLinkedList->next;

    }
    printf("Done!\n");
    

    printf("1: %d\n", biggest);
    printf("2: %d\n", secondBiggest);
    printf("3: %d\n", thirdBiggest);

    printf("Sum: %d\n", biggest + secondBiggest + thirdBiggest);


    fclose(inputFile);

}

