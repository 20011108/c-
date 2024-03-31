#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 10000007;
const int N = 105;
ll mp[N][N][N];
ll dfs(int n,int m, int k) {
	if (k == 0) return(m==0 && n == 0);
	if (k>m || n >= m) return 0;
	if (n == 0 ) return k == m;
	if (mp[n][m][k] != -1) return mp[n][m][k];
	ll ans = dfs(n,m-1,k-1) + dfs(n-1,m,k+k);
	ans %= MOD;
	mp[n][m][k] = ans;
	return ans;
} 
int main() {
	memset(mp,-1,sizeof mp);
	int m,n;
	cin >> n >> m;
	cout << dfs(n,m,2) << endl;
	return 0;
}
