#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n - 1), b(n - 1), x(n - 1);
  for (long long i = 0; i < n - 1; ++i) {
    cin >> a[i] >> b[i] >> x[i];
    x[i]--; // 0-indexed
  }
  vector<vector<long long> > dist(n, vector<long long>(n, 0));
  vector<vector<long long> > nexts(n, vector<long long>());
  for (long long i = 0; i < n - 1; ++i) {
    nexts[i].push_back(i + 1);
    dist[i][i + 1] = a[i];
  }
  for (long long i = 0; i < n - 1; ++i) {
    if (x[i] == i + 1) {
      dist[i][x[i]] = min(b[i], a[i]);
    } else {
      nexts[i].push_back(x[i]);
      dist[i][x[i]] = b[i];
    }
  }

  priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      que;
  long long upperd = 1;
  for (long long i = 0; i < n - 1; i++)
    upperd += a[i];
  vector<long long> mindist(n, upperd);
  que.push(make_pair(0, 0));
  mindist[0] = 0;
  while (!que.empty()) {
    auto t = que.top();
    que.pop();
    auto v = t.second;
    if (mindist[v] < t.first) {
      continue;
    }
    for (auto e : nexts[v]) {
      if (mindist[e] > mindist[v] + dist[v][e]) {
        mindist[e] = mindist[v] + dist[v][e];
        if (e == n - 1) {
          continue;
        }
        que.push(make_pair(mindist[e], e));
      }
    }
  }

  cout << mindist[n - 1] << endl;
}
