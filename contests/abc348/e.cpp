#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;

  vector<int> a(n - 1), b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  vector<int> c(n);
  ll csum = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    csum += c[i];
  }

  // 隣人
  vector<vector<int>> nb(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    nb[a[i]].push_back(b[i]);
    nb[b[i]].push_back(a[i]);
  }

  // 頂点 0 を root とする
  vector<int> par(n); // 親
  par[0] = -1;
  vector<vector<int>> ch(n, vector<int>()); // 子
  stack<int> stk;
  stack<int> stk4cnt;
  stk.push(0);
  stk4cnt.push(0);
  while (!stk.empty()) {
    int i = stk.top();
    stk.pop();
    for (auto e : nb[i]) {
      if (e == par[i]) {
        continue;
      }
      par[e] = i;
      ch[i].push_back(e);
      stk.push(e);
      stk4cnt.push(e);
    }
  }

  // DBG
  // cout << "CNT" << stk4cnt.size() << endl;
  // 自分を含まない、自分以下の頂点の数字の和
  vector<ll> vs(n, 0);
  ll f0 = 0;
  while (!stk4cnt.empty()) {
    int i = stk4cnt.top();
    stk4cnt.pop();
    if (i == 0) { // root
      continue;
    }
    vs[par[i]] += c[i] + vs[i]; // 自分の数字と、子の和
    f0 += c[i] + vs[i];
  }

  // { x, y } : f(x) は y
  queue<pair<int, ll>> q;
  q.push({ 0, f0 });
  ll minval = f0;
  while (!q.empty()) {
    auto e = q.front(); q.pop();
    int x = e.first;
    ll y  = e.second;


    // DEBUG
    // cout << "X: " << x << ", Y: " << y << endl;
    // cout << x << endl;

    // 親方向の数字
    // 子に映る際に増加
    ll z = csum - vs[x];
    for (auto child : ch[x]) {
      // 子供のうち、対象じゃないところの数字 増加
      ll zc = vs[x] - (vs[child] + c[child]);
      // 子供側の数字　減少
      ll zchild = vs[child] + c[child];

      // cout << "child: " << child << endl;
      // cout << "z: " << z << ", zc: " << zc << ", zchild:" << zchild << endl;

      ll newy = y + z + zc - zchild;
      q.push({ child, newy });
      minval = min(minval, newy);
    }
  }
  
  cout << minval << endl;

  /* DEBUG */
  // cout << "f0: " << f0 << endl;
  // for (int i = 0; i < n; i++) {
  //   cout << i << " V=" << vs[i] << " :";
  //   for (auto c : ch[i]) {
  //     cout << " " << c;
  //   }
  //   cout << endl;
  // }
}