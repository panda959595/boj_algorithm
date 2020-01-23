#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point {
	double x, y;
};
struct stru {
	point s, e;
};
stru y[2005];
stru g[2005];
double ans = 100000000;
double point_len(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double tri_area(point p1, point p2, point p3) {
	return abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) / 2;
}
bool check(point p1, point p2, point p3) {
	if ((p2.x - p1.x) * (p3.x - p1.x) + (p2.y - p1.y) * (p3.y - p1.y) < 0) {
		return false;
	}
	if ((p1.x - p2.x) * (p3.x - p2.x) + (p1.y - p2.y) * (p3.y - p2.y) < 0) {
		return false;
	}
	return true;
}
double func2(point p1, point p2, point p3) {
	return tri_area(p1, p2, p3) / point_len(p1, p2) * 2;
}
void func(stru a, stru b) {
	double ret = 100000000;
	double temp = point_len(a.s, b.s);
	ret = min(ret, temp);
	temp = point_len(a.s, b.e);
	ret = min(ret, temp);
	temp = point_len(a.e, b.s);
	ret = min(ret, temp);
	temp = point_len(a.e, b.e);
	ret = min(ret, temp);

	if (check(a.s, a.e, b.s)) {
		temp = func2(a.s, a.e, b.s);
		ret = min(ret, temp);
	}
	if (check(a.s, a.e, b.e)) {
		temp = func2(a.s, a.e, b.e);
		ret = min(ret, temp);
	}
	if (check(b.s, b.e, a.s)) {
		temp = func2(b.s, b.e, a.s);
		ret = min(ret, temp);
	}
	if (check(b.s, b.e, a.e)) {
		temp = func2(b.s, b.e, a.e);
		ret = min(ret, temp);
	}
	ans = min(ans, ret);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> y[i].s.x >> y[i].s.y >> y[i].e.x >> y[i].e.y;
	}
	for (int i = 0; i < m; i++) {
		cin >> g[i].s.x >> g[i].s.y >> g[i].e.x >> g[i].e.y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			func(y[i], g[j]);
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << ans << endl;
	return 0;
}