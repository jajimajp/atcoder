#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int h, w;
  cin >> h >> w;
  
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  int n;
  cin >> n;

  vector<int> r(n), c(n), e(n);
  // ２次元配列で取得
  vector<vector<int>> emap(h, vector<int>(w, 0));
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i] >> e[i];
    r[i]--;
    c[i]--;
    emap[r[i]][c[i]] = e[i];
  }
  
  int si = -1, sj = -1; // スタート地点

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }

  vector<vector<int>> memo(h, vector<int>(w, -1));
  // -1 : チェックしていない。
  // 0< : エネルギーが n の状況で訪れたことがある。

  queue<pair<int, int>> q;

  // スタート地点にEがないとゲームオーバー
  if (emap[si][sj] == 0) {
    cout << "No" << endl;
    return 0;
  }

  q.push({ si, sj });
  memo[si][sj] = emap[si][sj];

  while (!q.empty()) {
    auto qf = q.front();
    q.pop();
    int qi = qf.first;
    int qj = qf.second;
    int qe = memo[qi][qj];
    // エネルギー qe で (qi, qj) にきている

    pair<int, int> moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (pair<int, int> d : moves) {
      int ni = qi + d.first;
      int nj = qj + d.second;
      // いけるか
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) {
        continue;
      }
      if (a[ni][nj] == '#') {
        continue;
      }
      // ↓ いける
      // ゴールならクリア
      if (a[ni][nj] == 'T') {
        cout << "Yes" << endl;
        return 0;
      }
      int ne = qe - 1;
      // より高いエネルギーで来たことがあれば、探索する意味がない
      if (memo[ni][nj] >= ne) {
        continue;
      }
      // 移動して、薬を使う or 使わない 最善
      ne = max(emap[ni][nj], ne);
      if (ne > 0) {
        // 追加
        memo[ni][nj] = ne;
        q.push({ ni, nj });
      }
    }
  }

  cout << "No" << endl;
}