#include <iostream>
#include <string>

using namespace std;

int getPlayerInput(string playerName);
bool isLegalMove(int location, char board[], int boardsize);
void placeMarkOnBoard(char playermark, int location, char board[], int boardsize);
void clearBoard(char board[], int boardsize);
bool hasThreeInRow(char playerMark, char board[], int boardsize);
void displayBoard(char board[]);



int main(void) {
string Player1name;
string Player2name;
string player;
	int location = 0;
	char playerMark = 'X';
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int boardsize = 9;
	cout << "Welcome to Tic Tac D'oh!" << endl;
	cout << "Please enter Player 1's name: ";
	getline(cin, Player1name); cout << endl;
	cout << "Please enter Player 2's name: ";
	getline(cin, Player2name);
	player = Player1name;
	while (true){
		//system("cls");
		displayBoard(board);
		location = getPlayerInput(player);
		if (isLegalMove(location, board, boardsize) == false){
			cout << " invalid input" << endl;
			continue;
		}
		placeMarkOnBoard(playerMark, location, board, boardsize);
		
		
		if (hasThreeInRow(playerMark, board, boardsize) == true){
			char yes;
			cout << "Congratulations, " << player << " you win!" << endl;
			cout << "Would you like to play again? Y/N: ";
			cin >> yes;
			if (yes == 'Y')
				clearBoard(board, boardsize);
			else break;
		}

		
	
		if (player == Player1name)
		{
			player = Player2name;
			playerMark = 'O';
		}
		else {
			player = Player1name;
			playerMark = 'X';
		}
	}
}
void displayBoard(char board[]){
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
		cout << "---+---+---" << endl;
		cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
		cout << "---+---+---" << endl;
		cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

int getPlayerInput(string playerName){
	int location;

	while (true){
		cout << playerName << ", please select which location you would like to place your marker: ";
		cin >> location;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		if (cin.fail() || (location < 1 || location > 9)){
			cout << "Invalid input ";
			continue;
		}
		else return location;
	}
}

void placeMarkOnBoard(char playerMark, int location, char board[], int boardsize){
	
		
	//board[location - 1] = playerMark;
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
bool isLegalMove(int location, char board[], int boardsize){
	if (board[location-1] == 'X' || board[location-1] == 'O')
		return false;
	else return true;
}
void clearBoard(char board[], int boardsize){
		board[9];
}
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
//bool tie(char board[]){

//}