#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> x(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i];
  }

  set<ll> s;
  ll tot = 0; // |S| の総和
  vector<ll> st(n + 1, 0); // 追加時のtot
  vector<ll> a(n + 1, 0);

  for (int i = 0; i < q; i++) {
    if (s.count(x[i]) == 0) {
      // 追加
      s.insert(x[i]);
      st[x[i]] = tot;
    } else {
      s.erase(x[i]);
      a[x[i]] += (tot - st[x[i]]);
    }

    tot += s.size();
  }

  for (auto e : s) {
    a[e] += tot - st[e];
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i];
    if (i < n) {
      cout << " ";
    }
  }
  cout << endl;
}