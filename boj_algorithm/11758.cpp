#include <iostream>
using namespace std;
struct point {
	int x, y;
};
int main() {
	point p1, p2, p3;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	int temp = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
	if (temp > 0) {
		temp = 1;
	}
	else if (temp < 0) {
		temp = -1;
	}
	cout << temp << endl;
	return 0;
}