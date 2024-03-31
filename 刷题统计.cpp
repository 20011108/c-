#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,k;
ll ans = 0;
int main() {
	cin >> a >> b >> n;
	k = a * 5 + b + b;
	ans += n/k * 7;
	n %= k;
	if (n <= a * 5) {
		ans += n / a + (n % a != 0);
		
	}
	else {
		n -= a* 5;
		ans += 6 + (n > b);
	}
	cout << ans << endl;
	return 0;
}
