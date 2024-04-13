#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> cv(n);
  for (int i = 0; i < n; i++) {
    int c, v;
    cin >> c >> v;
    cv[i] = { c, v };
  }

  sort(cv.begin(), cv.end(),
    [](const pair<ll, ll>& a, const pair<ll, ll>& b) { return a.second < b.second; });
  
  vector<pair<ll, ll>> red;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      red.push_back(cv[i]);
    } else {
      if (cv[i].first != cv[i + 1].first) {
        red.push_back(cv[i]);
      }
    }
  }

  k -= (n - red.size());
  if (k < 0) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i < red.size(); i++) {
    if (i >= k) {
      cout << "Pick: " << red[i].first << " " << red[i].second << endl;
      ans += red[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}