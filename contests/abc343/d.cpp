#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(t), b(t);
  for (int i = 0; i < t; i++) {
    cin >> a[i] >> b[i];
    --a[i]; // 0-idx
  }

  vector<long long> points(n, 0);
  map<long long, int> mems;

  int vars = 1;
  mems.insert(make_pair(0, n));

  for (int i = 0; i < t; ++i) {
    long long prv = points[a[i]];
    long long nxt = prv + b[i];

    points[a[i]] = nxt;

    if (mems[prv] == 1) {
      mems.erase(prv);
      vars--;
    } else {
      mems[prv]--;
    }

    if (mems.count(nxt) == 0) {
      mems.insert(make_pair(nxt, 1));
      vars++;
    } else {
      mems[nxt]++;
    }

    cout << vars << endl;
  }
}
