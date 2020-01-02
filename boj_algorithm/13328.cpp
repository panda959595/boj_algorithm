#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> > vec_pow(vector< vector<int> > vec, int k) {
	if (k == 1) {
		return vec;
	}
	if (k % 2 == 0) {
		vector< vector<int> > temp(vec.size(), vector<int>(vec.size()));
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				temp[i][j] = 0;
				for (int k = 0; k < vec.size(); k++) {
					temp[i][j] += vec[i][k] * vec[k][j];
					temp[i][j] %= 31991;
				}
			}
		}
		return vec_pow(temp, k / 2);
	}
	else {
		vector< vector<int> > temp(vec.size(), vector<int>(vec.size()));
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				temp[i][j] = 0;
				for (int k = 0; k < vec.size(); k++) {
					temp[i][j] += vec[i][k] * vec[k][j];
					temp[i][j] %= 31991;
				}
			}
		}
		temp = vec_pow(temp, k / 2);
		vector< vector<int> > ret(vec.size(), vector<int>(vec.size()));
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				ret[i][j] = 0;
				for (int k = 0; k < vec.size(); k++) {
					ret[i][j] += vec[i][k] * temp[k][j];
					ret[i][j] %= 31991;
				}
			}
		}
		return ret;
	}
}
int main() {
	int d, t;
	cin >> d >> t;
	vector< vector<int> > vec;
	vector<int> vec_temp;
	for (int i = 0; i < d; i++) {
		vec_temp.push_back(1);
	}
	vec.push_back(vec_temp);
	for (int i = 0; i < d - 1; i++) {
		vec_temp.clear();
		for (int j = 0; j < d; j++) {
			if (i == j) {
				vec_temp.push_back(1);
			}
			else {
				vec_temp.push_back(0);
			}
		}
		vec.push_back(vec_temp);
	}
	vec = vec_pow(vec, t);
	cout << vec[0][0] << endl;
	return 0;
}