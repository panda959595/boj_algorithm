#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int start, end, hash;
	bool operator<(stru a) {
		return hash < a.hash;
	}
	bool operator>(stru a) {
		return hash > a.hash;
	}
	bool operator==(stru a) {
		return hash == a.hash;
	}
};
vector<stru> arr[1505];
vector<stru> brr[1505];
bool bigyo(stru a, stru b) {
	if(a.hash!=b.hash)
		return a.hash < b.hash;
	else {
		return true;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	int temp = 0;
	for (int i = 0; i < a.length(); i++) {//시작
		temp = 0;
		for (int j = i; j < a.length(); j++) {//끝
			temp += a[j] * a[j];
			arr[j - i + 1].push_back({ i,j,temp });
		}
	}
	for (int i = 0; i < b.length(); i++) {//시작
		temp = 0;
		for (int j = i; j < b.length(); j++) {//끝
			temp += b[j] * b[j];
			brr[j - i + 1].push_back({ i,j,temp });
		}
	}
	for (int i = 0; i < 1505; i++) {
		sort(arr[i].begin(), arr[i].end());
		sort(brr[i].begin(), brr[i].end());
	}
	int ans = 0;
	for (int i = a.length(); i >= 1; i--) {
		for (auto k : arr[i]) {
			for (vector<stru>::iterator ite = lower_bound(brr[i].begin(), brr[i].end(), k); ite != brr[i].end() && k.hash == ite->hash; ite++) {
				int alpa[26] = { 0, };
				int blpa[26] = { 0, };
				for (int j = 0; j < i; j++) {
					alpa[a[k.start + j] - 'a']++;
					blpa[b[ite->start + j] - 'a']++;
				}
				bool flag = true;
				for (int i = 0; i < 26;i++){
					if (alpa[i] != blpa[i]) {
						flag = false;
					}
				}
				if (flag) {
					ans = i;
					goto here;
				}
			}
		}
	}
here:
	cout << ans << "\n";
	return 0;
}