#include <bits/stdc++.h>

using namespace std;

#define ll long long

// start: 9:32
// gave up  : 10:22 
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  // memoize up and down
  vector<ll> ud(n, 0);
  ll base = 0; // 全体の補正
  // ２段階で増加・減少をメモ
  // lowerbound, 数
  map<ll, ll> memo;

  // i = 0
  ll l = b[0] + 1, r = b[0] + a[b[0]]; // maybe (> n)
  while ((r - l) >= n) {
    r -= n;
    base++;
  }
  // maybe (l == r)
  l = l % n;
  r = (r + 1) % n; // 次から減る
  ud[l]++;
  ud[r]--;

  if (l == r) {
    memo.insert({ 0, 0 });
  } else {
    memo.insert({ l, 1 });
    memo.insert({ r, 0 });
  }

  for (int i = 1; i < m; i++) {
    // その箇所にある個数
    // base + memo_lower
    ll pre = base;
    ll lower = 0;
    ll idxval = 0;
    auto up = memo.upper_bound(b[i]);
    if (up == memo.begin()) {
      idxval = memo[memo.size() - 1];
    } else {
      idxval = (*(up--)).second;
    }
    pre += idxval;

    cout << "DBG i: " << i << ", pre: " << pre << endl;

    l = b[i] + 1;
    r = b[i] + pre;
    while (r - l >= n) {
      r -= n;
      base++;
    }



  }
  
  cout << n << endl;
  return 0;
}
