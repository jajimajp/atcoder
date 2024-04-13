#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;

  vector<int> a(n), c(n);

  map<int, int> m; // color, minval
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
  }
  for (int i = 0; i < n; i++) {
    if (m.count(c[i]) > 0) {
      m[c[i]] = min(m[c[i]], a[i]);
    } else {
      m[c[i]] = a[i];
    }
  }

  int maxval = 0;
  for (auto kv : m) {
    maxval = max(kv.second, maxval);
  }

  cout << maxval << endl;
}