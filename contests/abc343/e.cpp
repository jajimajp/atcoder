#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct area {
  bool emp;
  int al;
  int ar;
  int bl;
  int br;
  int cl;
  int cr;
};

area dup(area v1, area v2) {
  area d;
  d.emp = false;
  if (v1.emp || v2.emp) {
    d.emp = true;
    return d;
  }
  if (v1.al < v2.al) {
    d.al = v2.al;
    d.ar = v1.ar;
    int len = v1.ar - v2.al;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  } else {
    d.al = v1.al;
    d.ar = v2.ar;
    int len = v2.ar - v1.al;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  }
  if (v1.bl < v2.bl) {
    d.bl = v2.bl;
    d.br = v1.br;
    int len = v1.br - v2.bl;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  } else {
    d.bl = v1.bl;
    d.br = v2.br;
    int len = v2.br - v1.bl;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  }
  if (v1.cl < v2.cl) {
    d.cl = v2.cl;
    d.cr = v1.cr;
    int len = v1.cr - v2.cl;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  } else {
    d.cl = v1.cl;
    d.cr = v2.cr;
    int len = v2.cr - v1.cl;
    if (len <= 0) {
      d.emp = true;
      return d;
    }
  }
  return d;
}

int sz(area v) {
  if (v.emp) {
    return 0;
  } else {
    return (v.ar - v.al) * (v.br - v.bl) * (v.cr - v.cl);
  }
}

// returns v1, v2, v3
tuple<int, int, int> calc(area v1, area v2, area v3) {
  area v12 = dup(v1, v2);
  area v23 = dup(v2, v3);
  area v31 = dup(v3, v1);
  area v123 = dup(v12, v23);
  int V3 = sz(v123);
  int V2 = sz(v12) + sz(v23) + sz(v31) - (3 * V3);
  int V1 = sz(v1) + sz(v2) + sz(v3) - (2 * V2) - (3 * V3);
  return {V1, V2, V3};
}

int main() {
  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  area x1 = {false, 0, 7, 0, 7, 0, 7};
  // x1 固定、 a2 <= a3
  for (int a2 = -7; a2 <= 7; a2++) {
    for (int b2 = -7; b2 <= 7; b2++) {
      for (int c2 = -7; c2 <= 7; c2++) {
        for (int a3 = -7; a3 <= 7; a3++) {
          for (int b3 = -7; b3 <= 7; b3++) {
            for (int c3 = -7; c3 <= 7; c3++) {
              area x2 = {false, a2, a2 + 7, b2, b2 + 7, c2, c2 + 7};
              area x3 = {false, a3, a3 + 7, b3, b3 + 7, c3, c3 + 7};
              auto [V1, V2, V3] = calc(x1, x2, x3);
              if (V1 == v1 && V2 == v2 && V3 == v3) {
                cout << "Yes" << endl;
                cout << "0 0 0 " << a2 << " " << b2 << " " << c2 << " " << a3
                     << " " << b3 << " " << c3 << endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
