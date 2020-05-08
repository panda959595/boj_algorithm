#include <iostream>
#include <string>
using namespace std;
int alpa[26];
string str;
long long func1(int pre, int stack, int index) {
	if (index == str.length()) {
		return 1;
	}
	if (str[index] != '_') {
		if (pre == alpa[str[index] - 'A']) {
			stack++;
		}
		else {
			pre = alpa[str[index] - 'A'];
			stack = 1;
		}
		if (stack == 3) {
			return 0;
		}
		return func1(pre, stack, index + 1);
	}
	long long ret = 0;
	if (pre == 1) {
		ret += func1(2, 1, index + 1) * 21;
		if (stack == 1) {
			ret += func1(1, 2, index + 1) * 5;
		}
	}
	else {
		ret += func1(1, 1, index + 1) * 5;
		if (stack != 2) {
			ret += func1(2, stack + 1, index + 1) * 21;
		}
	}
	return ret;
}
long long func2(int pre, int stack, int index, bool flag) {
	if (index == str.length()) {
		if (flag) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (str[index] != '_') {
		if (pre == alpa[str[index] - 'A']) {
			stack++;
		}
		else {
			pre = alpa[str[index] - 'A'];
			stack = 1;
		}
		if (stack == 3) {
			return 0;
		}
		return func2(pre, stack, index + 1, flag);
	}
	long long ret = 0;
	if (pre == 0) {
		ret += func2(1, 1, index + 1, flag) * 5;
		if (stack == 1) {
			ret += func2(2, 2, index + 1, flag) * 21;
		}
	}
	if (pre == 1) {
		ret += func2(2, 1, index + 1, flag) * 20;
		ret += func2(2, 1, index + 1, true);
		if (stack != 2) {
			ret += func2(1, stack + 1, index + 1, flag) * 5;
		}
	}
	else {
		ret += func2(1, 1, index + 1, flag) * 5;
		if (stack != 2) {
			ret += func2(2, stack + 1, index + 1, flag) * 20;
			ret += func2(2, stack + 1, index + 1, true);
		}
	}
	return ret;
}
int main() {
	cin >> str;
	bool l_check = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'L') {
			l_check = true;
			break;
		}
	}
	for (int i = 0; i < 26; i++) {
		alpa[i] = 2;
	}
	alpa['A' - 'A'] = 1;
	alpa['E' - 'A'] = 1;
	alpa['I' - 'A'] = 1;
	alpa['O' - 'A'] = 1;
	alpa['U' - 'A'] = 1;
	if (l_check) {
		cout << func1(-1, 0, 0);
	}
	else {
		cout << func2(-1, 0, 0, false);
	}
	return 0;
}