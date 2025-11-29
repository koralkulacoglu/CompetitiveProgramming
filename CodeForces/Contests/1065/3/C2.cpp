/*
ID: Koral Kulacoglu
TASK: Renako Amaori and XOR Game (Hard)
LANG: C++                 
*/

#pragma GCC optimize ("O3")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i, a, b) for (int i=(a)-1; i >= b; i--)
#define all(x) x.begin(), x.end()
 
const char nl = '\n';

void solve() {
	int n; cin >> n;
	vi a(n); FOR (i, 0, n) cin >> a[i];
	vi b(n); FOR (i, 0, n) cin >> b[i];

    // Check bits from MSB to LSB (assuming max value < 2^30)
    for (int k = 29; k >= 0; k--) {
        int totalOnes = 0;
        // Calculate total set bits at position k across both arrays
        // Actually we only care if there is an odd number of differing pairs
        // But checking total ones parity is equivalent.
        // Let's just verify the "differing pairs" count directly?
        // count of (A[i] bit k) + count of (B[i] bit k) is odd implies
        // count of pairs where bits differ is odd.
        
        int diffCount = 0;
        int lastDiffIdx = -1;
        
        FOR (i, 0, n) {
            int bitA = (a[i] >> k) & 1;
            int bitB = (b[i] >> k) & 1;
            if (bitA != bitB) {
                diffCount++;
                lastDiffIdx = i;
            }
        }

        if (diffCount % 2 != 0) {
            // This bit decides the winner
            // lastDiffIdx is the largest index where bits differ
            if ((lastDiffIdx + 1) % 2 != 0) cout << "Ajisai" << nl;
            else cout << "Mai" << nl;
            return;
        }
    }

    // If no bit has odd differing count, then for all bits, X_A and X_B match
	cout << "Tie" << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);
 
    int T = 1;
	cin >> T;
    while(T--) {
        solve();
    }
 
	return 0;
}
