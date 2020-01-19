#include <iostream>
#include <vector>
using namespace std;
bool check[1000005];
vector<long long> prime;
long long lpow(long long a, int b) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a;
	}
	else if (b % 2 == 0) {
		return lpow(a * a, b / 2);
	}
	else {
		long long temp = lpow(a * a, b / 2);
		return temp * a;
	}
}
int main() {
	for (int i = 2; i < 1000000; i++) {
		if (check[i]) {
			continue;
		}
		prime.push_back(i);
		for (int j = 1; j * i < 1000000; j++) {
			check[i * j] = true;
		}
	}
	long long n;
	cin >> n;
	long long ans = n;
	bool flag = false;
	for (int i = 0; i < prime.size(); i++) {
		if (n < prime[i] * prime[i]) {
			break;
		}
		if (n % prime[i] != 0) {
			continue;
		}
		int temp = 0;
		flag = true;
		while (n % prime[i] == 0) {
			temp++;
			n /= prime[i];
		}
		ans /= prime[i];
		ans *= (prime[i] - 1);
		//ans *= lpow(prime[i], temp - 1) * (prime[i] - 1);
	}
	if (n != 1) {
		ans /= n;
		ans *= n - 1;
	}
	cout << ans << endl;
	return 0;
}