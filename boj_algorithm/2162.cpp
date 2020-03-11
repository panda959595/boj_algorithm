#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct point {
	double x, y;
};
vector<int> road[3005];
point arr[3005][2];
bool check[3005];
double ccw(point a, point b, point c) {
	// a-b <a-c
	return  (c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x);
}
bool line(point a, point b, point c) {
	if (c.x<min(a.x, b.x) || c.x>max(a.x, b.x) || c.y<min(a.y, b.y) || c.y>max(a.y, b.y)) {
		return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0].x >> arr[i][0].y >> arr[i][1].x >> arr[i][1].y;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double a1 = ccw(arr[i][0], arr[i][1], arr[j][0]);
			double a2 = ccw(arr[i][0], arr[i][1], arr[j][1]);
			double b1 = ccw(arr[j][0], arr[j][1], arr[i][0]);
			double b2 = ccw(arr[j][0], arr[j][1], arr[i][1]);
			if (((a1 < 0 && a2>0) || (a1 > 0 && a2 < 0)) && ((b1 < 0 && b2>0) || (b1 > 0 && b2 < 0))) {
				road[i].push_back(j);
				road[j].push_back(i);
			}
			if ((a1 == 0 && line(arr[i][0], arr[i][1], arr[j][0])) || (a2 == 0 && line(arr[i][0], arr[i][1], arr[j][1]))) {
				road[i].push_back(j);
				road[j].push_back(i);
			}
			if ((b1 == 0 && line(arr[j][0], arr[j][1], arr[i][0])) || (b2 == 0 && line(arr[j][0], arr[j][1], arr[i][1]))) {
				road[i].push_back(j);
				road[j].push_back(i);
			}
		}
	}
	int ans = 0;
	int ma = 0;
	queue<int> que;
	for (int i = 0; i < n; i++) {
		if (check[i]) {
			continue;
		}
		ans++;
		check[i] = true;
		que.push(i);
		int temp = 1;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (auto k : road[now]) {
				if (check[k]) {
					continue;
				}
				temp++;
				check[k] = true;
				que.push(k);
			}
		}
		if (ma < temp) {
			ma = temp;
		}
	}
	cout << ans << endl << ma << endl;
	return 0;
}