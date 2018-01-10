#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	float num;
	float sum = 0.0;
	float squares = 0.0;
	int count = 0;
	while (true){

		cout << "enter numbers - Q to quit: ";

		cin >> num; 
		count++;
		sum += num;
		squares += num * num;

	float avg = sum / count;
	float stand = sqrt((squares - sum * sum / count) / (count - 1));

	if (count == 0)
		cout << "No data to process - exiting..." << endl;

	else cout << "n = " << count << ", average = " << avg << ", standard deviation =  " << stand << endl;
}
	return 1;
}