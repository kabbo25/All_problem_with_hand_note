[problem link](https://codeforces.com/contest/1475/problem/C)

# Observation and Problem statemen
![](g1.jpeg)
![](g2.jpeg)
![](g3.jpeg)

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
void solve() {
   ll a,b,k;
   cin>>a>>b>>k;
   vector<ll>boys(a+1,0);
   vector<ll>girls(b+1,0); 
   ll ans=(k*(k-1))/2;
   for(int i(0);i<k;++i){
       int x;
       cin>>x;
       boys[x]++;
   }
   for(int i(0);i<k;++i){
       int x;
       cin>>x;
       girls[x]++;
   }
   for(auto& x:boys)
   ans-=(x*(x-1))/2;
   for(auto x:girls)
   ans-=(x*(x-1))/2;
   cout<<ans<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for (int i(1); i <= t; ++i) {
 //       printf("Case %d:\n", i);
        solve();
    }
    return 0;
}
```
>Happy Coding :smile: