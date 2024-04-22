#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  vector<ll> le(n, 0), lo(n, 0), re(n, 0), ro(n, 0);
  // le: s[0] = 0, lo: s[0] = 1

   for (int i = 0; i < n; i++) {
    int si;
    if (s[i] == '0') si = 0;
    else si = 1;

    if (i == 0) {
      if (s[i] == '0') {
        le[0] = 0;
        lo[0] = c[0];
      } else {
        le[0] = c[0];
        lo[0] = 0;
      }
    } else {
      if (si % 2 == i % 2) {
        le[i] = le[i - 1];
        lo[i] = c[i] + lo[i - 1];
      } else {
        le[i] = c[i] + le[i - 1];
        lo[i] = lo[i - 1];
      }
    }
  }

  for (int i = n - 1; 0 <= i; i--) {
    int si;
    if (s[i] == '0') si = 0;
    else si = 1;

    if (i == n - 1) {
      if (si % 2 == i % 2) {
        re[n - 1] = 0;
        ro[n - 1] = c[n - 1];
      } else {
        re[n - 1] = c[n - 1];
        ro[n - 1] = 0;
      }
    } else {
      if (si % 2 == i % 2) {
        re[i] = re[i + 1];
        ro[i] = c[i] + ro[i + 1];
      } else {
        re[i] = c[i] + re[i + 1];
        ro[i] = ro[i + 1];
      }
    }
  }
  long long mins = 9223372036854775806;
  for (int i = 0; i < n - 1; i++) {
    // s[i] == s[i + 1]
    long long score = min(le[i] + ro[i + 1], lo[i] + re[i + 1]);
    mins = min(mins, score);
  }

  cout << mins << endl;

  return 0;
}