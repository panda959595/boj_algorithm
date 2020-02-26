#include <iostream>
using namespace std;
int arr[500005];
int st[2000005];
int lazy[2000005];
int make_st(int index, int left, int right) {
	if (left == right) {
		return st[index] = arr[left];
	}
	int mid = (left + right) / 2;
	return st[index] = make_st(index * 2, left, mid) ^ make_st(index * 2 + 1, mid + 1, right);
}
void propa(int index, int left, int right) {
	if (lazy[index] == 0) {
		return;
	}
	if ((right - left) % 2 == 0) {
		st[index] ^= lazy[index];
	}
	if (left != right) {
		lazy[index * 2] ^= lazy[index];
		lazy[index * 2 + 1] ^= lazy[index];
	}
	lazy[index] = 0;
}
void update(int index, int left, int right, int start, int end, int num) {
	propa(index, left, right);
	if (end < left || right < start) {
		return;
	}
	if (start <= left && right <= end) {
		lazy[index] ^= num;
		propa(index, left, right);
		return;
	}
	int mid = (left + right) / 2;
	update(index * 2, left, mid, start, end, num);
	update(index * 2 + 1, mid + 1, right, start, end, num);
	st[index] = st[index * 2] ^ st[index * 2 + 1];
}
int calc(int index, int left, int right, int start, int end) {
	propa(index, left, right);
	if (end < left || right < start) {
		return 0;
	}
	if (start <= left && right <= end) {
		return st[index];
	}
	int mid = (left + right) / 2;
	return calc(index * 2, left, mid, start, end) ^ calc(index * 2 + 1, mid + 1, right, start, end);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		//update(1, 1, n, i, i, arr[i]);
	}
	make_st(1, 1, n);
	cin >> m;
	while (m--) {
		int num, a, b;
		int c;
		cin >> num;
		if (num == 1) {
			cin >> a >> b >> c;
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			update(1, 1, n, a + 1, b + 1, c);
		}
		else {
			cin >> a >> b;
			if (a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			cout << calc(1, 1, n, a + 1, b + 1) << "\n";
		}
	}
	return 0;
}