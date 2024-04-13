#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 2) {
      cout << 'x';
    } else {
      cout << 'o';
    }
  }
  cout << endl;
}