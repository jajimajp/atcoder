#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string s;
  cin >> s;
  
  bool in = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '|') {
      if (in) {
        in = false;
        continue;
      } else {
        in = true;
        continue;
      }
    }

    if (in)
      continue;
    
    cout << s[i];
  }
  cout << endl;
}