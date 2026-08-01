#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n % 2) {
    cout << "NO\n";
    return;
  }

  int lb = -1e9, ub = 1e9;
  for (int i = 0; i < n; i += 2) {
    int left = a[i];
    int right = a[i + 1];
    lb = max(lb, right + 1);
    ub = min(ub, left - 1);
  }

  bool valid = (lb <= ub);

  cout << (valid ? "YES" : "NO") << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}