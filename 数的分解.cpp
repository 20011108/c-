#include <bits/stdc++.h>
using namespace std;
int check(int n){
	while(n){
		int t = n % 10;
		n = n / 10;
		if(t==2||t==4)
			return 0;
	}
	return 1;
}
int main(){
	int ans = 0;
	for(int i = 1; i < 2019; i++) {
		if(check(i))
			for(int j = i + 1; j<2019;j++){
				if(check(j)){
					int k = 2019 - i - j;
					if(k>j && check(k))
						ans++;
				}
			}
	}
	cout << ans << endl;
	return 0;
}
