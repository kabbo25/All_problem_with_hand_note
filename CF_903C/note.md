[**Problem link**](https://codeforces.com/contest/903/problem/C)

# Problem statement
- we have n empty boxes and i-th box is a cube with side lenght a<sub>i
- put i-th box in jth box if 
- i-th box not put into another box
- j-th box is empty
- box i is smaller than box j
- minimum number of visible boxes

# Input

- n (1 ≤ n ≤ 5000)
- Here n is the number of boxes

# observation
- It is always possible to put the boxes into bigger ones
- maximum of count of every box will be our answer

# Implementation
- count the occurance of every number 
- print maximum of it

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
    int n;
    cin>>n;
    vector<int>v(n+1);
    map<int,int>cnt;
    int mx=0;
    for(int i(1);i<=n;++i){
        cin>>v[i];
        cnt[v[i]]++;
    }
    for(auto[a,b]:cnt){
        mx=max(b,mx);
    }
    cout<<mx<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin>>t;
    // for (int i(1); i <= t; ++i) {
        //printf("Case %d:\n", i);
        solve();
    //}
    return 0;
}
```
>Happy coding :smile:
