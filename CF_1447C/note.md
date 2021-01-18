[**Problem Link**](https://codeforces.com/contest/1447/problem/C)

## **Problem Statement**
---
- There is bag with weight W 
- There is n item and ith item weight is **wi**
- total weight will be at least (W/2) and atmost (W)
- construct array of items that total weight of that array satisfy the above condition

## Input
---
- Given N, where N is number of elements
and N<=**2e5**
- Given W ,total capacity of the bag
W<=10<sup>18
- wi is weight of the item ,wi <=10<sup>9


## Observation:
- First we think of when we can't satisfy the condition
- when minimum element of that is bigger than the capacity of the bag then answer is -1
- if sum of all elements is less than (W/2) 
then also answer is -1

- for all other case answer is yes and we just have to put all items until total weights of the item don't exceed capacity
- if one element is greater than equal (W/2) then we push that element delete all element because this one element can be our possible answer or if `(2* ith_elemetn)<=W`

## Implementation:
- we if (2*ith_element)>=W we get our answer coz this element weight is greater than equal(W/2)
- else we put all the elements until the sum of the elements doesn't exceed the W
- lastlty we check `total_sum*2` less than Capacity then answer is -1

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
    ll N,W;
    cin>>N>>W;
    ll sum=0;
    vector<int>ans;
    for(int i(0);i<N;++i){
        ll x;
        cin>>x;
        if(x>W)continue;
        if(2*x>=W){
            ans.clear();
            ans={i+1};
            sum=x;
        }
        else if(sum+x<=W){
            ans.emplace_back(i+1);
            sum+=x;
        }
    }
  if(2*sum<W){
      cout<<-1<<endl;
      return;
  }
  cout<<ans.size()<<endl;
  for(auto& x:ans)
  cout<<x<<" ";
  cout<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for (int i(1); i <= t; ++i) {
       // printf("Case %d:\n", i);
        solve();
    }
    return 0;
}
```
# Happy coding :smile:

