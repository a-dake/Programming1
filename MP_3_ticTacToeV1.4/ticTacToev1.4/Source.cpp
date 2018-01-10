/*ticTacToev1.4 Written by Annalise Dake 11/9/2016
Simple game of Tic Tac Toe
allows two people to play against each other*/

#include <iostream>
#include <string>

using namespace std;

// function prototypes

int getPlayerInput(string playerName);	
bool isLegalMove(int location, char board[], int boardsize);
void placeMarkOnBoard(char playermark, int location, char board[], int boardsize);
void clearBoard(char board[], int boardsize);
bool hasThreeInRow(char playerMark, char board[], int boardsize);
void displayBoard(char board[]);
bool tie(char board[]);

// main function

int main(void) {

	//variables

	string Player1name;		//first player's name
	string Player2name;		//second player's name
	string player;			//player who's turn it is
	int location = 0;		//location where the player is putting their mark
	char playerMark = 'X';	//the players mark (either "X" or "O")
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };	//array that holds the game board
	int boardsize = 9;		//size of the board
	int XCount = 0;			//counts how many times player one has won
	int OCount = 0;			//counts how many times player two has won
	int tieCount = 0;		//counts how many times the game has been tied
	int gameCount = 0;		//counts the total number of games played

	/*greets user(s), prompts for the player's names
	allows the user(s) to input names*/

	cout << "Welcome to Tic Tac D'oh!" << endl;
	cout << "Please enter Player 1's name: ";
	getline(cin, Player1name); cout << endl;
	cout << "Please enter Player 2's name: ";
	getline(cin, Player2name);
	player = Player1name;

	/*while loop loops the game*/

	while (true){

	/*sets player one's mark to "X" 
	and player two's mark to "O"*/

		if (player == Player1name)
			playerMark = 'X';
		else if (player == Player2name)
			playerMark = 'O';

	/*displays game board,
	get's player's input for which location 
	they'd like to select*/

		displayBoard(board);
		location = getPlayerInput(player);

	/*if the input is invalid
	tells the user
	prompts for input again*/

		if (isLegalMove(location, board, boardsize) == false){
			cout << "Invalid input, please select an available space." << endl;
			continue;
		}

		placeMarkOnBoard(playerMark, location, board, boardsize);		//function places players mark on board

	/*checks if someone has won the game,
	if so, let's them know, adds 1 to their total number of wins
	prompts to play again, and either continues or breaks
	based on their input*/

		if (hasThreeInRow(playerMark, board, boardsize) == true){
			displayBoard(board);
			gameCount++;	//increments the total number of games
			char yes;		//input from player if they would like to play again
			cout << "Congratulations, " << player << " you win!" << endl;
			if (playerMark == 'X'){

				XCount++;	//increments number of wins by player 1
			}
			else if (playerMark == 'O') {

				OCount++;	//increments number of wins by player 2
			}
			cout << Player1name << ": " << XCount << endl;
			cout << Player2name << ": " << OCount << endl;
			cout << "Ties: " << tieCount << endl;
			cout << "Would you like to play again? Y/N: ";
			cin >> yes; cout << endl;
			if (yes == 'Y')
				clearBoard(board, boardsize);
			if (gameCount % 2 == 0)		//alternates players every other game
				player = Player1name;
			else
				player = Player2name;
			continue;
			if (yes != 'Y')
				break;
		}
			
		/*checks if tied game, if so, 
		prompts user if they would like to continue playing
		*/
		if (tie(board) == true){
			displayBoard(board);
			gameCount++;	//increments total number of games played
			char yes;		//user input for playing again
			tieCount++;		//increments the number of ties
			cout << "It's a tie!" << endl;
			cout << Player1name << ": " << XCount << endl;
			cout << Player2name << ": " << OCount << endl;
			cout << "Ties: " << tieCount << endl;
			cout << "Would you like to play again? Y/N: ";
			cin >> yes; cout << endl;
			if (yes == 'Y'){
				clearBoard(board, boardsize);
			if (gameCount % 2 == 0)
				player = Player1name; //alternates first player every other game
		else
				player = Player2name;
				continue;
			}
			if (yes != 'Y')
				break;
		}

		/*switches players between turns*/

		if (player == Player1name)
		{
			player = Player2name;
		}
		else {
			player = Player1name;
		} //end of if
	} //end of while
} //end of main

/*function that displays the game board when called; returns no value*/

void displayBoard(char board[]){
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}
 /*function that gets the players unput when called
 returns a number between 1 and 9 
 corresponding to the place on the board
 where they would like to place their mark*/

int getPlayerInput(string playerName){
	int location;

	while (true){
		cout << playerName << ", please select which location you would like to place your marker: ";
		cin >> location;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (cin.fail() || (location < 1 || location > 9)){ //if the input is invalid, user is prompted again
			cout << "Invalid input ";
			continue;
		}
		else return location;
	}
}
 
 /*function places marker of either "X" or "O" on board, 
 based on user input, when called; returns no value*/
void placeMarkOnBoard(char playerMark, int location, char board[], int boardsize){

	if (location == 1)
		board[0] = playerMark;
	else if (location == 2)
		board[1] = playerMark;
	else if (location == 3)
		board[2] = playerMark;
	else if (location == 4)
		board[3] = playerMark;
	else if (location == 5)
		board[4] = playerMark;
	else if (location == 6)
		board[5] = playerMark;
	else if (location == 7)
		board[6] = playerMark;
	else if (location == 8)
		board[7] = playerMark;
	else if (location == 9)
		board[8] = playerMark;
}

 /*function figures out if the input from the user
 for the space they would like to take has been used already
 returns false, when it has been
 and true when it has not been*/

bool isLegalMove(int location, char board[], int boardsize){
	if (board[location - 1] == 'X' || board[location - 1] == 'O')
		return false;
	else return true;
}

 /*function clears the board after someone has won 
 or the game has tied
 and the user indicates they would like to play again
 returns no value*/

void clearBoard(char board[], int boardsize){
	board[0] = '1';
	board[1] = '2';
	board[2] = '3';
	board[3] = '4';
	board[4] = '5';
	board[5] = '6';
	board[6] = '7';
	board[7] = '8';
	board[8] = '9';
}

 /*function decides if someone has won the game
 returns true if they have
 and false if they have not*/

bool hasThreeInRow(char playerMark, char board[], int boardsize){
	if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
		return true;
	else if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
		return true;
	else if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
		return true;
	else if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
		return true;
	else if (board[1] == 'X' && board[7] == 'X' && board[4] == 'X')
		return true;
	else if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
		return true;
	else if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
		return true;
	else if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
		return true;
	else if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
		return true;
	else if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
		return true;
	else if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')
		return true;
	else if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
		return true;
	else if (board[1] == 'O' && board[7] == 'O' && board[4] == 'O')
		return true;
	else if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
		return true;
	else if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
		return true;
	else if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
		return true;

	else return false;


}

 /*function decides if the game is tied
 returns true if it has
 false if it has not*/

bool tie(char board[]){
	if (board[0] != '1' && board[1] != '2' && board[2] != '3' && board[3] != '4' 
		&& board[4] != '5' && board[5] != '6' && board[6] != '7' && board[7] != '8' && board[8] != '9')
		return true;
	else return false;

}