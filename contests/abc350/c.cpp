#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<ll> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    pos[a[i]] = i;
    b[i] = a[i];
  }
  sort(b.begin(), b.end());

  vector<pair<int, int>> mv;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != b[i]) {
      int bind = pos[b[i]];

      // swap
      mv.push_back({ i + 1, bind + 1 });
      a[bind] = a[i];
      pos[a[i]] = bind;
      a[i] = b[i];
      pos[a[i]] = i;
    }
  }

  cout << mv.size() << endl;
  for (auto [a, b] : mv) {
    cout << a << " " << b << endl;
  }
}