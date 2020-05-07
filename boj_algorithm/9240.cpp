#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
pair<int, int> point[100005];
bool func(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	return 1LL * (p3.second - p1.second) * (p2.first - p1.first) - 1LL * (p2.second - p1.second) * (p3.first - p1.first);
}
double calc(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(1.0 * (p1.first - p2.first) * (p1.first - p2.first) + 1.0 * (p1.second - p2.second) * (p1.second - p2.second));
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> point[i].first >> point[i].second;
	}
	sort(point, point + n);
	stack<pair<int, int> > sta;
	sta.push(point[0]);
	sta.push(point[1]);
	for (int i = 2; i < n; i++) {
		while (sta.size() >= 2) {
			pair<int, int> p1, p2;
			p2 = sta.top();
			sta.pop();
			p1 = sta.top();
			if (func(p1, p2, point[i])) {
				sta.push(p2);
				break;
			}
		}
		sta.push(point[i]);
	}
	vector<pair<int,int> > vec;
	double ans = 0;
	while (!sta.empty()) {
		vec.push_back(sta.top());
		sta.pop();
	}
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < i; j++) {
			ans = max(ans, calc(vec[i], vec[j]));
		}
	}
	cout << fixed;
	cout.precision(9);
	cout << ans << endl;
	return 0;
}