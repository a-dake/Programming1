#include <iostream>
#include <string>

using namespace std;


bool isSortedIncreasing(int num[]);
bool isSortedDecreasing(int num[]);
bool hasAdjacentDuplicates(int num[]);
bool hasDuplicates(int num[]);

const int SIZE = 5;
int main(void){
	while (true) {
		int num[SIZE] = { 0 };
		for (int i = 0; i <= SIZE; i++) {
			cout << "Enter integer #" << i << ": ";
			cin >> num[i];
			cout << endl;
		}
		if (isSortedIncreasing(num) == true)
			cout << "The data is increasing" << endl;
		else cout << "The data is not increasing" << endl;

		if (isSortedDecreasing(num) == true)
			cout << "The data is decreasing" << endl;
		else
			cout << "The data is not decreasing" << endl;

		if (hasAdjacentDuplicates(num) == true)
			cout << "The data has adjacent duplicates" << endl;
		else cout << "The data does not have adjacent duplicates" << endl;

		if (hasDuplicates(num) == true)
			cout << "The data has duplicates" << endl;
		else cout << "The data does not have duplicates" << endl;

	}
	return 1;


}

bool isSortedIncreasing(int num[]){
	int x = 0;
	for (int i = 0; i < SIZE; i++){
		if (num[i] >= num[i-1])
			x++;
	}
	if (x >= SIZE - 1)
		return true;
	else return false;
}

bool isSortedDecreasing(int num[]){
	int x = 0;
	for (int i = 0; i < SIZE; i++){
		if (num[i] <= num[i-1])
			x++;
	}
	if (x >= SIZE - 1)
		return true;
	else
		return false;
}
bool hasAdjacentDuplicates(int num[]){
	int x = 0;
	for (int i = 0; i < SIZE; i++){
		if (num[i] == num[i-1])
			x++;
	}
	if (x > 0)
		return true;
	else return false;
}
bool hasDuplicates(int num[]){
	for (int i = 0; i < SIZE; i++){
		for (int j = i + 1; j < SIZE; j++){
			if (num[i] == num[j])
				return true;
		}
	}
	return false;
}