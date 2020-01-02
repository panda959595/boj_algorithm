#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map< string, vector<string> > ma;
queue<string> que;
vector<string> ans;
map<string, bool> check;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str1, str2, str3;
		cin >> str1 >> str3 >> str2;
		ma[str1].push_back(str2);
	}
	que.push("Baba");
	check["Baba"] = true;
	while (!que.empty()) {
		string now = que.front();
		que.pop();
		for (auto k : ma[now]) {
			if (check[k]) {
				continue;
			}
			check[k] = true;
			que.push(k);
			ans.push_back(k);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}