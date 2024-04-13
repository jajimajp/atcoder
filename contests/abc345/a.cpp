#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string s;
  cin >> s;
  if (s[0] != '<') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < s.length() - 1; ++i) {
    if (s[i] != '=') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (s[s.length() - 1] != '>') {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
  
}