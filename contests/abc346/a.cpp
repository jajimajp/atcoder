#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << (a[i] * a[i + 1]);
  }
  cout << endl;
}