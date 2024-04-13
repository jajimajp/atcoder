#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  // 最初 idx だったものが表す文字 0 => 'a'
  vector<int> rep(26);
  for (int i = 0; i < 26; ++i) {
    rep[i] = i;
  }

  for (int i = 0; i < q; ++i) {
    char c, d;
    cin >> c >> d;
    for (int j = 0; j < 26; ++j) {
      if (rep[j] == c - 'a') {
        rep[j] = d - 'a';
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    char c = 'a' + rep[s[i] - 'a'];
    cout << c;
  }
  cout << endl;
}
