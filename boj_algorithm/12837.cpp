#include <iostream>
using namespace std;
int n, q;
long long st[8000000];
long long ans;
void update(int index, int s, int e, int date, int money) {
	st[index] += money;
	if (date<s || date>e) {
		return;
	}
	if (s == e) {
		return;
	}
	if (date <= (s + e) / 2) {
		update(index * 2, s, (s + e) / 2, date, money);
	}
	else {
		update(index * 2 + 1, (s + e) / 2 + 1, e, date, money);
	}
}
void calc(int index, int s, int e, int l, int r) {
	if (l > e || r < s) {
		return;
	}
	if (s == l && e == r) {
		ans += st[index];
		return;
	}
	int mid = (s + e) / 2;
	if (mid >= r) {
		calc(index * 2, s, mid, l, r);
	}
	else if (mid < l) {
		calc(index * 2 + 1, mid + 1, e, l, r);
	}
	else {
		calc(index * 2, s, mid, l, mid);
		calc(index * 2 + 1, mid + 1, e, mid + 1, r);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	int a, b, c;
	while (q--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c);
		}
		else {
			ans = 0;
			calc(1, 1, n, b, c);
			cout << ans << "\n";
		}
	}
	return 0;
}