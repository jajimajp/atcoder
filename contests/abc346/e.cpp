#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  ll h, w, m;
  cin >> h >> w >> m;
  vector<int> t(m), a(m), x(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> a[i] >> x[i];
  }

  set<int> filled_row, filled_col;
  map<int, ll> count;

  for (int i = m - 1; 0 <= i; i--) {
    if (t[i] == 1) {
      if (filled_row.count(a[i]) == 0) {
        filled_row.insert(a[i]);
        if (count.count(x[i]) > 0) {
          count[x[i]] += w - filled_col.size();
        } else {
          count.insert({ x[i], (w - filled_col.size()) });
        }
      }
    } else {
      if (filled_col.count(a[i]) == 0) {
        filled_col.insert(a[i]);
        if (count.count(x[i]) > 0) {
          count[x[i]] += h - filled_row.size();
        } else {
          count.insert({ x[i], (h - filled_row.size()) });
        }
      }
    }
  }

  // デフォルトで 0
  ll fcnt = 0;
  for (auto [k, v] : count) {
    fcnt += v;
  }

  if (count.count(0) > 0) {
    count[0] = count[0] + h * w - fcnt;
  } else {
    count.insert({ 0, h * w - fcnt });
  }

  vector<ll> ans;
  for (int i = 0; i < 200100; i++) {
    if (count.count(i) > 0 && count[i] > 0) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (auto k : ans) {
    cout << k << " " << count[k] << endl;
  }

  return 0;
}