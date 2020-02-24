#include <iostream>
using namespace std;
int st_num[400005];
int st_index[400005];
int arr[100005];
int min_temp;
int ans;
int make_st(int index, int left, int right) {
	if (left == right) {
		st_index[index] = left;
		st_num[index] = arr[left];
		return st_num[index];
	}
	int mid = (left + right) / 2;
	int a = make_st(index * 2, left, mid);
	int b = make_st(index * 2 + 1, mid + 1, right);
	if (a > b) {
		st_num[index] = st_num[index * 2 + 1];
		st_index[index] = st_index[index * 2 + 1];
	}
	else {
		st_num[index] = st_num[index * 2];
		st_index[index] = st_index[index * 2];
	}
	return st_num[index];
}
void calc(int index, int left, int right, int start, int end) {
	if (left == start && right == end) {
		if (min_temp > st_num[index]) {
			min_temp = st_num[index];
			ans = st_index[index];
		}
		else if (min_temp == st_num[index] && ans > st_index[index]) {
			ans = st_index[index];
		}
		return;
	}
	int mid = (left + right) / 2;
	if (mid >= end) {
		calc(index * 2, left, mid, start, end);
	}
	else if (mid < start) {
		calc(index * 2 + 1, mid + 1, right, start, end);
	}
	else {
		calc(index * 2, left, mid, start, mid);
		calc(index * 2 + 1, mid + 1, right, mid + 1, end);
	}
}
void update(int index, int left, int right, int change_index, int change_num) {
	if (left == right) {
		arr[left] = change_num;
		st_num[index] = change_num;
		return;
	}
	int mid = (left + right) / 2;
	if (mid >= change_index) {
		update(index * 2, left, mid, change_index, change_num);
	}
	else {
		update(index * 2 + 1, mid + 1, right, change_index, change_num);
	}
	int a = st_num[index * 2];
	int b = st_num[index * 2 + 1];
	if (a > b) {
		st_num[index] = st_num[index * 2 + 1];
		st_index[index] = st_index[index * 2 + 1];
	}
	else {
		st_num[index] = st_num[index * 2];
		st_index[index] = st_index[index * 2];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make_st(1, 1, n);
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			min_temp = 2000000000;
			calc(1, 1, n, b, c);
			cout << ans << "\n";
		}
	}
	return 0;
}