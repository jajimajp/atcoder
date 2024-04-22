#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n, q;
  cin >> n >> q;
  vector<bool> t(n, true);
  for (int i = 0; i < q; i++) {
    ll p;
    cin >> p;
    p--;
    t[p] = !t[p];
  }
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if (t[i]) {
      cnt++;
    }
  }
  
  cout << cnt << endl;
}