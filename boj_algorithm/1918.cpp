#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
string str;
int p, m;
queue<char> func() {
	queue<char> ret;
	stack<char> temp;
	char top;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			while (!temp.empty()) {
				top = temp.top();
				if (top != '(') {
					ret.push(top);
					temp.pop();
				}
				else {
					break;
				}
			}
			temp.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!temp.empty()) {
				top = temp.top();
				if (top == '*' || top == '/') {
					ret.push(top);
					temp.pop();
				}
				else {
					break;
				}
			}
			temp.push(str[i]);
		}
		else if (str[i] == '(') {
			temp.push(str[i]);
		}
		else if (str[i] == ')') {
			top = temp.top();
			temp.pop();
			while (top!='(') {
				ret.push(top);
				top = temp.top();
				temp.pop();
			}
		}
		else {
			ret.push(str[i]);
		}
	}
	while (!temp.empty()) {
		top = temp.top();
		temp.pop();
		ret.push(top);
	}
	return ret;
}
int main() {
	cin >> str;
	queue<char> que = func();
	while (!que.empty()) {
		char temp = que.front();
		que.pop();
		cout << temp;
	}
	return 0;
}