#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ansMin = 0,ansMax = 1e9;
	while(n--){
		int a,b;
		cin >> a >> b;
		ansMin = max(a / (b+1) + 1, ansMin);
		ansMax = min(a / b, ansMax);
	}
	cout << ansMin << " " << ansMax << endl;
	return 0;
}
