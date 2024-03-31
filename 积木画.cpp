#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 100000007;
const int N = 1000005;
int n; 
ll dp[N];
int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i-1] * 2 + dp[i - 3]) % MOD;
		
	}
	cout << dp[n] << endl;
	return 0;
}
