#include <iostream>

//prints a diamond made of asterisks, from programming 1 class
//author: annalise dake
using namespace std;

int main(void){
	while (true) {
		int num;
		int i; int j;
		cout << "Enter number of asterisks";
		cin >> num;

		for (i = -num; i <= num; i++) {

			for (j = -num; j <= num; j++) {

				if (abs(i) + abs(j) < num) { cout << "*"; }
				else
					cout << " ";

			}
			cout << endl;
		}
	}
	return 1;
}