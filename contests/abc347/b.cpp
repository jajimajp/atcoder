#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  vector<ll> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  ll ab = a + b;

  set<ll> ds;
  vector<ll> dv;
  for (int i = 0; i < n; i++) {
    ll md = d[i] % ab;
    if (ds.count(md) == 0) {
      ds.insert(md);
      dv.push_back(md);
    }
  }

  sort(dv.begin(), dv.end());

  if (dv[dv.size() - 1] - dv[0] + 1 <= a) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < dv.size() - 1; i++) {
    if (dv[i + 1] - dv[i] > b) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}