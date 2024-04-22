#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string s;
  cin >> s;
  map<char, int> m;
  for (auto c : s) {
    if (m.count(c) > 0) {
      m[c]++;
    } else {
      m.insert({ c, 1 });
    }
  }

  vector<int> nth(101, 0);
  for (auto [k, v] : m) {
    nth[v]++;
  }

  for (int i = 0; i < 101; i++) {
    if (nth[i] == 0 || nth[i] == 2) {
      continue;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
