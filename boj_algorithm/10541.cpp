#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long alpa[30][1000005];
long long alpa_all[30];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	string str;
	cin >> n;
	cin >> str;
	alpa[str[0] - 'A'][0]++;
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < str.length(); j++) {
			alpa[i][j] = alpa[i][j - 1];
			if (str[j] - 'A' == i) {
				alpa[i][j]++;
			}
		}
		alpa_all[i] = alpa[i][str.length() - 1];
	}
	int k, len;
	len = str.length();
	cin >> k;
	while (k--) {
		long long line;
		char c;
		long long ans = 0;
		cin >> line >> c;
		//line번째 위에 나온 횟수
		long long start;
		line--;
		if (line % 2 == 0) {
			start = (line / 2) % len;
			start *= (line + 1) % len;
		}
		else {
			start = line % len;
			start *= ((line + 1) / 2) % len;
		}
		start %= len;
		line++;
		if (line >= len) {
			ans += alpa_all[c - 'A'] * (line / len);
			line %= len;
		}
		if (start + line <= len) {
			if (start != 0) {
				ans += alpa[c - 'A'][start + line - 1] - alpa[c - 'A'][start - 1];
			}
			else {
				ans += alpa[c - 'A'][start + line - 1];
			}
		}
		else {
			ans += alpa[c - 'A'][len - 1] - alpa[c - 'A'][start - 1];
			ans += alpa[c - 'A'][line - len + start - 1];
		}
		cout << ans << "\n";
	}
	return 0;
}