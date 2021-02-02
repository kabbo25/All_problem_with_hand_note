[Problem Link](http://codeforces.com/contest/312/problem/B)

# Prerequisite:
-  All about G.P
- Infinite sum of G.P
- Probability
# Problem statement and observation

- SmallR, who shoots first can win in the following cases:

He shoots the target in the first shot. OR
He misses AND his opponent misses AND he shoots the target. OR
He misses AND his opponent misses AND he misses AND his opponent misses AND he shoots the target
When there is an OR between 2 events(which lead to same result) happening, it means EITHER of them will lead to the same result, so the probability of the result is the SUM OF ALL THESE PROBABILITIES.

On the other hand, when there is AND between 2 events, it means that BOTH OF THEM SHOULD HAPPEN TO GET THE DESIRED OUTCOME. So if event A happens with probability = 1/2 and event B happens with probability = 1/2 and event C happens when both A and B happen, then probability of C happening is 1/2 * 1/2 = 1/4, which also makes sense logically. Because C will happen in only 1 out 4 cases, when BOTH A and B have happened. You can imagine the 4 cases:

A did not happen AND B did not happen => C did not happen
A happened AND B did not happen => C did not happen
A did not happen AND B happened => C did not happen
A happened AND B happened => C happened
So a good rule of thumb is AND means product of probabilities and OR means sum of probabilities.

So now we can get the answer to our problem:

answer = ```a/b + ( (1-a/b) * (1-c/d) * a/b ) + ( (1-a/b) * (1-c/d) * (1-a/b) * (1-c/d) * a/b )```... and so on.

You can sum this up using formula for sum of infinite geometric series.

- let p=a/b,q=(1-c/d)*(1-a/b). The answer of this problem can be showed as:p*q^0+p*q^1+p*q^2+………… That is the sum of a geometric progression which is infinite but 0<q<1.We can get the limit by the formula:p/(1-q)

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
    cout<<setprecision(12)<<fixed;
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double p=(a/b);
    double q=(1-(a/b))*(1-(c/d));
    cout<<(p/(1-q))<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int t;
    //cin>>t;
    //for (int i(1); i <= t; ++i) {
   //     printf("Case %d:\n", i);
        solve();
 //   }
    return 0;
}
```
>Happy coding :smile: