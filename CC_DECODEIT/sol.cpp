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
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
const int mod = 1e9 + 7;
using u64 = uint64_t;
using u128 = __uint128_t;
#define sc1(x) scanf("%lld",&(x));
const ll mx = -1e12;
void solve() {
	int N;
	cin >> N;
	string str;
	cin >> str;
	map<int, char>mp;
	for (int i(0); i <= 15; ++i) {
		mp[i] = char('a' + i);
	}
	for (int i(0); i < N; i += 4) {
		string temp = str.substr(i, 4);
		bitset<4> foo(temp);
		auto x = foo.to_ulong();
		cout << mp[x];

	}
	cout << endl;


}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i(1); i <= t; ++i) {
		//printf("Case %d:\n", i);
		solve();
	}
	return 0;
}