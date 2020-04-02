#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int left_s, left_e, right_s, right_e;
	bool flag;
};
stru ans;
vector<int> func_left(vector<int> vec, int s, int e) {
	int temp;
	for (int i = s; i <= e; i++) {
		if (vec[i] == s + 1) {
			temp = i;
			break;
		}
	}
	ans.left_s = s + 1;
	ans.left_e = temp + 1;
	reverse(vec.begin() + s, vec.begin() + temp + 1);
	return vec;
}
vector<int> func_right(vector<int> vec, int s, int e) {
	int temp;
	for (int i = e; i >= s; i--) {
		if (vec[i] == e + 1) {
			temp = i;
			break;
		}
	}
	ans.right_s = temp + 1;
	ans.right_e = e + 1;
	reverse(vec.begin() + temp, vec.begin() + e + 1);
	return vec;
}
void func(vector<int> vec, int s, int e) {	
	vector<int> temp = func_left(vec, s, e);
	int temp_s, temp_e;
	temp_s = s;
	for (int i = s; i <= e; i++) {
		if (temp[i] != i + 1) {
			break;
		}
		temp_s++;
	}
	temp_e = e;
	for (int i = e; i >= s; i--) {
		if (temp[i] != i + 1) {
			break;
		}
		temp_e--;
	}
	if (temp_s != e + 1 || temp_e != s - 1) {
		temp = func_right(temp, temp_s, temp_e);
	}
	else {
		ans.right_s = ans.right_e = 1;
	}
	bool flag = true;
	for (int i = s; i <= e; i++) {
		if (temp[i] != i + 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		ans.flag = true;
		return;
	}
	temp = func_right(vec, s, e);
	temp_s = s;
	for (int i = s; i <= e; i++) {
		if (temp[i] != i + 1) {
			break;
		}
		temp_s++;
	}
	temp_e = e;
	for (int i = e; i >= s; i--) {
		if (temp[i] != i + 1) {
			break;
		}
		temp_e--;
	}
	if (temp_s != e + 1 || temp_e != s - 1) {
		temp = func_left(temp, temp_s, temp_e);
	}
	else {
		ans.left_s = ans.left_e = 1;
	}
	ans.flag = false;
	return;
}
int main() {
	int n;
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	int s, e;
	s = 0;
	for (int i = 0; i < n; i++) {
		if (vec[i] != i + 1) {
			break;
		}
		s++;
	}
	e = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (vec[i] != i + 1) {
			break;
		}
		e--;
	}
	if (s != n || e != -1) {
		func(vec, s, e);
	}
	else {
		ans.left_e = ans.right_e = ans.left_s = ans.right_s = 1;
	}
	if (ans.flag) {
		cout << ans.left_s << " " << ans.left_e << endl << ans.right_s << " " << ans.right_e;
	}
	else {
		cout << ans.right_s << " " << ans.right_e << endl << ans.left_s << " " << ans.left_e;
	}
	return 0;
}