#include <iostream>
using namespace std;
int arr[100005];
int st[800005];
int ans[100005];
void set_st(int index, int s, int e) {
	st[index] = e - s + 1;
	if (s == e) {
		return;
	}
	set_st(index * 2, s, (s + e) / 2);
	set_st(index * 2 + 1, (s + e) / 2 + 1, e);
}
int find_st(int index, int s, int e, int num) {
	st[index]--;
	if (s == e) {
		return s;
	}
	int mid = (s + e) / 2;
	int left = st[index * 2];
	if (left >= num) {
		return find_st(index * 2, s, mid, num);
	}
	else {
		return find_st(index * 2 + 1, mid + 1, e, num - left);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
	}
	set_st(1, 1, n);
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		int index = find_st(1, 1, n, temp + 1);
		ans[index] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}