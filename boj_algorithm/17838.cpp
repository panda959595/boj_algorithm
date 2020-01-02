#include <iostream>
#include <string>
using namespace std;
int main() {
	int t;
	int a[2] = { 1,4 };
	int b[3] = { 3,5,6 };
	cin >> t;
	string str;
	while (t--) {
		cin >> str;
		bool flag = true;
		for (int i = 0; i < 2; i++) {
			if (str[0] != str[a[i]]) {
				flag = false;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (str[2] != str[b[i]]) {
				flag = false;
			}
		}
		if (str[0] == str[2]) {
			flag = false;
		}
		if (flag) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}