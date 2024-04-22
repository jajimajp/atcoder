#include <bits/stdc++.h>

using namespace std;

#define ll long long

// 0 1 2
// 3 4 5
// 6 7 8
vector<int> a(9);
vector<bool> tsl(9, false);
vector<bool> asl(9, false);
const vector<vector<int>> lines = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {0, 3, 6},
  {1, 4, 7},
  {2, 5, 8},
  {0, 4, 8},
  {2, 4, 6},
};

bool twin(set<int> unpicked) {
  // DEBUG
  // cout << "UP";
  // for (auto e : unpicked) {
  //   cout << " " << e;
  // }
  // cout << endl << "T";
  // for (auto e : tsl) {
  //   cout << e;
  // }
  // cout << endl << "A";
  // for (auto e : asl) {
  //   cout << e;
  // }

  // bingo
  for (auto l : lines) {
    if (tsl[l[0]] && tsl[l[1]] && tsl[l[2]]) {
      return true;
    }
    if (asl[l[0]] && asl[l[1]] && asl[l[2]]) {
      return false;
    }
  }

  // finished
  if (unpicked.size() == 0) {
    // int cnt = 0;
    ll tsc = 0, asc = 0;
    for (int i = 0; i < 9; i++) {
      if (tsl[i]) {
        // cnt++;
        tsc += a[i];
      }
      if (asl[i]) {
        // cnt++;
        asc += a[i];
      }
    }
    // DBG
    // cout << "CNT " << cnt << endl;
    // cout << "last " << asc << " " << tsc << endl;
    return tsc > asc;
  }

  vector<int> cpup;
  for (auto e : unpicked) {
    cpup.push_back(e);
  }
  // select
  if (unpicked.size() % 2 == 0) {
    // aoki
    for (auto u : cpup) {
      unpicked.erase(u);
      asl[u] = true;
      bool res = twin(unpicked);
      asl[u] = false;
      unpicked.insert(u);
      // aoki wins
      if (!res) {
        return false;
      }
    }
    // no way to win
    return true;
  } else {
    // takahashi
    for (auto u : cpup) {
      unpicked.erase(u);
      tsl[u] = true;
      bool res = twin(unpicked);
      tsl[u] = false;
      unpicked.insert(u);
      // if (cpup.size() == 9) {
      //   if (res) {
      //     cout << "win" << endl;
      //   } else {
      //     cout << "Ls" << endl;
      //   }
      // }
      // takahashi wins
      if (res) {
        return true;
      }
    }
    // no way to win
    return false;
  }

  return true;
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
  }
  set<int> up = {0,1,2,3,4,5,6,7,8};

  bool res = twin(up);
  if (res) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  // DBG
  // for (int i = 0; i < 9; i++) {
  //   cout << "A " << a[i] << endl;
  // }
  // for (auto l : lines) {
  //   cout << l[0] << l[1] << l[2] << endl;
  // }

  return 0;
}
