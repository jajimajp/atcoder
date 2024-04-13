#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  vector<int> a;
  while (true) {
    int i;
    cin >> i;
    a.push_back(i);
    if (i == 0) break;
  }
  for (int i = a.size() - 1; 0 <= i; i--) {
    cout << a[i] << endl;
  }
}