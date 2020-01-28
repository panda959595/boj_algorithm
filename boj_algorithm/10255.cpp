#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct point {
	int x, y;
	bool operator==(point a) {
		if (x == a.x && y == a.y) {
			return true;
		}
		else {
			return false;
		}
	}
};
long long ccw(point a, point b, point c) {
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}
int func(point a, point b, point x, point y) {//a, b 변/ x, y 선분
	long long c1 = ccw(a, b, x);
	long long c2 = ccw(a, b, y);
	long long c3 = ccw(x, y, a);
	long long c4 = ccw(x, y, b);
	bool d1, d2, d3, d4;
	d1 = d2 = d3 = d4 = false;
	if (c1 == 0) {
		if (a.x == b.x) {
			if (x.y > max(a.y, b.y) || x.y < min(a.y, b.y)) {
				d1 = false;
			}
			else {
				d1 = true;
			}
		}
		else {
			if (x.x > max(a.x, b.x) || x.x < min(a.x, b.x)) {
				d1 = false;
			}
			else {
				d1 = true;
			}
		}
	}
	if (c2 == 0) {
		if (a.x == b.x) {
			if (y.y > max(a.y, b.y) || y.y < min(a.y, b.y)) {
				d2 = false;
			}
			else {
				d2 = true;
			}
		}
		else {
			if (y.x > max(a.x, b.x) || y.x < min(a.x, b.x)) {
				d2 = false;
			}
			else {
				d2 = true;
			}
		}
	}
	if (c3 == 0) {
		if (x.x == y.x) {
			if (a.y > max(x.y, y.y) || a.y < min(x.y, y.y)) {
				d3 = false;
			}
			else {
				d3 = true;
			}
		}
		else {
			if (a.x > max(x.x, y.x) || a.x < min(x.x, y.x)) {
				d3 = false;
			}
			else {
				d3 = true;
			}
		}
	}
	if (c4 == 0) {
		if (x.x == y.x) {
			if (b.y > max(x.y, y.y) || b.y < min(x.y, y.y)) {
				d4 = false;
			}
			else {
				d4 = true;
			}
		}
		else {
			if (b.x > max(x.x, y.x) || b.x < min(x.x, y.x)) {
				d4 = false;
			}
			else {
				d4 = true;
			}
		}
	}
	if (!d1 && !d2 && !d3 && !d4) {//한 직선위에 x
		if (1LL * c1 * c2 < 0 && 1LL * c3 * c4 < 0) {//교점이 1개
			return 2;
		}
		else {//교점 0개
			return 0;
		}
	}
	else {
		int temp = 0;
		if (d1) {
			temp++; 
		}
		if (d2) {
			temp++;
		}
		if (d3) {
			temp++;
		}
		if (d4) {
			temp++;
		}
		if ((d1 && d2) || (d3 && d4)) {
			return 8;
		}
		if (temp > 1) {
			if (a == x || a == y || b == x || b == y) {
				return 1;
			}
			else {
				return 8;
			}
		}
		if (d3 || d4) {
			return 1;
		}
		else {
			return 2;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		point a, b;
		point s, e;
	/*	a.x = 0;
		a.y = 0;
		b.x = 10;
		b.y = 10;*/
		cin >> a.x >> a.y >> b.x >> b.y;
		cin >> s.x >> s.y >> e.x >> e.y;
		int ans = 0;
		point temp_a, temp_b;
		temp_a = a;
		temp_b = { a.x,b.y };
		ans += func(temp_a, temp_b, s, e);
		temp_b = { b.x,a.y };
		ans += func(temp_a, temp_b, s, e);
		temp_b = b;
		temp_a = { a.x,b.y };
		ans += func(temp_a, temp_b, s, e);
		temp_a = { b.x,a.y };
		ans += func(temp_a, temp_b, s, e);
		ans /= 2;
		if (ans < 4) {
			cout << ans << endl;
		}
		else {
			cout << 4 << endl;
		}
	}
	return 0;
}