/*
* @Author: kabbo
* @Date:   2020-06-24 08:40:07
* @Last Modified by:   kabbo
* @Last Modified time: 2020-06-24 08:49:58
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<long long,long long>
#define endl '\n'
#define ll int64_t

#define ar array
/*http:*///www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// template<class Fun>
// class y_combinator_result {
// 	Fun fun_;
// public:
// 	template<class T>
// 	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

// 	template<class ...Args>
// 	decltype(auto) operator()(Args &&...args) {
// 		return fun_(std::ref(*this), std::forward<Args>(args)...);
// 	}
// };

// template<class Fun>
// decltype(auto) y_combinator(Fun &&fun) {
// 	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
// }
const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld",&(x));
const int mx = 2e5 + 5;
vector<int>adj[mx];
vector<int>high(mx, (int) - 1e9);
bool vis[mx];
vector<int>cost(mx, 0);
void dfs(int i) {
	vis[i] = true;
	high[i] = max(high[i], cost[i]);
	for (auto u : adj[i]) {
		if (!vis[u])
			dfs(u);
		high[i] = max(high[i], high[u]);
	}
}
void  solve() {
	int N, M;
	cin >> N >> M;
	for (int i(1); i <= N; ++i) {
		cin >> cost[i];
	}
	for (int i(0); i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
	}
	for (int i(1); i <= N; ++i) {
		if (!vis[i])
			dfs(i);
	}
	ll ans = (int) - 1e9;
	for (int i(1); i <= N; ++i) {
		for (int j : adj[i])
			ans = max(ans, (ll)high[j] - cost[i]);
	}
	cout << ans << endl;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// int t;
	// cin >> t;
	// for (int i(1); i <= t; ++i) {
	//printf("Case %d:\n", i);
	solve();
	//}
	return 0;
}