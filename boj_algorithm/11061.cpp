#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int f[1005][1005];
struct stru {
	int length;
	int s;
	int e;
};
vector<stru> vec;
bool bigyo(stru a, stru b) {
	return a.length < b.length;
}
int parent[1005];
int level[1005];
int line[1005];
int point[1005];
int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		int ans = 0;
		cin >> n;
		vec.clear();
		for (int i = 0; i < n; i++) {
			point[i] = 1;
			parent[i] = i;
			line[i] = 0;
			for (int j = i + 1; j < n; j++) {
				cin >> f[i][j];
				f[j][i] = f[i][j];
				stru temp;
				temp.length = f[i][j];
				temp.s = i;
				temp.e = j;
				vec.push_back(temp);
			}
		}
		sort(vec.begin(), vec.end(), bigyo);
		vector<int> temp;
		for (int i = 0; i < vec.size(); i++) {
			int a = find(vec[i].s);
			int b = find(vec[i].e);
			if (a != b) {
				merge(a, b);
				a = find(a);
				line[a] += line[b];
				line[a]++;
				point[a] += point[b];
				line[b] = point[b] = 0;
			}
			else {
				line[a]++;
			}
			temp.push_back(a);
			if (i != vec.size() - 1 && vec[i].length == vec[i + 1].length) {
				continue;
			}
			sort(temp.begin(), temp.end());
			int pre = -1;
			for (auto k : temp) {
				if (pre == k || k != find(k)) {
					continue;
				}
				pre = k;
				if (line[k] == (point[k] * (point[k] - 1)) / 2) {
					ans++;
				}
			}
			temp.clear();
		}
		ans--;
		cout << ans << "\n";
	}
	return 0;
}