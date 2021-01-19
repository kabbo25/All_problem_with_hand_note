[**Problme Statement**](https://codeforces.com/problemset/problem/1445/B)

# Problem Statement
- atleast 100 participants will advace to the final stage
- Jury has only standings for the first and for the second contest
- Students are ranked according to their numbers
- In the first contest 100-th place participant has c points
- In the second contest all hundred participants of first contest  has atleast b points
- Similarly for second contest minimum number is c and  all the participant of second  have alleast d ponts in first contest

- Find the cutoff score  to qualify in the final

# Input
- a, b, c, d (0≤a,b,c,d≤9; d≤a; b≤c)

# Observation
- Minimum score of first 100 participant is (a+b)
- Minimum score of second 100 participant is (c+d)
- Minimum cut off score will be max(a+b,c+d)
- Because we assume that all first 100 participant has same score and it can be possible and all second 100 participant has same score


# Implementation 

- max(a+b,c+d)

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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(a+b,c+d)<<endl;
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