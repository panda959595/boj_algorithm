#include <iostream>
#include <algorithm>
using namespace std;
struct point {
	double x, y;
};
point line_start, line_end;
bool horizon_check(double y, double x_start, double x_end) {
	double x = (line_start.y*line_end.x + line_start.x*y - line_start.x*line_end.y - line_end.x*y) / (line_start.y - line_end.y);
	if (x >= x_start && x <= x_end && x >= min(line_start.x, line_end.x) && x <= max(line_start.x, line_end.x)) {
		return true;
	}
	else {
		return false;
	}
}
bool vertical_check(double x, double y_start, double y_end) {
	double y = (line_start.x*line_end.y + line_start.y*x - line_start.y*line_end.x - line_end.y*x) / (line_start.x - line_end.x);
	if (y >= y_start && y <= y_end && y >= min(line_start.y, line_end.y) && y <= max(line_start.y, line_end.y)) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	point left_top, right_bottom;
	int sx, sy, ex, ey;
	int T;
	cin >> T;
	while (T--) {
		cin >> line_start.x >> line_start.y >> line_end.x >> line_end.y;
		//cin >> left_top.x >> left_top.y >> right_bottom.x >> right_bottom.y;
		cin >> sx >> sy >> ex >> ey;
		if (sx > ex) {
			int temp = sx;
			sx = ex;
			ex = temp;
		}
		if (sy > ey) {
			int temp = sy;
			sy = ey;
			ey = temp;
		}
		if (line_start.x == line_end.x) {
			if (sx > line_start.x || ex < line_start.x) {
				cout << "F\n";
			}
			else {
				if (line_start.y > ey&&line_end.y > ey) {
					cout << "F\n";
				}
				else if (line_start.y < sy&&line_end.y < sy) {
					cout << "F\n";
				}
				else {
					cout << "T\n";
				}
			}
			continue;
		}
		if (line_start.y == line_end.y) {
			if (sy > line_start.y || ey < line_start.y) {
				cout << "F\n";
			}
			else {
				if (line_start.x > ex&&line_end.x > ex) {
					cout << "F\n";
				}
				else if (line_start.x < sx&&line_end.x < sx) {
					cout << "F\n";
				}
				else {
					cout << "T\n";
				}
			}
			continue;
		}
		if (line_start.x >= sx && line_start.x <= ex &&
			line_end.x >= sx && line_end.x <= ex &&
			line_start.y >= sy && line_start.y <= ey &&
			line_end.y >= sy && line_end.y <= ey) {
			cout << "T\n";
			continue;
		}
		bool ans = false;
		ans |= horizon_check(sy, sx, ex);
		ans |= horizon_check(ey, sx, ex);
		ans |= vertical_check(sx, sy, ey);
		ans |= vertical_check(ex, sy, ey);
		if (ans) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}
	return 0;
}