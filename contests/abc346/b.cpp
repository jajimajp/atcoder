#include <bits/stdc++.h>

using namespace std;

int main() {
  string s = "wbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw";
  int w, b;
  cin >> w >> b;
  int len = w + b;
  for (int st = 0; st < 16; st++) {
    int cw = 0, cb = 0;
    for (int i = st; i < st + len; i++) {
      if (s[i] == 'w') {
        cw++;
      } else {
        cb++;
      }
    }
    if (cw == w && cb == b) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}