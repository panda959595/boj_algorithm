#include <iostream>
using namespace std;
int m, n;
int arr[705][705];
int grow1[1405];
int grow2[1405];
int stree1[3000];
int stree2[3000];
int lazy1[3000];
int lazy2[3000];
void update1(int index, int left, int right, int s, int e, int val) {
	if (s == left && e == right) {
		lazy1[index] += val;
		return ;
	}
	int mid = (left + right) / 2;
	if (mid >= e) {
		update1(index * 2, left, mid, s, e, val);
	}
	else if (mid < s) {
		update1(index * 2 + 1, mid + 1, right, s, e, val);
	}
	else {
		update1(index * 2, left, mid, s, mid, val);
		update1(index * 2 + 1, mid + 1, right, mid + 1, e, val);
	}
}
void update2(int index, int left, int right, int s, int e, int val) {
	if (s == left && e == right) {
		lazy2[index] += val;
		return;
	}
	int mid = (left + right) / 2;
	if (mid >= e) {
		update2(index * 2, left, mid, s, e, val);
	}
	else if (mid < s) {
		update2(index * 2 + 1, mid + 1, right, s, e, val);
	}
	else {
		update2(index * 2, left, mid, s, mid, val);
		update2(index * 2 + 1, mid + 1, right, mid + 1, e, val);
	}
}
void downlazy1(int index, int left, int right) {
	if (left == right) {
		grow1[left] = lazy1[index];
		return;
	}
	if (lazy1[index] > 0) {
		lazy1[index * 2] += lazy1[index];
		lazy1[index * 2 + 1] += lazy1[index];
	}
	int mid = (left + right) / 2;
	downlazy1(index * 2, left, mid);
	downlazy1(index * 2 + 1, mid + 1, right);
}
void downlazy2(int index, int left, int right) {
	if (left == right) {
		grow2[left] = lazy2[index];
		return;
	}
	if (lazy2[index] > 0) {
		lazy2[index * 2] += lazy2[index];
		lazy2[index * 2 + 1] += lazy2[index];
	}
	int mid = (left + right) / 2;
	downlazy2(index * 2, left, mid);
	downlazy2(index * 2 + 1, mid + 1, right);
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b != 0) {
			update1(1, 1, 2 * m - 1, 1 + a, a + b, 1);
		}
		if (c != 0) {
			update1(1, 1, 2 * m - 1, 1 + a + b, 2 * m - 1, 2);
		}
		if (c >= m - 1) {
			update2(1, 1, m - 1, 1, m - 1, 2);
		}
		else if (c > 0) {
			update2(1, 1, m - 1, m - c, m - 1, 2);
			if (b + c >= m - 1) {
				update2(1, 1, m - 1, 1, m - c - 1, 1);
			}
			else if (b > 0) {
				update2(1, 1, m - 1, m - b - c, m - c - 1, 1);
			}
		}
		else {
			if (b + c >= m - 1) {
				update2(1, 1, m - 1, 1, m - c - 1, 1);
			}
			else if (b > 0) {
				update2(1, 1, m - 1, m - b - c, m - c - 1, 1);
			}
		}
	}
	downlazy1(1, 1, 2 * m - 1);
	downlazy2(1, 1, m - 1);
	for (int i = 1; i <= m; i++) {
		arr[m - i][0] = grow1[i] + 1;
	}
	for (int i = m + 1; i <= 2 * m - 1; i++) {
		arr[0][i - m] = grow1[i] + 1;
	}
	for (int i = 1; i < m ; i++) {
		for (int j = 1; j < m; j++) {
			arr[i][j] = grow2[j] + 1;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}