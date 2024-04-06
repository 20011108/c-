#include <bits/stdc++.h>
using namespace std;
int main(){
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ans[5];
	int index = 0;
	int n = 2019;
	while(n){
		int t = n % 26;
		n = n / 26;
		ans[index] = str[t - 1];
		index++;
		
	}
	for (int i = index - 1; i >= 0; i--){
		cout << ans[i];
	}
	return 0;
}
 
