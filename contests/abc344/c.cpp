#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n, m, l;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++)
    cin >> b[i];
  cin >> l;
  vector<int> c(l);
  for (int i = 0; i < l; i++)
    cin >> c[i];
  
  int q;
  cin >> q;
  vector<int> x(q);
  for (int i = 0; i < q; i++)
    cin >> x[i];
  
  set<ll> ok;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < l; k++) {
        ok.insert(a[i] + b[j] + c[k]);
      }
    }
  }

  for (int i = 0; i < q; i++) {
    if (ok.count(x[i]) > 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}