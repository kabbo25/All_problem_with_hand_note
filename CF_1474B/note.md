[**Problem Link**](https://codeforces.com/contest/1474/problem/B)

## Problem statement
---
- Find smallest integers that have atleast 4 divisors 
and difference between every divsior is atlest **d**

# Input
- given d, d<= 10<sup>5

# Observation 
- first of all we find the maximum integer which will be our candidate answer 

-For every number `1` is the first divsior our possible second number will be `[1+d]` 

- actually we have to find two smallerst primes numbers those difference is atleast d
- from above formula we can see that first prime number have to atleast `[1+d]` and second one have to be `[1+d+d]` then distance between them will be atleast d


# Implementation
- first we generate all primes up to d
- then using lower_bound we find two primes
- maximum answer will be **[(d+1)<sup>3</sup>]** because it has 4 divisors and distance between them is **d**

- we take minimum of maximum answer and prime of((d+1) and (1+d+d))

# Code 
```c++
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
#define ull unsigned long long
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
/*Well, probably you won't understand anything,
because you didn't try to understand anything in your life,
you expect all hard work to be done for you by someone else. 
Let's start*/
const int X = 30303;
 
bitset<X> is_prime;
vector<int> pf;
vector<int> pr;
 
void init(){
	pf.resize(X, 0);
	is_prime.flip();
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i < X; i++){
		if(is_prime[i]){
			pr.push_back(i);
			pf[i] = i;
		}
		for(int p : pr){
			if(ll(i) * p >= X) break;
			pf[i * p] = p;
			is_prime[i * p] = false;
			if(i % p == 0) break;
		}
	}
}
void solve() {
     ll d;
     cin>>d;
     ll low=d+1;
     ll x=*lower_bound(pr.begin(),pr.end(),low);
     ll y=*lower_bound(pr.begin(),pr.end(),x+d);
     cout<<min(x*x*x,(ll)x*y)<<endl;
}
int main() {
     
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    for (int i(1); i <= t; ++i) {
        //printf("Case %d:\n", i);
        solve();
    }
    return 0;
}
```
>Happy coding :smile:
