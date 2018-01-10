#include <iostream>
#include <string>

using namespace std;

int convertToRomanInt(string str);
int romanCharValue(char r);
int sum;

int main(void){
	string input;
	while (true) {
		cout << "Enter Roman Numeral or Q to quit: ";
		getline(cin, input);
		if (input == "Q")
			break;
		cout << "\""<< input << "\"" << " = "; 
		cout << convertToRomanInt(input) << endl;
	}
	return 0;

}

int convertToRomanInt(string str){
	string input = str;
	int length = input.length();
	int previous = 0;
	bool error = false;
	int nIndex = 0;

	sum = 0;

	while ((error == false) && (nIndex < length))
	{
		switch (input[nIndex])
		{
		case 'M':
			sum += 1000;
			if (previous < 1000)
			{
				sum -= 2 * previous;
			}
			previous = 1000;
			break;
		case 'D':
			sum += 500;
			if (previous < 500)
			{
				sum -= 2 * previous;
			}
			previous = 500;
			break;
		case 'C':
			sum += 100;
			if (previous < 100)
			{
				sum -= 2 * previous;
			}
			previous = 100;
			break;
		case 'L':
			sum += 50;
			if (previous < 50)
			{
				sum -= 2 * previous;
			}
			previous = 50;
			break;
		case 'X':
			sum += 10;
			if (previous < 10)
			{
				sum -= 2 * previous;
			}
			previous = 10;
			break;
		case 'V':
			sum += 5;
			if (previous < 5)
			{
				sum -= 2 * previous;
			}
			previous = 5;
			break;
		case 'I':
			sum += 1;
			if (previous < 1)
			{
				sum -= 2 * previous;
			}
			
			previous = 1;
			break;
		}
		nIndex++;		
		}
	return sum;

	}
int romanCharValue(char r){
	char s = r;
	return s;
}