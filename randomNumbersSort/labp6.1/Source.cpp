#include<iostream>
#include<string>
#include<ctime>

using namespace std;

int main(void){

	
	int i = 0;
	srand(time(NULL));
	int numbers[10] = { 0 };
	cout << "The random integers:";
	for (i = 0; i < 10; i++){
		numbers[i] = rand() % 9000 + 1000;
		cout << " " << numbers[i] << " ";
	}
	cout << endl;
	cout << "Even indices: " << numbers[0] << " " << numbers[2] << " " << numbers[4] << " " << numbers[6] << " " << numbers[8] << endl;
	cout << "Even numbers:";
	for (int j = 0; j < 10; j++){
		if (numbers[j] % 2 == 0)
			cout << " " << numbers[j] << " ";
	}
	cout << endl;
	cout << "Reverse order: ";
	for (int j = 9; j >= 0; j--){
		cout << " " << numbers[j] << " ";
	}
	cout << endl;
	cout << "First and Last: " << numbers[0] << " " << numbers[9] << endl;
	int x;
	cin >> x;
}