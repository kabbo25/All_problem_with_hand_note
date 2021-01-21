[Problem Link](https://codeforces.com/contest/1443/problem/B)

# Problem statement
- N buildings in a straight line
- There is a string implies that i-th character in mine or not
- If mine X exploded then (x-1) and (x+1) mine also get activated
- For manual activation it cost a coints
- For set mines he takes b coins
- we have to blow all mines and have to find minimum cost

# Input
-(1≤a,b≤1000)
- string lengths for all test cases does not exceed 10<sup>5</sup>

# Observation
- we have to push all segment
- for any segement we have two options
- first activate any mine to destroy the segement
- second place mind between the segment 
# Implementation
- push all segment the array
- try first and second case in both segment
- minimum of them will be our answer
# Implementation
```c++
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int tc, cs = 1;
 
void test_cases() {
	ll a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int n = s.size();
	vector<pair<int, int>> v;
	int cur = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			if (cur == -1) cur = i;
		} else {
			if (cur != -1) {
				v.emplace_back(cur, i);
				cur = -1;
			}
		}
	}
	if (cur != -1) v.emplace_back(cur, n - 1);
	if (v.empty()) {
		cout << 0 << '\n';
		return;
	}
	ll ans = a;
	for (int i = 1; i < (int)v.size(); ++i) {
		int d = v[i].first - v[i - 1].second;
		ans += min(a, d * b);
	}
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		test_cases();
	}
}
```
> Happy coding :smile:
