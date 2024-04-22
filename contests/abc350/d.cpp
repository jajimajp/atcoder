#include <bits/stdc++.h>
#include <numeric> // std::iota()

using namespace std;

#define ll long long

/// @brief Union-Find 木
/// @note 1.3 高速化
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find
class UnionFind
{
public:

	UnionFind() = default;

	/// @brief Union-Find 木を構築します。
	/// @param n 要素数
	explicit UnionFind(size_t n)
		: m_parents(n)
		, m_sizes(n, 1)
	{
		std::iota(m_parents.begin(), m_parents.end(), 0);
	}

	/// @brief 頂点 i の root のインデックスを返します。
	/// @param i 調べる頂点のインデックス
	/// @return 頂点 i の root のインデックス
	int find(int i)
	{
		if (m_parents[i] == i)
		{
			return i;
		}

		// 経路圧縮
		return (m_parents[i] = find(m_parents[i]));
	}

	/// @brief a のグループと b のグループを統合します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	void merge(int a, int b)
	{
		a = find(a);
		b = find(b);

		if (a != b)
		{
			// union by size (小さいほうが子になる）
			if (m_sizes[a] < m_sizes[b])
			{
				std::swap(a, b);
			}

			m_sizes[a] += m_sizes[b];
			m_parents[b] = a;
		}
	}

	/// @brief a と b が同じグループに属すかを返します。
	/// @param a 一方のインデックス
	/// @param b 他方のインデックス
	/// @return a と b が同じグループに属す場合 true, それ以外の場合は false
	bool connected(int a, int b)
	{
		return (find(a) == find(b));
	}

	/// @brief i が属するグループの要素数を返します。
	/// @param i インデックス
	/// @return i が属するグループの要素数
	int size(int i)
	{
		return m_sizes[find(i)];
	}

private:

	// m_parents[i] は i の 親,
	// root の場合は自身が親
	std::vector<int> m_parents;

	// グループの要素数 (root 用)
	// i が root のときのみ, m_sizes[i] はそのグループに属する要素数を表す
	std::vector<int> m_sizes;
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m), b(m);
  UnionFind uf(n);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    uf.merge(a[i], b[i]);
  }

  set<ll> roots;
  for (int i = 0; i < n; i++) {
    roots.insert(uf.find(i));
  }

  map<ll, ll> cnts;
  for (auto r : roots) {
    cnts.insert({ r, 0 });
  }
  for (int i = 0; i < m; i++) {
    cnts[uf.find(a[i])]++;
  }
  ll ans = 0;
  for (auto r : roots) {
    ll sz = uf.size(r);
    ans += (sz * (sz - 1) / 2) - cnts[r];
  }
  cout << ans << endl;
}