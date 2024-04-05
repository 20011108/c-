#include <bits/stdc++.h>
using namespace std;
vector<int> Split(int x) {
	vector<int> ret;
	if (x == 0) {
		ret.push_back(0);
		return ret;
		
	}
	while (x > 0) {
		ret.push_back(x % 10);
		x /= 10;
	}
	return ret;
}
const int maxn = 2021;
int rest_num[10] = {0};
bool Sub(const vector<int> &x) {
	for (unsigned int i = 0; i < x.size(); i++) {
		rest_num[x[i]]--;
		if (rest_num[x[i]] < 0) {
			return false;
		}
	}
	return true;
}
int main(){
	for (int i = 0; i < 10; i++) {
		rest_num[i] = maxn;
	}
	int ans = 1;
	while (1) {
		vector<int> need = Split(ans);
		bool succFlag = Sub(need);
		if (!succFlag) {
			break;
		}
		ans++;
	}
	printf("ans = %d\n",ans-1);
	return 0;
}
 
