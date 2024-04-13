#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<string>> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.push_back(vector<string>(a[i]));
    for (int j = 0; j < a[i]; j++) {
      cin >> s[i][j];
    }
  }

  int tlen = t.length();
  // dp[i][j] i個目までの袋で、j文字目の直前まで作る最小金額
  // -1: 作成不可能
  vector<vector<int>> dp(n + 1, vector<int>(tlen + 1, -1));

  int mincost = 10000; // 完成させる最小コスト
  for (int i = 0; i < n; i++) { // 100
    if (i == 0) {
      for (int j = 0; j < a[i]; j++) {
        if (s[0][j].length() > tlen) {
          continue;
        }
        bool ok = true;
        for (int idx = 0; idx < s[0][j].length(); idx++) {
          if (s[0][j][idx] != t[idx]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dp[0][s[0][j].length()] = 1;
          if (s[0][j].length() == tlen) {
            mincost = 1;
          }
        }
      }
      dp[0][0] = max(0, dp[0][0]);
      continue;
    }
    // i > 0
    // 何もしない
    for (int j = 0; j < tlen; j++) { // 100
      dp[i][j] = dp[i - 1][j];
    }
    // pick 1
    for (int j = 0; j < tlen; j++) { // 100
      if (dp[i - 1][j] == -1) {
        continue;
      }
      for (int k = 0; k < a[i]; k++) { // 10
        if (j + s[i][k].length() > tlen) {
          continue;
        }
        bool ok = true;
        for (int l = 0; l < s[i][k].length(); l++) { // 10
          if (s[i][k][l] != t[j + l]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          if (dp[i][j+s[i][k].length()] == -1) {
            dp[i][j+s[i][k].length()] = dp[i-1][j] + 1;
          } else {
            dp[i][j+s[i][k].length()] = min(dp[i][j+s[i][k].length()], dp[i-1][j] + 1);
          }
          if (j + s[i][k].length() == tlen) {
            mincost = min(mincost, dp[i][j+s[i][k].length()]);
          }
        }
      }
    }
  }

  if (mincost == 10000) {
    cout << -1 << endl;
  } else {
    cout << mincost << endl;
  }
}