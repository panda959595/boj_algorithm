#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> road[10005];
int people[10005];
int check[10005];
struct stru {
	int xx, ox, o;
	stru(int a, int b, int c) {
		xx = a;
		ox = b;
		o = c;
	}
	stru() {
		xx = 0;
		ox = 0;
		o = 0;
	}
};
stru func(int num, int pre) {
	vector<stru> vec;
	if (road[num].size() == 1 && pre != 0) {
		return stru(0, 0, people[num]);
	}
	for (auto k : road[num]) {
		if (k == pre) {
			continue;
		}
		stru temp = func(k, num);
		vec.push_back(temp);
	}
	stru ret;
	//xx,o
	for (auto k : vec) {
		ret.xx += max(k.xx, k.ox);
		ret.o += max(k.xx, k.ox);
	}
	ret.o += people[num];
	//ox
	for (int i = 0; i < vec.size(); i++) {
		int temp = vec[i].o;
		for (int j = 0; j < vec.size(); j++) {
			if (i == j) {
				continue;
			}
			temp += max(max(vec[j].xx, vec[j].ox), vec[j].o);
		}
		ret.ox = max(ret.ox, temp);
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
		check[a]++;
		check[b]++;
	}
	stru ans;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 1) {
			ans = func(i, 0);
			break;
		}
	}
	cout << max(max(ans.o, ans.ox), ans.xx) << endl;
	return 0;
}