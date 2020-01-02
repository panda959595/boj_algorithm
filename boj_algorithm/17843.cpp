#include <iostream>
#include <algorithm>
using namespace std;
double mid(double x, double y, double z) {
	if (x >= y&&y >= z) {
		return y;
	}
	else if (y >= x && x >= z) {
		return x;
	}
	else {
		return z;
	}
}
double min(double x, double y, double z) {
	if (x <= y && x <= z) {
		return x;
	}
	else if (y <= x && y <= z) {
		return y;
	}
	else {
		return z;
	}
}
double max(double x, double y, double z) {
	if (x >= y && x >= z) {
		return x;
	}
	else if (y >= x && y >= z) {
		return y;
	}
	else {
		return z;
	}
}
int main() {
	int T;
	cin >> T;
	cout << fixed;
	cout.precision(7);
	while (T--) {
		double h, m, s;
		double x, y, z;
		cin >> h >> m >> s;
		x = s * 6;
		y = (s + 60 * m) / 10;
		z = (s + 60 * m + 3600 * h) / 120;
		double a, b, c;
		a = min(x, y, z);
		c = max(x, y, z);
		b = mid(x, y, z);
		double ans = min(a + 360 - c, b - a, c - b);
		cout << ans << "\n";
	}
	return 0;
}