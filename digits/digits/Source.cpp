#include <iostream>

using namespace std;



int last_digit(int n) {
	int last;
	last = n % 10;
	return last;
}

int first_digit(int n) {
	while (n >= 10) {
		n /= 10;	
		
	}
	
	return n;
}

int digits(int n) {
	int count;
	for (count = 1; n >= 10; n++) {
		
		if (n >= 10)
			count++;
			n /= 10;
	}
	return count;
}
int main(void) {
	int n;
	while (!cin.fail()){
	cout << "Enter number or Q to quit: ";

		cin >> n;
		if (cin.fail()) return 0;
		cout << "First digit: " << first_digit(n) << " ";
		cout << "Last digit : " << last_digit(n) << " ";
		cout << "Number of digits: " << digits(n) << endl;
	}
}