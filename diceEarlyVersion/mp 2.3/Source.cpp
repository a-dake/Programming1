#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int diceRoll();
int humanTurn(int& TotalGameScore);
int computerTurn(int& computerTotalGameScore);

int main()

{
	const int SCORE_LIMIT = 100;
	bool win = 1;
	int totalGameScore = 0, computerTotalScore = 0;
	int computerTotalGameScore = 0;
	cout << "It is your turn. Press r to roll.\n";
	if ((totalGameScore < SCORE_LIMIT) && (computerTotalScore < SCORE_LIMIT))
	{
		win = 1;
	}
	else
	{
		win = 0;
	}
	do
	{
		cout << "Computers Score: " << computerTotalScore << endl;

		humanTurn(totalGameScore);
		computerTurn(computerTotalGameScore);
	} while (win = 1);

	if ((win = 0) && (totalGameScore > computerTotalGameScore))
	{
		cout << "You win!";
	}
	else
	{
		cout << "You lost!";
	}


	return 0;
}


int humanTurn(int& totalGameScore)
{
	int currentScore = 0;
	int lastRoll;
	char rollOrHold;
	int humanTotalScore = 0;
	

	cout << "Your total score is: " << humanTotalScore << "." << endl;
	cout << "Press r to roll again, or h to hold." << endl;
	cin >> rollOrHold;

	while (rollOrHold == 'r')
	{
		srand(time(NULL));
		lastRoll = diceRoll();
		if (lastRoll == 1)
		{
			cout << "You rolled a 1, ending your turn." << endl;
			break;
		}
		else
		{
			currentScore += lastRoll;
			cout << "You roll a " << lastRoll << ". Your score this turn is: " << currentScore << endl;
			cout << "Press r to roll again, or h to hold." << endl;
			cin >> rollOrHold;
		}
	}
	while (rollOrHold == 'h')
	{
		humanTotalScore += currentScore;
		break;
	}

	return humanTotalScore;
}

int computerTurn(int& computerTotalScore)
{
	int currentScore = 0;
	int lastRoll;

	cout << "Computer's total score is: " << computerTotalScore << "." << endl;
	while ((currentScore <= 20) && (currentScore != 1))
	{
		lastRoll = diceRoll();
		if (lastRoll == 1)
		{
			cout << "The computer rolled a 1, ending their turn." << endl;
			break;
		}
		else
		{
			currentScore += lastRoll;
			cout << "The computer rolls a " << lastRoll << ". Computer's score this turn is: " << currentScore << endl;
		}
	}
	if (currentScore >= 20)
	{
		computerTotalScore += currentScore;
		cout << "After the computer's turn, they have gained an additional " << lastRoll << " points." << endl;
	}

	return computerTotalScore;
}

int diceRoll()
{
	int roll;

	roll = rand() % 6 + 1;

	return roll;
}