/*Program written by Annalise Dake 10/20/2016
mp2.4
this program plays the dice game 'pig' using player input*/

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool isGameScoreLost(int die1value, int die2value);       //prototype for checking if the game score is lost
bool isTurnScoreLost(int die1value, int die2value);		//prototype for checking if the turn score is lost
int rolldie(void);								//prototype for rolling the dice
char getUserInput(void);						//prototype for getting user input

const int SCORE_LIMIT = 100;					//the score limit that ends the game
const string DASH = "---------------------\n";  //devider between turns for readability

int main(void) {


	srand(time(0));               //seeds the dice function
	int die1value = rolldie();		  //first die
	int die2value = rolldie();		  //second die
	int turnScore = 0;			  //the total of dice for one turn
	int totalGameScore = 0;		  //total game score for the player
	int totalGameScoreComp = 0;	  //total game score for the computer
	char input = 'r';


	while (totalGameScore <= SCORE_LIMIT && totalGameScoreComp <= SCORE_LIMIT){       //while loop that goes until the player or the computer reaches 100
		turnScore = 0;
		while (input == 'r'){														  //while loop gets the input and checks whether it's an r or an s
			cout << "Enter r to roll dice, or s to stop turn ";
			cin >> input;                        
			cout << endl << DASH;

			if (input == 's') {
				totalGameScore += turnScore;
				cout << "Total score = " << totalGameScore;
				break;
			}
			die1value = rolldie();
			die2value = rolldie();

			if (isTurnScoreLost(die1value, die2value) == true){								 //checks if a 1 has been rolled
				turnScore = 0;
				cout << "You rolled a " << die1value << " and a " << die2value << "." << endl << "Turn Score Lost!" << endl << DASH;
				break;
			}

			else{																	//if a 1 hasn't been rolled, this adds your turn score
				turnScore = (turnScore + (die1value + die2value));
				cout << "You rolled a " << die1value << " and a " << die2value << "." << endl;
				cout << "Turn Score = " << turnScore << endl;
				continue;
			}

			if (isGameScoreLost(die1value, die2value) == true){								//checks if both dice rolled 1, if so sets the score back to zero
				totalGameScore = 0;  
				cout << "Game Score Lost!" << endl << DASH;
				break;
			}


		}	//end of player while loop
			if (totalGameScore >= SCORE_LIMIT){
				cout << "\nPlayer wins!\n";
			return 0;
		}	//end of if statment (checks if player has won)
		
		cout << endl << DASH;		//devider

		//computer loop starts here
		turnScore = 0;
		input = 'r';
		while (input = 'r'){
		if (turnScore >= 21){
				totalGameScoreComp += turnScore;
				cout << "Total score = " << totalGameScoreComp << endl << DASH;
				break;
			}

		else
				input = 'r';

			die1value = rolldie();
			die2value = rolldie();

		if (isTurnScoreLost(die1value, die2value) == true){
				turnScore = 0;
				cout << "The computer rolled a " << die1value << " and a " << die2value << "." << endl << "Turn Score Lost!" << endl << DASH;
				break;
			}
		else {
				turnScore = (turnScore + (die1value + die2value));
				cout << "The computer rolled a " << die1value << " and a " << die2value << "." << endl;
				cout << "Turn Score = " << turnScore << endl << DASH;
			}

		if (isGameScoreLost(die1value, die2value) == true){
				totalGameScoreComp = 0;
				cout << "Game Score Lost!" << endl << DASH;
				break;

			}	//end of if 
		}	//end of computer while loop
	}	//end of entire while loop	
	if (totalGameScoreComp >= SCORE_LIMIT){
		cout << "\nComputer Wins!\n";
		return 0;
	}	//end of if statemen that checks if the computer has won
}	//end of main


bool isTurnScoreLost(int die1value, int die2value) {								/*function to decide whether the turn
																					score is lost based on if a 1 was rolled */
	if ((die1value == 1 & die2value != 1) || (die1value != 1 && die2value == 1))
		return true;
	else
		return false;

}

bool isGameScoreLost(int die1value, int die2value) {								/*function to decide wether the game score is
																					lost based on if both numbers rolled were 1*/
	if (die1value == 1 && die2value == 1)
		return true;
	else
		return false;

}

int rolldie(void) {														/*this function rolls the dice*/
	int ran;
	ran = rand() % 6 + 1;
	return ran;
}

char getUserInput(void) {												//gets input from user
	char input = 'r';
	if ((input == 'r') || (input == 's'))
		return true;
	else
		return false;

}


