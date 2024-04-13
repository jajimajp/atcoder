#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, q;
  string s;
  cin >> n >> q;
  cin >> s;

  std::set<int> chan;
  vector<bool> con(n, false);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      con[i] = i % 2 == 0;
    } else {
      con[i] = i % 2 == 1;
    }
  }

  bool cur = con[0];
  for (int i = 1; i < n; i++) {
    if (cur != con[i]) {
      chan.insert(i);
      cur = con[i];
    }
  }

  for (int i = 0; i < q; i++) {
    int j, l, r;
    cin >> j >> l >> r;
    l--;
    r--;
    if (j == 1) {
      if (0 < l) {
        if (chan.count(l) > 0) {
          chan.erase(l);
        } else {
          chan.insert(l);
        }
      }
      if (chan.count(r + 1) > 0) {
        chan.erase(r + 1);
      } else {
        chan.insert(r + 1);
      }
    } else {
      auto it = chan.lower_bound(l + 1);
      if (it == chan.end() || *it > r) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
