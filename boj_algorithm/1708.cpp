#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct stru {
	int x, y, p, q;
};
vector<stru> vec;
bool bigyo(stru a, stru b) {
	if (1LL * a.q*b.p != 1LL * a.p*b.q) {
		return 1LL * a.q*b.p < 1LL * a.p*b.q;
	}
	else if (a.y!=b.y) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}
bool check(stru a, stru b, stru c) {
	return 1LL * (b.y - a.y)*(c.x - a.x) < 1LL * (c.y - a.y)*(b.x - a.x);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b,0,0 });
	}
	sort(vec.begin(), vec.end(), bigyo);
	for (int i = 1; i < n; i++) {
		vec[i].p = vec[i].x - vec[0].x;
		vec[i].q = vec[i].y - vec[0].y;
	}
	sort(vec.begin() + 1, vec.end(), bigyo);
	stack<int> sta;
	sta.push(0);
	sta.push(1);
	for (int i = 2; i < n; i++) {
		while (sta.size() >= 2) {
			int b = sta.top();
			sta.pop();
			int a = sta.top();
			if (check(vec[a], vec[b], vec[i])) {
				sta.push(b);
				break;
			}
		}
		sta.push(i);
	}
	cout << sta.size() << "\n";
	return 0;
}