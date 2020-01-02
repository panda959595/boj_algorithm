#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct bus {
	int start;
	int end;
	int num;
};
vector<bus> vec;
bool check[500005];
bool bigyo(bus a, bus b) {
	if (a.start != b.start) {
		return a.start < b.start;
	}
	else if (a.end != b.end) {
		return a.end > b.end;
	}
	else{
		return a.num < b.num;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			vec.push_back({ a,b,i });
			vec.push_back({ a + n,b + n,i });
		}
		else if (b == 0) {
			vec.push_back({ a, n, i });
		}
		else {
			vec.push_back({ a,b + n,i });
		}
		check[i] = true;
	}
	sort(vec.begin(), vec.end(), bigyo);
	int now = 0;
	int next = now + 1;
	while (now < vec.size() && next < vec.size()) {
		if (vec[now].start > n) {
			break;
		}
		if (vec[now].end >= vec[next].end) {
			check[vec[next].num] = false;
			next++;
		}
		else {
			now = next;
			next++;
		}
	}
	for (int i = 0; i < m; i++) {
		if (check[i]) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}