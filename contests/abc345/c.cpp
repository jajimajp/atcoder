#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  int len = s.length();
  if (len == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < len; i++) {
    cnt[s[i] - 'a']++;
  }
  bool idext = false;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > 1) {
      idext = true;
      break;
    }
  }

  ll ans = 0;
  int rest = len;
  for (int i = 0; i < len; i++) {
    rest--;
    cnt[s[i] - 'a']--;
    ans += rest - cnt[s[i] - 'a'];
  }

  if (idext) {
    ans++;
  }

  cout << ans << endl;
}