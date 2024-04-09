#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(0));
    int gameLoop = 1;
    int myWins = 0;
    int compsWins = 0;
    int yourPick;
    int compsPick;
    char yourPickChar;
    char compsPickChar;
    char Picks[3] = {'r', 'p', 's'};
    while (gameLoop < 6) {
        printf("Round %d\n", gameLoop);
        printf("Enter r for ROCK, p for PAPER, and s for SCISSORS\n");
        scanf(" %c", &yourPickChar);
        if (yourPickChar == 'r') {
            yourPick = 0;
        }
        else if (yourPickChar == 'p') {
            yourPick = 1;
        }
        else {
            yourPick = 2;
        }
        compsPick = rand() % 3;
        compsPickChar = Picks[compsPick];
        printf("\nComputer picked %c against your %c\n", compsPickChar, yourPickChar);
        if (yourPick == 0 && compsPick == 2){
            myWins++;
        }
        else if (yourPick == 2 && compsPick == 0){
            compsWins++;
        }
        else {
            if (yourPick > compsPick){
                myWins++;
            }
            else if(yourPick<compsPick){
                compsWins++;
            }
        }
        printf("My wins %d vs comps wins %d\n", myWins, compsWins);
        gameLoop++;
    }
    return 0;
}