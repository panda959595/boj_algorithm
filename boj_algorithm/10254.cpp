#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
struct stru {
	int x, y, p, q;
};
bool bigyo(stru a, stru b) {
	if (1LL * a.q*b.p != 1LL * b.q*a.p) {
		return 1LL * a.q*b.p < 1LL * b.q*a.p;
	}
	else if (a.y != b.y) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}
long long len(stru a, stru b) {
	return 1LL * (a.x - b.x)*(a.x - b.x) + 1LL * (a.y - b.y)*(a.y - b.y);
}
bool check(stru a, stru b, stru c) {
	return 1LL * (b.y - a.y)*(c.x - a.x) < 1LL * (c.y - a.y)*(b.x - a.x);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<stru> point;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			point.push_back({ a,b,0,0 });
		}
		if (n == 2) {
			cout << point[0].x << " " << point[0].y << " " << point[1].x << " " << point[1].y << "\n";
		}
		sort(point.begin(), point.end(), bigyo);
		for (int i = 1; i < n; i++) {
			point[i].p = point[i].x - point[0].x;
			point[i].q = point[i].y - point[0].y;
		}
		sort(point.begin() + 1, point.end(), bigyo);
		stack<int> sta;
		sta.push(0);
		sta.push(1);
		for (int i = 2; i < n; i++) {
			while (sta.size() >= 2) {
				int b = sta.top();
				sta.pop();
				int a = sta.top();
				if (check(point[a], point[b], point[i])) {
					sta.push(b);
					break;
				}
			}
			sta.push(i);
		}
		vector<int> vec;
		while (!sta.empty()) {
			vec.push_back(sta.top());
			sta.pop();
		}
		pair<int, int> ans;
		long long ans_temp = 0;
		if (vec.size() % 2 == 0) {
			for (int i = 0; i < vec.size() / 2; i++) {
				long long temp = len(point[vec[i]], point[vec[i + vec.size() / 2]]);
				if (temp > ans_temp) {
					ans_temp = temp;
					ans.first = vec[i];
					ans.second = vec[i + vec.size() / 2];
				}
			}
		}
		else {
			for (int i = 0; i <= vec.size() / 2; i++) {
				long long temp = len(point[vec[i]], point[vec[i + vec.size() / 2]]);
				if (temp > ans_temp) {
					ans_temp = temp;
					ans.first = vec[i];
					ans.second = vec[i + vec.size() / 2];
				}
				if (i == vec.size() / 2) {
					continue;
				}
				temp = len(point[vec[i]], point[vec[i + 1 + vec.size() / 2]]);
				if (temp > ans_temp) {
					ans_temp = temp;
					ans.first = vec[i];
					ans.second = vec[i + 1 + vec.size() / 2];
				}
			}
		}
		cout << point[ans.first].x << " " << point[ans.first].y << " " << point[ans.second].x << " " << point[ans.second].y << "\n";
	}
	return 0;
}