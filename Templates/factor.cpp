#include <vector>

using namespace std;

vector<int> factor(int n) {
	vector<int> divisors;
	for (int i=2; i*i<=n; i++) {
		while (n % i == 0) {
			divisors.push_back(i);
			n /= i;
		}
	}
	if (n > 1) divisors.push_back(n);
	return divisors;
}

