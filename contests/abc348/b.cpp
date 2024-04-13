#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n;
  cin >> n;

  vector<ll> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    ll maxdist = 0;
    ll maxidx = -1;
    for (int j = n - 1; 0 <= j; j--) {
      ll dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      if (dist >= maxdist) {
        maxdist = dist;
        maxidx = j;
      }
    }
    cout << (1 + maxidx) << endl;
  }
}