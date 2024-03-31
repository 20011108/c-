#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

string s;
int sum[maxn];
int main(){
	int k;
	cin >> k;
	cin >> s;
	int n = s.size();
	char a,b;
	cin >> a >> b;
	for (int i = 1; i <= n; i++) {
		if (s[i-1] == b) sum[i]=1;
		sum[i] += sum[i-1];
		
	} 
	ll ans = 0;
	for (int i = 1; i + k - 1 <= n; i++) {
		if (s[i-1] == a) ans += sum[n] - sum[i+k - 2];
	}
	cout << ans << endl;
	return 0;
}
