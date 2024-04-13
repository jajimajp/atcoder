#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  vector<int> a(n), b(n), are(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    are[i] = a[i] * b[i];
  }
  vector<int> bi;
  for (int i = 0; i < (1 << n); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sum += a[j] * b[j];
      }
    }
    if (sum == h * w) {
      bi.push_back(i);
    }
  }
  for (auto i : bi) {
    vector<pair<int, int>> ele;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        ele.push_back({ a[j], b[j] });
      }
    }

    do {
      for (int bit = 0; bit < (1 << ele.size()); bit++) {
        bool no = false;
        vector<vector<bool>> filled(h, vector<bool>(w, false));
        for (int k = 0; k < ele.size(); k++) {
          // find left-top-most false y, x
          bool checked = false;
          for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
              if (!filled[y][x]) {
                checked = true;
                int ae, be;
                if (bit & (1 << k)) {
                  ae = ele[k].first;
                  be = ele[k].second;
                } else {
                  be = ele[k].first;
                  ae = ele[k].second;
                }

                if (y + ae > h || x + be > w) {
                  no = true;
                  break;
                }
                for (int xi = 0; xi < be; xi++) {
                  for (int yi = 0; yi < ae; yi++) {
                    if (filled[ae + yi][be + xi]) {
                      no = true;
                      break;
                    }
                    filled[ae + yi][be + xi] = true;
                  }
                }
              }
            }
            if (no || checked) {
              break;
            }
          }
          if (!checked) {
            no = true;
            break;
          }
          if (no) {
            break;
          }
        }
        if (!no) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    } while (next_permutation(ele.begin(), ele.end()));
  }
  cout << "No" << endl;
}