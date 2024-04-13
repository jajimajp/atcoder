#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll popcount(ll n) {
  ll ret = 0;
  for (ll i = 0; (1ll << i) <= n; ++i) {
    if (n & (1ll << i)) {
      ret++;
    }
  }

  return ret;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll cpk = popcount(c);
  ll aff = 60 - cpk; // 相殺に使える箇所数

  // 1 が足りない
  if (a + b < cpk) {
    cout << -1 << endl;
    return 0;
  }
  // 相殺で作れない
  if (max(a, b) - min(a, b) > cpk) {
    cout << -1 << endl;
    return 0;
  }

  // 偶数の相殺で作れない
  if ((max(a, b) + min(a, b) - cpk) % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }

  ll del = (max(a, b) + min(a, b) - cpk) / 2;

  // 相殺箇所が足りない
  if (del > aff) {
    cout << -1 << endl;
    return 0;
  }

  // 下位から見て、1のところでは、まずaから消費、次にb
  // 0のところでは、相殺個数までは1,1 それ以降0,0
  ll aval = 0;
  ll bval = 0;
  ll acnt = a - del;
  ll bcnt = b - del;
  ll delcnt = del;
  for (int i = 0; i <= 60; i++) {
    ll sft = 1ll << i;
    if (sft & c) { // should be 1
      if (acnt > 0) {
        aval += sft;
        acnt--;
      } else {
        bval += sft;
        bcnt--;
      }
    } else { // should be 0
      if (delcnt > 0) {
        aval += sft;
        bval += sft;
        delcnt--;
      }
    }
  }

  cout << aval << " " << bval << endl;
}