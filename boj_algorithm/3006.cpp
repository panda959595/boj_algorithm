#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100005];
int st[400005];
vector<int> vec;
vector<int> ans;
void update(int index, int l, int r, int num) {
	if (num<l || num>r) {
		return;
	}
	st[index]++;
	if (num == l && num == r) {
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, num);
	update(index * 2 + 1, mid + 1, r, num);
}
int calc(int index, int l, int r, int s, int e) {
	if (s > r || e < l) {
		return 0;
	}
	else if (s == l && e == r) {
		return st[index];
	}
	int mid = (l + r) / 2;
	if (mid >= e) {
		return calc(index * 2, l, mid, s, e);
	}
	else if (mid < s) {
		return calc(index * 2 + 1, mid + 1, r, s, e);
	}
	else {
		return calc(index * 2, l, mid, s, mid) + calc(index * 2 + 1, mid + 1, r, mid + 1, e);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[temp] = i + 1;
	}
	int l, r;
	l = 1;
	r = n;
	while (l <= r) {
		vec.push_back(l);
		if (l != r) {
			vec.push_back(r);
		}
		l++;
		r--;
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (i % 2 != n % 2) {
			ans.push_back(calc(1, 1, n, 1, arr[vec[i]]));
		}
		else {
			ans.push_back(calc(1, 1, n, arr[vec[i]], n));
		}
		update(1, 1, n, arr[vec[i]]);
	}
	reverse(ans.begin(),ans.end());
	for (int i = 0; i < n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}