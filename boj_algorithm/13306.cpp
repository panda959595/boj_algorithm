#include <iostream>
#include <vector>
using namespace std;
int n, q;
int parent[200005];
int level[200005];
int input[200005];
struct stru {
	int flag;
	int b;
	int c, d;
};
vector<stru> query;
vector<bool> ans;
int find(int n) {
	if (n == parent[n]) {
		return n;
	}
	else {
		return parent[n] = find(parent[n]);
	}
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	if (level[a] < level[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	parent[b] = a;
	if (level[a] == level[b]) {
		level[a]++;
	}
}
int main() {
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> input[i];
		parent[i] = i;
		level[i] = 1;
	}
	level[1] = 1;
	parent[1] = 1;
	for (int i = 0; i < n + q - 1; i++) {
		stru temp;
		cin >> temp.flag;
		if (temp.flag == 0) {
			cin >> temp.b;
		}
		else {
			cin >> temp.c >> temp.d;
		}
		query.push_back(temp);
	}
	for (int i = n + q - 2; i >= 0; i--) {
		if (query[i].flag == 0) {
			merge(query[i].b, input[query[i].b]);
		}
		else {
			int n, m;
			n = find(query[i].c);
			m = find(query[i].d);
			if (n == m) {
				ans.push_back(1);
			}
			else {
				ans.push_back(0);
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}