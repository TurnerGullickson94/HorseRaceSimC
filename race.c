
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Prototypes.h"


// REMEMBER THIS IF YOU ARE READING THIS CODE!
// STATS[0] IS YOUR CURRENT CASH
// STATS[1] IS YOUR CHOSEN HORSE
// STATS[2] IS THE BET YOU PLACE ON THE HORSE
// STATS[3] IS THE ODDS OF YOUR BET SUCCEEDING
// STATS[4] IS YOUR CASH AFTER A RACE
// keep these in mind they come up alot

int main()
{
	int odds[10];
	int player1[5]; 
	int player2[5];
	int position[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int count;
	int winner;
    int choice;
	char raceAgain;
    char human[50], human2[50];
    char computer[50];
	
	// okay lets make this array with your money in the first thingy, horse in the second, bet in the third, the odds of your bet in the fourth, and your current cash in the last one
	
    //this is to give the user some general knowledge before they start the program
    printf("This is a simulation of a horse race with betting included. You will be asked your name then how much money you start with. Then you will be shown the odds of the horses chance to win. From there you can choose which horse to choose and how much to bet on it. You cannot win more than $1000000 and you cannot bet more than what you have. There is a maximum and minimum of two people betting against eachother\n\n\n\n");
    
    //this try block is so that if the user enters a number that is not specified, the program will exit

    //this is so if youre lonely you can bet against a computer that randomly generates all of the variables
        printf("If you would like to play against a computer hit 1 and if you have another player hit 2\n");
        scanf("%d", &choice);
    //this way it calls the function so the computer can randomly generate stuff, but the human still does everything as if wer in the normal player vs player situation
        if (choice==1)
        {
            printf("What is the your first name player 1?\n");
            scanf("%s",human);
        

            moneyAmount(player1, human);
            strcpy(human2,computer);
            moneyAmountComputer(player2, human2);
        }
    
    //this is just player vs player and goes on the same perameters for both
        if (choice==2)
        {
            printf("What is the your first name player 1?\n");
            scanf("%s",human);
    
            printf("What is the your first name player 2?\n");
            scanf("%s",human2);
            moneyAmount(player1, human);
            moneyAmount(player2, human2);
        }
    
        //if the input does not match the perameters it will throw choice and the program will exit
        if((choice<1)||(choice>2)){
            printf("invalid players. exiting");
            exit(1);
        }

    //here we use a do-while loop so that the user(s) can choose to bet again or not. if they choose to continue, their current amount of money with their losses or winnings is stored and they continue with that amount.
	do
	{
        // this is the first for loop. this one here is the one that determines the money made after the race. can't win more than 1000000 becasue cmon that's a lot. the "10" is the number of horses
		for (count = 0; count < 10; count++)
			position[count] = 0;
		winner = 1000000;
		oddsOfWinning(odds, 10);
		oddsPerHorse(odds);
		bet(player1, human, odds);
		oddsPerHorse(odds);
         if(choice==1)
               betComputer(player2, human2, odds);
           else
               bet(player2, human2, odds);
		
		do
		{
			for (count = 0; count < 10; count++)
			{
				position[count] += run(odds, count);
				if (position[count] >= 50)
					winner = count;
				 //this is the distance type function and how fast each horse will run
				
			}
			// this part is the one that actually determines the winner. that 50 thing is just to keep the race moving smoothly and not for too long.
			theRace(position);
		} while (winner == 1000000);
		printf("\nThe winning horse is horse " +winner + 1);
        printf("\n");
        
        //this calls to the computer so it cab randomly generate stuff but the human can choose theirself
        if(choice==1)
        {
            player1[0] += payoff(winner, player1, human);
            player2[0] += payoffComputer(winner, player2, human2);
        }
        
        //both people do the same thing
        if(choice==2)
        {
            player1[0] += payoff(winner, player1, human);
            player2[0] += payoff(winner, player2, human2);
        }

        //automatically quits if one player is no longer able to bet more money
		if ((player1[0] <= 0) || (player2[0] <= 0))
        {
            printf("Sorry one, or both of you has reached $0 and can no longer bet, time to exit. Thanks for playing!\n");
			raceAgain = 'n';
        }
        // gives choice for another race if both players still have money
		else
		{
			printf("\n race again? (Y/N)\n");
			scanf("%c",&raceAgain);
		}
	}
    while ((raceAgain == 'Y') || (raceAgain == 'y'));
	// gives choice for another race

    // tells whos the winner (see function) but if the computer is playing it computes it different so we have a different function
    if (choice==1){
        whoWinsComputer(player1, player2, human, human2);
    }
    if (choice==2){
        whoWins(player1, player2, human, human2);
    }
	
	return 0;
}