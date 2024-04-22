#include <bits/stdc++.h>

using namespace std;

#define ll long long

// start: 0:29
// end  : 0:57
// time : 28 min
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  // 2 * 10-^5 までの素数
  vector<ll> is_prime(200002, true);
  vector<ll> primes;
  for (int i = 2; i < 200001; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= 200001; j += i) {
        is_prime[j] = false;
      }
      primes.push_back(i);
    }
  }

  map<ll, ll> m;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (m.count(0) > 0) {
        m[0]++;
      } else {
        m.insert({ 0, 1 });
      }
    } else {
      for (auto p : primes) {
        if (p * p > a[i]) {
          break;
        }
        while (p * p <= a[i] && (a[i] % (p * p) == 0)) {
          a[i] /= p * p;
        }
      }
      if (m.count(a[i]) > 0) {
        m[a[i]]++;
      } else {
        m.insert({ a[i], 1 });
      }
    }
  }

  ll ans = 0;
  for (auto [k, c] : m) {
    if (k == 0) {
      ans += (c * (c - 1) / 2) + (c * (n - c));
    } else {
      ans += (c * (c - 1) / 2);
    }
  }
  
  cout << ans << endl;

  return 0;
}
