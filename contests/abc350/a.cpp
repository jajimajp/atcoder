#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  char c;
  cin >> c >> c >> c;
  ll n;
  cin >> n;

  if (n == 316 || n == 0) {
    cout << "No" << endl;
    return 0;
  }
  if (n <= 349) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}