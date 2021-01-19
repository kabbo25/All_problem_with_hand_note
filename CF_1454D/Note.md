[**Problem Link**](https://codeforces.com/contest/1454/problem/D)

## Problem Statement
---
- Given an integer n
- We have to construct an array `[a1,.....ak]` 
-ai greater than 1
- product of every element in that array is equal to n
- a[i+1] should be multiple of a[i]
- k is the maximum length of that array

## Input
---
- N <=10<sup>10 </sup>, where n is the number of elements in that array

## Observation
---
- First observation is that product of every element must be equal to n that implies we have to factorize N
- if n is prime then the value of k will 1 and answer will be `n`
- First we factorize n - [p<sub>1</sub> <sup>k</sup>,p<sub>2 <sup>k2</sup>......... p<sub>k</sub> <sup>kn</sup> ] 
- then K will be max(k1,k2,......kn)
- if we find k then it is very easy to construct the array

## Implementation
---
- first factorize n 
- find K using formula `K will be max(k1,k2,......kn)`
- construct the array we push `(K-1)times P` and last element will be `(N/(k-1)*p)`

# Code 
---
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
const int X = 1e5+5;

void solve() {
    ll n;
    cin>>n;
    ll N=n;
    vector<ar<ll,2>>factor;
    for(ll i(2);i*i<=n;++i){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            factor.push_back({i,cnt});
        }
    }
    if(n>1)factor.push_back({n,1});
    ar<int,2>ans{0,0};
    int mx=0;
    for(auto& x:factor){
       if(x[1]>mx){
           ans[0]=x[0];
           ans[1]=x[1];
           mx=x[1];
       }
    }
    vector<ll>res;
    ll sum=1;
    for(int i(0);i<ans[1]-1;++i){
    res.emplace_back(ans[0]);
    sum*=ans[0];
    }
    res.emplace_back(N/sum);
    cout<<res.size()<<endl;
    for(auto& x:res)
    cout<<x<<" ";
    cout<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //init();
    int t;
    cin>>t;
    for (int i(1); i <= t; ++i) {
       // printf("Case %d:\n", i);
        solve();
    }
    return 0;
}
```