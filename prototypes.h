
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//we decided to not use a class and just use a bunch of functions instead
//all of these functions are named so it is easy to get the idea of what they are doing by just looking at their name.
    void menu();
    void oddsOfWinning(int odds[], int size);
    void moneyAmount(int stats[], char human[]);
    void moneyAmountComputer(int stats[], char human[]);
    void bet(int stats[], char human[], int odds[]);
    void betComputer(int stats[], char human[], int odds[]);
    void oddsPerHorse(int odds[]);
    int run(int odds[], int horse);
    int payoff(int winner, int player[], char human[]);
    int payoffComputer(int winner, int player[], char human[]);
    void theRace(int positions[]);
    void whoWins(int player1[], int player2[], char human[], char otherHuman[]);
    void whoWinsComputer(int player1[], int player2[], char human[], char otherHuman[]);