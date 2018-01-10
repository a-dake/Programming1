#include <iostream>
#include <ctime>
#include <string>

using namespace std;

bool isGameScoreLost(int die1, int die2);       //prototype for checking if the game score is lost
bool isTurnScoreLost(int die1, int die2);		//prototype for checking if the turn score is lost
int rolldie(void);								//prototype for rolling the dice
char getUserInput(void);

const int SCORE_LIMIT = 100;					//the score limit that ends the game
const string DASH = "---------------------\n";  //devider between turns for readability

int main(void) {


	srand(time(0));               //seeds the dice function
	int die1 = rolldie();		  //first die
	int die2 = rolldie();		  //second die
	int turnScore = 0;			  //the total of dice for one turn
	int totalGameScore = 0;		  //total game score for the player
	int totalGameScoreComp = 0;	  //total game score for the computer
	char input = 'r';


	while (totalGameScore <= SCORE_LIMIT && totalGameScoreComp <= SCORE_LIMIT){
		turnScore = 0;
	
		while (input = 'r'){
	
			cout << "Enter r to roll dice, or s to stop turn ";
			cin >> input;                        //
			cout << endl << DASH;	
			if (input != 'r' && input != 's'){
				cout << "Enter r to roll dice, or s to stop turn ";
				cin >> input;
			}
		if (input = 's') {
			totalGameScore += turnScore;
			cout << "Total score = " << totalGameScore;
				break;
		}
			die1 = rolldie();
			die2 = rolldie();

		if (isTurnScoreLost(die1, die2) == true){
			turnScore = 0;
			cout << "You rolled a " << die1 << " and a " << die2 << "." << endl << "Turn Score Lost!" << endl << DASH;
				break;
			}

		else{
			turnScore = (turnScore + (die1 + die2));
			cout << "You rolled a " << die1 << " and a " << die2 << "." << endl;
			cout << "Turn Score = " << turnScore << endl;
				continue;
			}

		if (isGameScoreLost(die1, die2) == true){
			totalGameScore = 0;
			cout << "Game Score Lost!" << endl << DASH;
				break;
			}
	

		}
		if (totalGameScore >= SCORE_LIMIT){
			cout << "\nPlayer wins!\n";
				return 0;
		}


		//end of player while loop

		//devider
		cout << endl << DASH;

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
		
			die1 = rolldie();
			die2 = rolldie();

			if (isTurnScoreLost(die1, die2) == true){
				turnScore = 0;
				cout << "The computer rolled a " << die1 << " and a " << die2 << "." << endl << "Turn Score Lost!" << endl << DASH;
				break;
			}
			else {
				turnScore = (turnScore + (die1 + die2));
				cout << "The computer rolled a " << die1 << " and a " << die2 << "." << endl;
				cout << "Turn Score = " << turnScore << endl << DASH;
			}

			if (isGameScoreLost(die1, die2) == true){
				totalGameScoreComp = 0;
				cout << "Game Score Lost!" << endl << DASH;
				break;
			
			}//end of if 
		}	//end of computer while loop
		//end of entire while loop	

	}
	if (totalGameScoreComp >= SCORE_LIMIT){
	cout << "\nComputer Wins!\n";
	return 0;
}
	}


bool isTurnScoreLost(int die1, int die2) {								/*function to decide whether the turn 
																		score is lost based on if a 1 was rolled */
	if ((die1 == 1 & die2 != 1) || (die1 != 1 && die2 == 1))
		return true;
	else 
		return false;

}

bool isGameScoreLost(int die1, int die2) {								/*function to decide wether the game score is 
																		lost based on if both numbers rolled were 1*/
	if (die1 == 1 && die2 == 1)
		return true;
	else
		return false;
	
}

int rolldie(void) {														/*this function rolls the dice*/
	int ran;
	ran = rand() % 6 + 1;
	return ran;
}

char getUserInput(void) {
	char input = 'r';
	if ((input == 'r') || (input == 's'))
		return true;
	else
		return false;

}

	
