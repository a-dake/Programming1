#include <iostream>
#include <string>

using namespace std;

int getPlayerInput(int location);
bool isLegalMove(int location, char board[], int boardsize);
void placeMarkOnBoard();
void clearBoard(char board[], int boardsize);
bool hasThreeInRow(char playerMark, char board[], int boardsize);
void displayBoard();
void toggle();
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
string Player1name;
string Player2name;
string player = Player2name;
int a = 0;
int location = 0;

int main(void) {
	cout << "Welcome to Tic Tac D'oh!" << endl;
	cout << "Please enter Player 1's name: ";
	getline(cin, Player1name); cout << endl;
	cout << "Pleas enter Player 2's name: ";
	getline(cin, Player2name);
	while (a == 0){


		
		displayBoard();
		getPlayerInput(player);
		placeMarkOnBoard();
		toggle();

	}
}
void displayBoard(){
	for (int i = 0; i < 1; i++){
		cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
		cout << "---+---+---" << endl;
		cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
		cout << "---+---+---" << endl;
		cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;

	}
}

int getPlayerInput(string playerName){

	int location;
	cout << playerName << ", please select which location you would like to place your marker: ";
		cin >> location;
		while (location != 1 && location != 2 && location != 3 && location != 4 && location != 5 && location != 6 && location != 7 && location != 8 && location != 9)
		{
			cout << "invalid input" << endl;
			continue;
		}

		return location;
	
}

void placeMarkOnBoard(){
	if (player == Player1name){
		//board[
		if (getPlayerInput(location) == 1)
			board[0] = 'X';
		else if (getPlayerInput(location) == 2)
			board[1] = 'X';
		else if (getPlayerInput(location) == 3)
			board[2] = 'X';
		else if (getPlayerInput(location) == 4)
			board[3] = 'X';
		else if (getPlayerInput(location) == 5)
			board[4] = 'X';
		else if (getPlayerInput(location) == 6)
			board[5] = 'X';
		else if (getPlayerInput(location) == 7)
			board[6] = 'X';
		else if (getPlayerInput(location) == 8)
			board[7] = 'X';
		else if (getPlayerInput(location) == 9)
			board[8] = 'X';
	}

	if (player == Player2name){
		if (getPlayerInput(location) == 1)
			board[0] = 'O';
		else if (getPlayerInput(location) == 2)
			board[1] = 'O';
		else if (getPlayerInput(location) == 3)
			board[2] = 'O';
		else if (getPlayerInput(location) == 4)
			board[3] = 'O';
		else if (getPlayerInput(location) == 5)
			board[4] = 'O';
		else if (getPlayerInput(location) == 6)
			board[5] = 'O';
		else if (getPlayerInput(location) == 7)
			board[6] = 'O';
		else if (getPlayerInput(location) == 8)
			board[7] = 'O';
		else if (getPlayerInput(location) == 9)
			board[8] = 'O';
	}

}
void toggle(){
	if (player == Player1name)
		player = Player2name;
	else
		player = Player1name;
}