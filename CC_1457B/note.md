[**Problem Link**](https://codeforces.com/contest/1457/problem/B)

## Problem Statement
---
- There is a street with n houses number 1 to n
- The ith house is color in Ci
- Street is beautiful if `all houses are painted in the same color`
- Tom can paint at most **k** houses in a range
- ** Minimum number of days need to make the street beautiful

## Input
---
- Given K  where  k <= 10<sup>5
- Given N where  N <= 10<sup>5
- Ci where Ci <=100

## Observation
---
- We have to make every elements of the array is equal
- We will try every color to paint the house and find how many houses we need to color
- answer will be minimum number houses we need to change after using `ith` color


## Implementation
---
- try `[1...100]` every color 
- Because we can color from `[i.....i+k-1]` houses so we first find the left index of house which is not color in Ci and from `[i.....i+k-1]` in that range in color every houses with color Ci in one day
- answer will be for which color we need minimum number of days



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
    int N,K;
    cin>>N>>K;
    vector<int>v(N);
    for(auto& x:v)
    cin>>x;
    ll ans=(ll)1e9;
    for(int i(1);i<=100;++i){
        ll temp=0;
        for(int j(0);j<N;++j){
            if(v[j]!=i){
                temp++;
                j+=(K-1);
            }
        }
        ans=min(ans,temp);

    }
    cout<<ans<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for (int i(1); i <= t; ++i) {
   //     printf("Case %d:\n", i);
        solve();
    }
    return 0;
}

```
# Happy Coding :smile: