#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> primes;
  for (int i = 2; i <= 500; i++) {
    bool is_prime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      primes.push_back(i);
  }

  vector<int> hsh(n);
  for (int i = 0; i < n; i++) {
    hsh[i] = a[i];
    if (a[i] == 0 || a[i] == 1) {
      continue;
    }
    for (int j = 0; j < primes.size(); j++) {
      while (hsh[i] % (primes[j] * primes[j]) == 0) {
        hsh[i] = hsh[i] / (primes[j] * primes[j]);
      }
    }
  }

  // count each hsh with (v, num) form
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cnt[hsh[i]]++;
  }

  long long ans = 0;
  ans += cnt[0] * (n - cnt[0]);
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    ans += it->second * (it->second - 1) / 2;
  }

  cout << ans << endl;
}
