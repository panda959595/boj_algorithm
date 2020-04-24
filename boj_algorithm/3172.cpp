#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int st[400005];
void update(int index, int l, int r, int num) {
	if (num<l || num>r) {
		return;
	}
	st[index]++;
	if (l == r) {
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, num);
	update(index * 2 + 1, mid + 1, r, num);
}
int calc(int index, int l, int r, int s, int e) {
	if (r < s || l > e) {
		return 0;
	}
	if (s <= l && r <= e) {
		return st[index];
	}
	int mid = (l + r) / 2;
	return calc(index * 2, l, mid, s, e) + calc(index * 2 + 1, mid + 1, r, s, e);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector < pair<string, int> >vec;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back({ temp,i });
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		vec[i].second = i + 1;
		reverse(vec[i].first.begin(), vec[i].first.end());
	}
	sort(vec.begin(), vec.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		update(1, 1, n, vec[i].second);
		if (vec[i].second == n) {
			continue;
		}
		ans += calc(1, 1, n, vec[i].second + 1, n);
	}
	cout << ans << "\n";
	return 0;
}