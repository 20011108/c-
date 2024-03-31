#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
ll v[maxn], l[maxn],r[maxn];
void del(ll x) {
	r[l[x]] = r[x],l[r[x]] = l[x];
	v[l[x]] += v[x],v[r[x]] += v[x];
	
} 
int main(){
	int n,k;
	cin >> n >> k;
	priority_queue<pair<ll, int>, vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		l[i] = i - 1;
		r[i] = i + 1;
		pq.emplace(v[i],i);
		 
	}
	while(k--) {
	auto p = pq.top();
	pq.pop();
	if (p.first != v[p.second]) {
		pq.emplace(v[p.second],p.second);
		k++;
	}else del(p.second);
}
ll head = r[0];
while (head != n + 1) {
	cout << v[head] << " ";
	head = r[head];
}
return 0;
}
   

