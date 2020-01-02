#include <iostream>
#include <string>
using namespace std;
int n, k;
int arr[100005];
int st_minus[400005];
int st_zero[400005];
int make_st_minus(int index, int s, int e) {
	if (s == e) {
		if (arr[s] < 0) {
			return st_minus[index] = 1;
		}
		else {
			return st_minus[index] = 0;
		}
		return st_minus[index];
	}
	int mid = (s + e) / 2;
	return st_minus[index] = make_st_minus(index * 2, s, mid) + make_st_minus(index * 2 + 1, mid + 1, e);
}
int make_st_zero(int index, int s, int e) {
	if (s == e) {
		if (arr[s] == 0) {
			return st_zero[index] = 1;
		}
		else {
			return st_zero[index] = 0;
		}
	}
	int mid = (s + e) / 2;
	return st_zero[index] = make_st_zero(index * 2, s, mid) + make_st_zero(index * 2 + 1, mid + 1, e);
}
void update_minus(int index, int s, int e, int num, int flag) {
	st_minus[index] += flag;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	if (num > mid) {
		update_minus(index * 2 + 1, mid + 1, e, num, flag);
	}
	else {
		update_minus(index * 2, s, mid, num, flag);
	}
}
void update_zero(int index, int s, int e, int num, int flag) {
	st_zero[index] += flag;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	if (num > mid) {
		update_zero(index * 2 + 1, mid + 1, e, num, flag);
	}
	else {
		update_zero(index * 2, s, mid, num, flag);
	}
}
int calc_minus(int index, int s, int e, int l, int r) {
	if (s == l && e == r) {
		return st_minus[index];
	}
	int mid = (s + e) / 2;
	if (mid >= r) {
		return calc_minus(index * 2, s, mid, l, r);
	}
	else if (mid < l) {
		return calc_minus(index * 2 + 1, mid + 1, e, l, r);
	}
	else {
		return calc_minus(index * 2, s, mid, l, mid) + calc_minus(index * 2 + 1, mid + 1, e, mid + 1, r);
	}
}
int calc_zero(int index, int s, int e, int l, int r) {
	if (s == l && e == r) {
		return st_zero[index];
	}
	int mid = (s + e) / 2;
	if (mid >= r) {
		return calc_zero(index * 2, s, mid, l, r);
	}
	else if (mid < l) {
		return calc_zero(index * 2 + 1, mid + 1, e, l, r);
	}
	else {
		return calc_zero(index * 2, s, mid, l, mid) + calc_zero(index * 2 + 1, mid + 1, e, mid + 1, r);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	//cin >> T;
	while (cin>>n>>k) {
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		string ans = "";
		make_st_minus(1, 1, n);
		make_st_zero(1, 1, n);
		for (int i = 0; i < k; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'C') {
				if (b < 0) {
					if (arr[a] >= 0) {
						update_minus(1, 1, n, a, 1);
					}
					if (arr[a] == 0) {
						update_zero(1, 1, n, a, -1);
					}
				}
				else if (b == 0) {
					if (arr[a] != 0) {
						update_zero(1, 1, n, a, 1);
					}
					if (arr[a] < 0) {
						update_minus(1, 1, n, a, -1);
					}
				}
				else {
					if (arr[a] < 0) {
						update_minus(1, 1, n, a, -1);
					}
					else if (arr[a] == 0) {
						update_zero(1, 1, n, a, -1);
					}
				}
				arr[a] = b;
			}
			else {
				if (calc_zero(1, 1, n, a, b) > 0) {
					ans += '0';
				}
				else if (calc_minus(1, 1, n, a, b) % 2 == 0) {
					ans += '+';
				}
				else {
					ans += '-';
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}