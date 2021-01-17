[**Problem Link**](https://www.codechef.com/problems/ALPHABET?fbclid=IwAR37nhyLT-pGPQMAj1cHuAED79ckhc9f4wXD2x3_Yz7Vumws17EIAwZcUL8)

### Problem Statement
---
- We have a book consisting of N words
- He can read a word if this word is from the book 
- we have to find which word is from the book or or 

### Input 
---
- given a string 
- N query 
- every query have string we have to 
we can read that word or not 

### Observation
---
- We can observe for first given string have some letters, and we can only read those letters 

- if given query string consist those letters which already present in first string we can read it otherwise we can't 

### Implementation
----
- First take one map and count every letter of first string 
- then for query string ,traverse the string and if that letter `Present in map ` we can read otherwise we can't 
- we take one bool variable to see that we can read all the letters if we can't read even one letter then `flag will be false` and answer will be `No` ,other wise answer will be `Yes`

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
void solve() {
    string str;
    cin>>str;
   map<char,int>mp;
   for(auto& x:str)
   mp[x]++;
   int q;
   cin>>q;
   while(q--){
       string s;
       cin>>s;
       bool flag=true;
       for(auto& x:s){
           if(mp.count(x)==0){
               flag=false;
               break;
           }
       }
       cout<<(flag?"Yes":"No")<<endl;
   }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin>>t;
    // for (int i(1); i <= t; ++i) {
       // printf("Case %d:\n", i);
        solve();
    //}
    return 0;
}
```
>Happpy coding :satisfied: