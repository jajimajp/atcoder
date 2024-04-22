#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> twos;
vector<pair<ll, ll>> ans;

void s(ll l, ll r) {
  for (size_t i = 0; i < twos.size(); i++) {
    // あやしい
    ll btm = l / twos[i];
    if (btm * twos[i] < l) {
      btm++;
    }
    ll nl = btm * twos[i];
    ll nr = (btm + 1L) * twos[i];
    if (l <= nl && nr <= r) {
      // bef
      if (l < nl) {
        s(l, nl);
      }
      ans.push_back({ nl, nr });
      // af
      if (nr < r) {
        s(nr, r);
      }
      return;
    }
  }

  ans.push_back({ l, r });
}

int main() {
  ll l, r;
  cin >> l >> r;

  ll tmp = 1;
  for (int i = 0; i < 61; i++) {
    twos.push_back(tmp);
    tmp *= 2;
  }

  reverse(twos.begin(), twos.end());

  // dbg
  // for (ll e : twos) {
  //   cout << e << endl;
  // }

  s(l, r);

  cout << ans.size() << endl;
  for (auto [a, b] : ans) {
    cout << a << " " << b << endl;
  }

  return 0;
}
