[Problem Link](https://codeforces.com/contest/1445/problem/A)

# Problem Statement
- Given two arrays a and b, each have n integers
- There is an element x
- we have to rearrange all the elements such that <pre tab>a<sub>i</sub>+b<sub>i</sub> <=x

# Input
- (1≤n≤50) where n is the size of both an array

# Observation
- we will sort the array ,and merger (maxi+mini) from both array so that it will balanced

# Implementation
- sort the array in increasing and decreasing order
- check for all elemets

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
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n);
    for(auto& i:a)cin>>i;
    for(auto& i:b)cin>>i;
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    vector<int>ans;
    bool flag=true;
    for(int i(0);i<n;++i){
        ans.emplace_back(a[i]+b[i]);
    }
    for(auto& i:ans)
    flag&=(i<=x);
    cout<<(flag?"Yes":"No")<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
