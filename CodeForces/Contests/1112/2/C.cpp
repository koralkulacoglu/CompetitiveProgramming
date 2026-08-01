#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> vals(n, vector<int>(4));
  for (int i = 0; i < n; i++) {
    cin >> vals[i][0] >> vals[i][1] >> vals[i][2] >> vals[i][3];
  }

  auto isValid = [&](int m) {
    int elements = 0;
    if (elements == m)
      return true;

    for (int i = 0; i < n; i++) {
      int l = vals[i][0];
      int r = vals[i][1];
      int u = vals[i][2];
      int v = vals[i][3];

      int leftRank = elements + 1;
      if (l <= leftRank && r >= leftRank)
        continue;

      int rightRank = m - elements;
      if (u <= rightRank && v >= rightRank)
        continue;

      elements++;

      if (elements == m)
        return true;
    }

    return false;
  };

  for (int k = n; k >= 0; k--) {
    if (isValid(k)) {
      cout << k << '\n';
      return;
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
