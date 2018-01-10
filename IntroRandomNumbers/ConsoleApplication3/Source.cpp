#include <iostream>
#include <ctime>

using namespace std;

int main(void) {
	int x;
	int y;
	const int a = 0;
	const int b = 1;
	const int c = 2;
	const int d = 3;

	const int INTERSECTIONS = 100;
	const int DRUNKARDS = 10;
	const int DIRECTIONS = 4;

	srand( time((unsigned) 0));

	for (int i = 1; i <= DRUNKARDS; i++)
	{
		x = 0;
		y = 0;
		for (int j = 1; j <= INTERSECTIONS; j++){
			int directions = rand() % DIRECTIONS;
			switch (directions) {
			case a: y++;
			case b: y--;
			case c: x++;
			case d: x--;
			}
		}
		cout << "Drunkard #" << i << ": at instersection (" << x << "," << y << ")" << endl;

	
	}

	int g;
	cin >> g;
	return 0;

}