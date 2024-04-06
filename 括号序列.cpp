#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5010,MOD = 1e9 + 7;
int n;
char str[N];
LL f[N][N];
LL work()
{
	memset(f,0,sizeof f);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (str[i] == '(')
		{
			for (int j = 1; j <= n; j++)
				f[i][j] = f[i-1][j-1];
		}
		else
		{
			f[i][0] = (f[i - 1][0] + f[i - 1][1]) % MOD;
			for (int j = 1; j <= n; j++)
				f[i][j] = (f[i - 1][j + 1] + f[i][j-1]) % MOD; 
		}
	}
	for (int i = 0; i <= n; i++)
		if(f[n][i])
			return f[n][i];
	return -1;
 } 
 int main(){
 	scanf("%s",str+1);
 	n = strlen(str+1);
 	LL l = work();
 	reverse(str + 1,str + n + 1);
 	for (int i = 1; i <= n; i++){
 		if (str[i] == '(') str[i] = ')';
 		else str[i] = '(';
 		
	 }
	 LL r = work();
	 printf("%lld\n", l * r % MOD);
	 return 0;
 }
