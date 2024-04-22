#include <bits/stdc++.h>

using namespace std;

#define ll long long

// start: 23:28
// end  : 24:21
// time : 53min

#define MOD 998244353L

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--; // to 0-idxed
  }
  string s;
  cin >> s;

  vector<vector<ll>> picks(2, vector<ll>(n, 0));
  vector<bool> sp(n, true); // スプーンがある
  for (bool right : {true, false}) {
    for (int i = 0; i < n; i++) {
      sp[i] = true;
    }
    for (int i = 0; i < n; i++) {
      if (s[p[i]] == 'R') {
        if (!right && sp[(p[i] + 1)%n]) {
          picks[right][p[i]] = 0;
          break;
        }
        picks[right][p[i]] = 1;
      }
      if (s[p[i]] == 'L') {
        if (right && sp[p[i]]) {
          picks[right][p[i]] = 0;
          break;
        }
        picks[right][p[i]] = 1;
      }
      if (s[p[i]] == '?') {
        if (right && (!sp[p[i]]) || (!right) && (!sp[(p[i] + 1) % n])) {
          picks[right][p[i]] = 2;
        } else {
          picks[right][p[i]] = 1;
        }
      }
      sp[(p[i] + right) % n] = false;
    }
  }

  ll ans_l = 1;
  ll ans_r = 1;
  for (int i = 0; i < n; i++) {
    ans_l = (ans_l * picks[0][i]) % MOD;
  }
  for (int i = 0; i < n; i++) {
    ans_r = (ans_r * picks[1][i]) % MOD;
  }
  ll ans = (ans_l + ans_r) % MOD;

  cout << ans << endl;
  return 0;
}
