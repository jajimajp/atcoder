#include <iostream>
#include <vector>
#include <string>

using namespace std;

// x^3 # : 10^6

bool is_loop(long long n) {
  vector<int> ns;
  long long tmp = n;
  while (0 < tmp) {
    ns.push_back(tmp % 10);
    tmp = tmp / 10;
  }
  long long rev = 0;
  for (int i = 0; i < ns.size(); i++) {
    rev = 10 * rev + ns[i];
  }
  return rev == n;
}

int main() {
  long long n;
  cin >> n;

  vector<long long> tri;
  long long i = 1;
  while (i * i * i <= n) {
    tri.push_back(i * i * i);
    ++i;
  }

  for (int i = tri.size() - 1; 0 <= i; --i) {
    if (is_loop(tri[i])) {
      cout << tri[i] << endl;
      return 0;
    }
  }
}
