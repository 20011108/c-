#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x = max(i,n-i-1);
		cout << x * 2 << endl;
		
	}
	return 0;
 } 
