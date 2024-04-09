#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 505;
ll m,n,k;
ll a[N][N];
ll ans = 0;
int main(){
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i][j-1];
			
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int left = 1;
			ll cur = 0;
			for (int right = 1; right <= m; right++){
				cur += a[left][j] - a[left][i - 1];
				left++;
			}
			ans += right - left + 1;
		}
	}
	cout << ans << endl;
return 0; 
} 

