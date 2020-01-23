#include <iostream>
using namespace std;
struct point {
	double x, y;
};
double outer(point p1, point p2, point p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}
int main() {
	int n;
	cin >> n;
	point arr[10005];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	double ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ans += outer(arr[0], arr[i], arr[i + 1]) / 2;
	}
	ans = abs(ans);
	cout << fixed;
	cout.precision(1);
	cout << ans << endl;
	return 0;
}