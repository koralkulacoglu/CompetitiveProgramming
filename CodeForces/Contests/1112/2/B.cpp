#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int firstHalf = (k + 1) / 2;
  int secondHalf = k / 2;

  string res;
  for (int i = 0; i < firstHalf + 1; i++)
    res.push_back('0');
  for (int i = 0; i < secondHalf + 1; i++)
    res.push_back('1');

  int rem = n - res.size();

  for (int i = 0; i < rem; i++) {
    char cur = res.empty() ? '0' : (res.back() == '0' ? '1' : '0');
    res.push_back(cur);
  }

  int zeros = count(res.begin(), res.end(), '0');
  int ones = count(res.begin(), res.end(), '1');

  if (res.size() != n) {
    cout << -1 << '\n';
    return;
  }

  if (abs(zeros - ones) == 2) {
    res.pop_back();
    res = '1' + res;
  }

  zeros = count(res.begin(), res.end(), '0');
  ones = count(res.begin(), res.end(), '1');

  if (abs(zeros - ones) > 1) {
    cout << -1 << '\n';
    return;
  }

  int p = 0;
  for (int i = 0; i < res.size() - 1; i++) {
    if (res[i] == res[i + 1])
      p++;
  }

  if (p != k) {
    cout << -1 << '\n';
    return;
  }

  cout << res << '\n';
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
