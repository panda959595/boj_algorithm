#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int min_num;
vector<int> vec;
int n;
bool func(int a, int x, int b, int y, int index) {
	bool ret = false;
	if (index == n - 1) {
		return  true;
	}
	if (x == -1) {
		if (vec[index] - min_num == 0) {
			return false;
		}
		ret |= func(vec[index], vec[index] - min_num, b, y, index + 1);
	}
	else if (y == -1) {
		if (vec[index] == a + x) {
			ret |= func(a + x, x, b, y, index + 1);
		}
		if (ret) {
			return true;
		}
		ret |= func(a, x, vec[index], vec[index] - min_num, index + 1);
	}
	else {
		if (vec[index] == a + x) {
			ret |= func(vec[index], x, b, y, index + 1);
		}
		if (ret) {
			return true;
		}
		if (x != y && vec[index] == b + y) {
			ret |= func(a, x, vec[index], y, index + 1);
		}
		else {
			return false;
		}
	}
	return ret;
}
int main() {
	cin >> n;
	cin >> min_num;
	for (int i = 1; i < n; i++) {
		int temp;
		cin >> temp;
		if (min_num > temp) {
			swap(min_num, temp);
		}
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	bool flag = func(-1, -1, -1, -1, 0);
	if (flag) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}