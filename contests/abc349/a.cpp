#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  ll n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n - 1; i++) {
    ll e;
    cin >> e;
    sum += e;
  }

  cout << (-1 * sum) << endl;

  return 0;
}
