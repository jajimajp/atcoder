#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] % k == 0) {
      ans.push_back(a[i] / k);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i < ans.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}