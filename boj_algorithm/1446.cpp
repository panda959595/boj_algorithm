#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct stru {
	int s, e, len;
};
struct mv {
	int now;
	int len;
};
vector<stru> vec;
int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		stru temp;
		cin >> temp.s >> temp.e >> temp.len;
		if (temp.e > d || temp.len >= temp.e - temp.s) {
			continue;
		}
		vec.push_back(temp);
	}
	queue<mv> que;
	mv now = { 0,0 };
	que.push(now);
	int ans = 10005;
	while (!que.empty()) {
		now = que.front();
		que.pop();
		if (ans > d - now.now + now.len) {
			ans = d - now.now + now.len;
		}
		for (int i = 0; i < vec.size(); i++) {
			if (now.now > vec[i].s) {
				continue;
			}
			mv temp;
			temp.len = now.len + vec[i].s - now.now + vec[i].len;
			temp.now = vec[i].e;
			que.push(temp);
		}
	}
	cout << ans << endl;
	return 0;
}