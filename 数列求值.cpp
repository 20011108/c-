#include <bits/stdc++.h>
using namespace std;
int f[20190324]; 
int main(){
	f[0] = f[1] = f[2] = 1;
	for (int i = 3; i < 20190324; i++) {
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % 10000;
	}
	cout << f[20190323] << endl;
	return 0;
} 
