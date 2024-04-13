#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<ll>> rs(n, vector<ll>(n, 0)); // 頂点 i, j から右 m 個の和
  for (int i = 0; i < n; i++) {
    ll sm = 0;
    for (int j = 0; j < n; j++) {
      sm += a[i][j];
      if (j + 1 >= m) {
        rs[i][j - m + 1] = sm;
      }
      if (j - m + 1 >= 0) {
        sm -= a[i][j - m + 1];
      }
    }
  }

  vector<vector<ll>> sq(n, vector<ll>(n, 0)); // 頂点 i, j からmの和
  for (int i = 0; i < n; i++) {
    ll sm = 0;
    for (int j = 0; j < n; j++) {
      sm += rs[j][i];
      if (j + 1 >= m) {
        sq[j - m + 1][i] = sm;
      }
      if (j - m + 1 >= 0) {
        sm -= rs[j - m + 1][i];
      }
    }
  }

  ll ans = 0;
  for (int ai = 0; ai < n; ai++) {
    if (ai + m > n) { continue; }
  for (int aj = 0; aj < n; aj++) {
    if (aj + m > n) { continue; }
  for (int bi = 0; bi < n; bi++) {
    if (bi + m > n) { continue; }
  for (int bj = 0; bj < n; bj++) {
    if (bj + m > n) { continue; }
    if (ai + m <= bi - 1 && aj + m <= bj - 1) { continue; }
  for (int ci = 0; ci < n; ci++) {
    if (ci + m > n) { continue; }
  for (int cj = 0; cj < n; cj++) {
    if (cj + m > n) { continue; }
    if (bi + m <= ci - 1 && bj + m <= cj - 1) { continue; }
    ans = max(ans, sq[ai][aj] + sq[bi][bj] + sq[ci][cj]);
  }



  }

  }

  }

  }

  }

  cout << ans << endl;
}