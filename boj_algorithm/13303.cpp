#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int x;
	int yl, yh;
};
bool bigyo(stru a, stru b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		return a.yl < b.yl;
	}
}
vector<stru> hudle;
int n;
long long ans;
int finish;
vector<int> ans_vec;
void func(int x, int y, long long mv) {
	if (ans < mv) {
		return;
	}
	if (x == finish) {
		if (ans == mv) {
			ans_vec.push_back(y);
		}
		else if (ans > mv) {
			ans = mv;
			ans_vec.clear();
			ans_vec.push_back(y);
		}
		return;
	}
	stru temp = { x - 1, y  , y };
	bool flag = true;
	for (vector<stru>::iterator ite = lower_bound(hudle.begin(), hudle.end(), temp, bigyo); ite->x == x; ite++) {
		if (ite->yh >= y && ite->yl <= y) {
			temp.x += 2;
			temp.yl = -1;
			flag = false;
			func((upper_bound(hudle.begin(), hudle.end(), temp, bigyo))->x, ite->yh, mv + abs(ite->yh - y));
			func((upper_bound(hudle.begin(), hudle.end(), temp, bigyo))->x, ite->yl, mv + abs(ite->yl - y));
			break;
		}
	}
	if (flag) {
		temp.x += 2;
		func((upper_bound(hudle.begin(), hudle.end(), temp, bigyo))->x, y, mv);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int start;
	cin >> start >> finish;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		hudle.push_back({ a,b,c });
	}
	sort(hudle.begin(), hudle.end(), bigyo);
	hudle.push_back({ finish,0,0 });
	ans = 1 << 30;
	ans <<= 30;
	func(hudle[0].x, start, 0);
	sort(ans_vec.begin(), ans_vec.end());
	int output = 0;
	int before = -1;
	for (int i = 0; i < ans_vec.size(); i++) {
		if (before == ans_vec[i]) {
			continue;
		}
		before = ans_vec[i];
		output++;
	}
	before = -1;
	cout << ans + finish << "\n" << output;
	for (int i = 0; i < ans_vec.size(); i++) {
		if (before == ans_vec[i]) {
			continue;
		}
		before = ans_vec[i];
		cout << " " << ans_vec[i];
	}
	cout << "\n";
	return 0;
}