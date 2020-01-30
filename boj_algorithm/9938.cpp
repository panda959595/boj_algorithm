#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
bool check[300005];
bool dra_check[300005];
vector<int> vec[300005];
int arr[300005][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("test_case/ladice.in.6a", "r", stdin);
	freopen("test_case/out.6a", "w", stdout);
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(i);
		vec[b].push_back(i);
		arr[i][0] = a;
		arr[i][1] = b;
	}
	for (int i = 0; i < n; i++) {
		priority_queue<int, vector<int>, greater<int> > pq;
		int temp = 0;
		for (int j = 0; j < 2; j++) {
			if (dra_check[arr[i][j]]) {
				continue;
			}
			for (int k = 0; k < vec[arr[i][j]].size(); k++) {
				pq.push(vec[arr[i][j]][k]);
			}
			temp++;
			dra_check[arr[i][j]] = true;
		}
		while (!pq.empty()) {
			int now = pq.top();
			pq.pop();
			if (!pq.empty() && now == pq.top()) {
				if (temp > 0) {
					check[now] = true;
					temp--;
				}
				pq.pop();
				continue;
			}
			for (int j = 0; j < 2; j++) {
				if (dra_check[arr[now][j]]) {
					continue;
				}
				for (int k = 0; k < vec[arr[now][j]].size(); k++) {
					pq.push(vec[arr[now][j]][k]);
				}
				dra_check[arr[now][j]] = true;
				temp++;
			}
			pq.push(now);
		}
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) {
			cout << "LADICA\n";
		}
		else {
			cout << "SMECE\n";
		}
	}
	return 0;
}