#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
vector<int> vec;
int minus_st[800005];
int two_st[800005];
void set_minus_st(int index, int s, int e) {
	if (s == e) {
		if (vec[s - 1] < 0) {
			minus_st[index] = 1;
		}
		else {
			minus_st[index] = 0;
		}
		return;
	}
	set_minus_st(index * 2, s, (s + e) / 2);
	set_minus_st(index * 2 + 1, (s + e) / 2 + 1, e);
	minus_st[index] = minus_st[index * 2] + minus_st[index * 2 + 1];
}
void set_two_st(int index, int s, int e) {
	if (s == e) {
		if (abs(vec[s - 1]) == 2) {
			two_st[index] = 1;
		}
		else {
			two_st[index] = 0;
		}
		return;
	}
	set_two_st(index * 2, s, (s + e) / 2);
	set_two_st(index * 2 + 1, (s + e) / 2 + 1, e);
	two_st[index] = two_st[index * 2] + two_st[index * 2 + 1];
}
int get_minus_st(int index, int s, int e, int l, int r) {
	if (s == l && e == r) {
		return minus_st[index];
	}
	int mid = (s + e) / 2;
	if (mid >= r) {
		return get_minus_st(index * 2, s, mid, l, r);
	}
	else if (mid < l) {
		return get_minus_st(index * 2 + 1, mid + 1, e, l, r);
	}
	else {
		return get_minus_st(index * 2, s, mid, l, mid) + get_minus_st(index * 2 + 1, mid + 1, e, mid + 1, r);
	}
}
int get_two_st(int index, int s, int e, int l, int r) {
	if (s == l && e == r) {
		return two_st[index];
	}
	int mid = (s + e) / 2;
	if (mid >= r) {
		return get_two_st(index * 2, s, mid, l, r);
	}
	else if (mid < l) {
		return get_two_st(index * 2 + 1, mid + 1, e, l, r);
	}
	else {
		return get_two_st(index * 2, s, mid, l, mid) + get_two_st(index * 2 + 1, mid + 1, e, mid + 1, r);
	}
}
long long lpow(long long a, int b) {
	if (b == -1) {
		return 0;
	}
	if (b == 1) {
		return a;
	}
	else if (b == 0) {
		return 1;
	}
	else if (b % 2 == 0) {
		a *= a;
		a %= 1000000007;
		return lpow(a, b / 2);
	}
	else {
		long long ret = lpow(a, b - 1);
		ret *= a;
		ret %= 1000000007;
		return ret;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		vec.clear();
		cin >> n;
		int first_min = -1;
		int last_min = -1;
		int min_num = 0;
		int size = 0;
		int two_num = -1;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			vec.push_back(temp);
			if (temp < 0 && first_min == -1) {
				first_min = vec.size();
			}
			if (temp < 0) {
				last_min = vec.size();
				min_num++;
			}
			if (temp == 0) {
				if (size == 0) {
					vec.clear();
					first_min = -1;
					last_min = -1;
					continue;
				}
				else if (size == 1) {
					if (vec[0] == 2) {
						two_num = max(two_num, 1);
					}
					else if (vec[0] == 1) {
						two_num = max(two_num, 0);
					}
					vec.clear();
					size = 0;
					first_min = -1;
					last_min = -1;
					continue;
				}
				set_two_st(1, 1, size);
				int two_num_temp;
				if (first_min == -1) {
					two_num_temp = get_two_st(1, 1, size, 1, size);
				}
				else if (min_num % 2 == 0) {
					two_num_temp = get_two_st(1, 1, size, 1, size);
				}
				else {
					int left_two = get_two_st(1, 1, size, 1, first_min);
					int right_two = get_two_st(1, 1, size, last_min, size);
					if (left_two > right_two) {
						two_num_temp = get_two_st(1, 1, size, 1, last_min - 1);
					}
					else {
						two_num_temp = get_two_st(1, 1, size, first_min + 1, size);
					}
				}
				two_num=max(two_num,two_num_temp);
				vec.clear();
				size = 0;
				first_min = -1;
				last_min = -1;
			}
			else {
				size++;
			}
		}
		if (size > 1) {
			set_two_st(1, 1, size);
			int two_num_temp;
			if (first_min == -1) {
				two_num_temp = get_two_st(1, 1, size, 1, size);
			}
			else if (min_num % 2 == 0) {
				two_num_temp = get_two_st(1, 1, size, 1, size);
			}
			else {
				int left_two = get_two_st(1, 1, size, 1, first_min);
				int right_two = get_two_st(1, 1, size, last_min, size);
				if (left_two >= right_two) {
					two_num_temp = get_two_st(1, 1, size, 1, last_min - 1);
				}
				else {
					two_num_temp = get_two_st(1, 1, size, first_min + 1, size);
				}
			}
			two_num = max(two_num, two_num_temp);
			vec.clear();
			size = 0;
			first_min = -1;
			last_min = -1;
		}
		else if (size == 1) {
			if (vec[0] == 2) {
				two_num = max(two_num, 1);
			}
			else if (vec[0] == 1) {
				two_num = max(two_num, 0);
			}
			vec.clear();
			size = 0;
			first_min = -1;
			last_min = -1;
		}
		long long ans = lpow(2, two_num);
		cout << ans << "\n";
	}
	return 0;
}