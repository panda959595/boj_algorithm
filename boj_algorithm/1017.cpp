#include <iostream>
#include <vector>
using namespace std;
bool prime[2005];
vector<int> road[50];
vector<int> vec;
int n;
int main() {
	for (int i = 2; i < 2000; i++) {
		prime[i] = true;
	}
	for (int i = 2; i < 2000; i++) {
		for (int j = 2; i * j < 2000; j++) {
			prime[i * j] = false;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (prime[vec[i] + vec[j]]) {
				road[i].push_back(j);
				road[j].push_back(i);
			}
		}
	}
	return 0;
}