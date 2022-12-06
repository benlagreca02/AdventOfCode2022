#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

// Plays:
// A/X: Rock
// B/Y: Paper
// C/Z: Scissors
#define MY_ROCK  'X'
#define MY_PAPER 'Y'
#define MY_SCISS 'Z'

#define OPP_ROCK  'A' 
#define OPP_PAPER 'B'
#define OPP_SCISS 'C'

// Scores:
// Shape you select:
//   rock: 1
//   papr: 2
//   scis: 3

#define ROCK_PTS 1
#define PAPER_PTS 2
#define SCISS_PTS 3

#define MY_PLAY_INDEX 2
#define OPPONENT_PLAY_INDEX 0

// Round Result:
//   loss: 0
//   tie:  3
//   win:  6
#define LOSS_PTS 0
#define TIE_PTS 3
#define WIN_PTS 6

int main(){

    FILE *inputFile;

    inputFile = fopen("input.txt", "r");

    // I'm a good noodle!
    if(inputFile == NULL){
        printf("Couldn't open file!\n");
        return -1;
    }

    char *lineData = NULL;
    size_t lineLength = 0;
    ssize_t numCharsRead;

    int totalPoints = 0;
    int points = 0;
    int roundNum;
    // on each line
    while ((numCharsRead = getline(&lineData, &lineLength, inputFile)) != -1){
        points = 0;
        if(lineData[0] == '\n'){
            // end of file
            break;
        }
        
        roundNum++;
        char myPlay = lineData[MY_PLAY_INDEX];
        char oppPlay = lineData[OPPONENT_PLAY_INDEX];

        // data is predictable
        switch(myPlay){
            case MY_ROCK:
                points += ROCK_PTS;

                if(oppPlay == OPP_ROCK){
                    points += TIE_PTS;
                }
                else if(oppPlay == OPP_PAPER){
                    points += LOSS_PTS;
                }
                else if(oppPlay == OPP_SCISS){
                    points += WIN_PTS;
                }

                break;

            case MY_PAPER:
                points += PAPER_PTS;

                if(oppPlay == OPP_ROCK){
                    points += WIN_PTS;
                }
                else if(oppPlay == OPP_PAPER){
                    points += TIE_PTS;
                }
                else if(oppPlay == OPP_SCISS){
                    points += LOSS_PTS;
                }
                break;

            case MY_SCISS: 
                points += SCISS_PTS;

                if(oppPlay == OPP_ROCK){
                    points += LOSS_PTS;
                }
                else if(oppPlay == OPP_PAPER){
                    points += WIN_PTS;
                }
                else if(oppPlay == OPP_SCISS){
                    points += TIE_PTS;
                }
                break;
        }
 
        printf("Round %d, I Played: %c, opp played %c Points: %d\n", roundNum, myPlay, oppPlay, points);
        totalPoints += points;
        
    }

    fclose(inputFile);
    printf("total points: %d\n", totalPoints);

}
