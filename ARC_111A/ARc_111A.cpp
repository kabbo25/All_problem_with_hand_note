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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
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
const int X = 1e5 + 5;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template < typename T_container, typename T = typename enable_if < !is_same<T_container, string>::value, typename T_container::value_type >::type > ostream & operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<const int &MOD>
struct _m_int {
	int val;

	_m_int(int64_t v = 0) {
		if (v < 0) v = v % MOD + MOD;
		if (v >= MOD) v %= MOD;
		val = int(v);
	}

	_m_int(uint64_t v) {
		if (v >= MOD) v %= MOD;
		val = int(v);
	}

	_m_int(int v) : _m_int(int64_t(v)) {}
	_m_int(unsigned v) : _m_int(uint64_t(v)) {}

	static int inv_mod(int a, int m = MOD) {
		// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
		int g = m, r = a, x = 0, y = 1;

		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const { return val; }
	explicit operator unsigned() const { return val; }
	explicit operator int64_t() const { return val; }
	explicit operator uint64_t() const { return val; }
	explicit operator double() const { return val; }
	explicit operator long double() const { return val; }

	_m_int& operator+=(const _m_int &other) {
		val -= MOD - other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	_m_int& operator-=(const _m_int &other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
		return unsigned(x % m);
#endif
		// Optimized mod for Codeforces 32-bit machines.
		// x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
		unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}

	_m_int& operator*=(const _m_int &other) {
		val = fast_mod(uint64_t(val) * other.val);
		return *this;
	}

	_m_int& operator/=(const _m_int &other) {
		return *this *= other.inv();
	}

	friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
	friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
	friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
	friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

	_m_int& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	_m_int& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	_m_int operator++(int) { _m_int before = *this; ++*this; return before; }
	_m_int operator--(int) { _m_int before = *this; --*this; return before; }

	_m_int operator-() const {
		return val == 0 ? 0 : MOD - val;
	}

	friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
	friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
	friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
	friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
	friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
	friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }

	_m_int inv() const {
		return inv_mod(val);
	}

	_m_int pow(int64_t p) const {
		if (p < 0)
			return inv().pow(-p);

		_m_int a = *this, result = 1;

		while (p > 0) {
			if (p & 1)
				result *= a;

			p >>= 1;

			if (p > 0)
				a *= a;
		}

		return result;
	}

	friend ostream& operator<<(ostream &os, const _m_int &m) {
		return os << m.val;
	}
};

int MOD = 998244353;
using mod_int = _m_int<MOD>;
/*
bitset<X> is_prime;
vector<int> pf;
vector<int> pr;

void init() {
	pf.resize(X, 0);
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < X; i++) {
		if (is_prime[i]) {
			pr.push_back(i);
			pf[i] = i;
		}
		for (int p : pr) {
			if ((ll)i * p >= X) break;
			pf[i * p] = p;
			is_prime[i * p] = false;
			if (i % p == 0) break;
		}
	}
}*/


void solve() {

	ll N, M;
	cin >> N >> M;

	MOD = M * M;
	cout << int(mod_int(10).pow(N)) / M << endl;

}
int main() {
	//init();
	ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// int t;
	// cin >> t;
	// for (int i(1); i <= t; ++i) {
	//printf("Case %d:\n", i);
	solve();
	//}
	return 0;
}