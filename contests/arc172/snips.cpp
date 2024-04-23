#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 素数列挙
vector<ll> primes_upto(ll upto) {
  vector<ll> is_prime(upto, true);
  vector<ll> primes;
  for (int i = 2; i < upto; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j < upto; j += i) {
        is_prime[j] = false;
      }
      primes.push_back(i);
    }
  }
  return primes;
}
