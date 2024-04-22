#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  // 長さ3の部分文字
  size_t ti = 0;
  size_t si = 0;
  while (si < s.length()) {
    if (t[ti] == s[si] + ('A' - 'a')) {
      si++;
      ti++;
      if (ti == 3) {
        cout << "Yes" << endl;
        return 0;
      }
    } else {
      si++;
    }
  }

  // 長さ2 + 'X'
  if (t[2] == 'X') {
    ti = 0;
    si = 0;
    while (si < s.length()) {
      if (t[ti] == s[si] + ('A' - 'a')) {
        si++;
        ti++;
        if (ti == 2) {
          cout << "Yes" << endl;
          return 0;
        }
      } else {
        si++;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
