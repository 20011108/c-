#include <bits/stdc++.h>
using namespace std;
const int total = 23333333;
const double H = 11625907.5798;
int main(){
	int l = 0,r = total / 2;
	while (l < r) {
		int mid = (l + r) >> 1;
		double ans = 0;
		ans -= 1.0 * mid * mid / total * log2(1.0 * mid / total);
		ans -= 1.0 * (total - mid) * (total - mid) / total * log2(1.0 * (total - mid) / total);
		if (abs(ans - H) < 1e-4){
			cout << mid << endl;
			return 0;
		}	
		if (ans > H){
			r = mid;
		}
		else {
			l =mid + 1;
		}
	
	}
		return 0;
} 
