#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  ll n, k;
  cin >> n >> k;
  set<ll> a;
  for (int i = 0; i < n; i++) {
    ll e;
    cin >> e;
    if (1 <= e && e <= k) {
      a.insert(e);
    }
  }
  ll total = (1 + k) * k / 2;
  for (ll e : a) {
    total -= e;
  }
  cout << total << endl;
  return 0;
}