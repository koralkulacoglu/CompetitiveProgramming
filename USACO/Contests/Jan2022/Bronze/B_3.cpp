#include <bits/stdc++.h>
 
using namespace std;
 
int game(vector<int> a, vector<int> b) {
	int as=0, bs=0;
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			as += (a[i] > b[j]);
		}
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			bs += (b[i] > a[j]);
		}
	}
	if (as > bs) return 1;
	if (bs > as) return -1;
	return 0;
}
 
// this would be an interesting problem without brute force
// n-sided die for example
void solve() {
	vector<int> a(4), b(4), c(4);
	for (int i=0; i<4; i++)
		cin >> a[i];
	for (int i=0; i<4; i++)
		cin >> b[i];

	for (int i=1; i<=10; i++) {
		for (int j=1; j<=10; j++) {
			for (int k=1; k<=10; k++) {
				for (int l=1; l<=10; l++) {
					c[0] = i;
					c[1] = j;
					c[2] = k;
					c[3] = l;

					int ab = game(a, b);
					int bc = game(b, c);
					int ca = game(c, a);

					if ((ab==1) && (bc==1) && (ca==1)) {
						cout << "yes\n";
						return;
					}
					if ((ab==-1) && (bc==-1) && (ca==-1)) {
						cout << "yes\n";
						return;
					}
				}
			}
		}
	}
	cout << "no\n";
}
 
int main() {
    int T;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}

