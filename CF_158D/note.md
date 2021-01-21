[Problem Link](https://codeforces.com/problemset/problem/158/D)

# Problem statement
- N ice sculpture were erected which create a regular polygon
- Sculpture arrange in a circle
- Sculpture has degree ti
- we have arrange people such that sum of degree will be maximum
- Sculpture can not be moved

# Input
- 3 ≤ n ≤ 20000, here n is the initial number of sculptures
-( - 1000 ≤ ti ≤ 1000) ,degree of sculptures

# Observation

- First of all we have know that there is something called [Regular polygon](https://en.wikipedia.org/wiki/Regular_polygon#:~:text=In%20Euclidean%20geometry%2C%20a%20regular,be%20either%20convex%20or%20star.L) , which have some extra properties

- we have to create some new N-gon from the given regular polygon and we have take care of that Newly created N-gon have to be regualr polygon

- Regular polygon first properties is that 
distance between every vertices have to exact same

- Ice sculpture is place in a circle manner and we have create new polygon such that distance between every vertex wood same
- we can write it mathmatically that, if we start at a particular distance then ,

>**Start+nx ≡ start (mod N)**
>
> or, **Start+nx-start≡ 0(mod N)**
>
>or, **nx≡0(mod N)** ,here x is number of scultpure we skip
>
>so we can say that x have to multiply of N
> 
> and strart should be less than **X** because 
start must be `[1.....(X-1)]` if start is greater than X then we can write start =(n*x)+(start%x) which will be redundency ,then strat will become
>
> **Start=Strat%X**
>
> we need atleast 3 vertices so 
>
>x>=(n/3) or (n/x)<=3

# Implementation 
- we try all possible value of x which will be divisor of N and try to calculate the degree 
- take maximum of it
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
    vector<int>v(n);
    for(int &i:v)
    cin>>ignore;
    int ans=(int)-1e9;
    for(int x=1;x<=(n/3);++x){
        if(n%x)continue;
        for(int start(0);start<x;++start){
            int temp=0;
            for(int j(start);j<n;j+=x){
                temp+=v[j];
            }
            ans=max(ans,temp);
        }
    }
    cout<<ans<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t;
    // cin>>t;
    // for (int i(1); i <= t; ++i) {
    //     printf("Case %d:\n", i);
        solve();
    //}
    return 0;
}
```
>Happy Coding :smile:

