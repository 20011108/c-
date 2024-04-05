#include <bits/stdc++.h>
using namespace std;
int main() 
{
	long long int dayMs = 24 * 60 * 60 * 1000;
	long long int n;
	scanf("%lld",&n);
	n = n % dayMs;
	n = n / 1000;
	int hour = n/3600;
	int minutes = (n - hour * 3600) / 60;
	int second = n % 60;
	printf("%02d:%02d:%02d\n",hour,minutes,second);
}
 
