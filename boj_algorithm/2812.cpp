#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string str;
int main() {
	int n, k;
	cin >> n >> k;
	cin >> str;
	stack<int> sta;
	sta.push(str[0] - '0');
	for (int i = 1; i < n; i++) {
		int temp = str[i] - '0';
		while (!sta.empty() && k > 0) {
			int top = sta.top();
			if (temp > top) {
				k--;
				sta.pop();
			}
			else {
				break;
			}
		}
		sta.push(temp);
	}
	while (k > 0) {
		sta.pop();
		k--;
	}
	stack<int> sta_temp;
	while (!sta.empty()) {
		int temp = sta.top();
		sta.pop();
		sta_temp.push(temp);
	}
	while (!sta_temp.empty()) {
		int temp = sta_temp.top();
		sta_temp.pop();
		cout << temp;
	}
	return 0;
}