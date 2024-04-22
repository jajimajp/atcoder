#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<ll, double> mm;
ll n, a;
double x, y;

double ex(ll e) {
  if (e <= 0) {
    return 0.0;
  }
  if (mm.count(e) > 0) {
    return mm[e];
  }

  // pre
  double pre = 0.0;
  if ((e / a) <= 0) {
    pre = x;
  } else {
    pre = x + ex(e / a);
  }

  // af
  double af = 0.0;
  // 1 : me
  // x = Y + (x + ...)/6
  // 5/6 x = Y + .../6
  // x = ... / 5 + Y * 6/5
  for (int i = 2; i <= 6; i++) {
    if ((e / i) > 0) {
      af += ex(e / i);
    }
  }
  af = af / 5.0 + y * 6.0 / 5.0;
  

  double v;
  if (pre < af) {
    v = pre;
  } else {
    v = af;
  }
  mm.insert({ e, v });
  return mm[e];
}

int main() {
  cin >> n >> a >> x >> y;
  mm = map<ll, double>();
  double ans = ex(n);
  printf("%.15f\n", ans);
}